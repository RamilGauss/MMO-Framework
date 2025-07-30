/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Modules/Resources/Scene/StateGraph/Instantiate/Async/ComponentDeserializingProcess.h"

#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"
#include "TornadoEngine/ReflectionAggregators/ScenePartReflectionAggregator.h"

#include "TornadoEngine/Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    void TComponentDeserializingProcess::Launch(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        ctx->currentEntIt = ctx->sceneContent->entities.begin();
    }
    //-------------------------------------------------------------------------------
    void TComponentDeserializingProcess::Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);

        auto componentReflection = nsTornadoEngine::Project()->mScenePartAggregator->mComponents;
        for (auto& component : ctx->currentEntIt->components) {
            // Add component by rtti
            auto convertResult = componentReflection->mRtti->ConvertNameToType(component.typeName, component.rtti);
            if (convertResult == false) {
                continue;
            }

            component.p = componentReflection->mTypeFactory->New(component.rtti);

            // Deserialize component by rtti and json body
            std::string err;
            componentReflection->mJson->Deserialize(component.p, component.jsonBody, component.rtti, err);
        }

        ctx->currentEntIt++;
    }
    //-------------------------------------------------------------------------------
    uint32_t TComponentDeserializingProcess::GetTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        return ctx->sceneContent->entities.size();
    }
    //-------------------------------------------------------------------------------
}
