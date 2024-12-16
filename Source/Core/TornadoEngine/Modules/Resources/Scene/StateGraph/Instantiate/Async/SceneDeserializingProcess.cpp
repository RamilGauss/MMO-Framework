/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneDeserializingProcess.h"

//#include "Generated files/TornadoEngineJsonSerializer.h"

#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    void TSceneDeserializingProcess::Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);

        //std::string err;
        //auto deserResult = TTornadoEngineJsonSerializer::Deserialize(&ctx->sceneContent, ctx->fileContent, err);


        for (auto& entity : ctx->sceneContent.entities) {
            for (auto& component : entity.components) {
                if (component.typeName == "") {
                    //ctx->entityGuids.push_back();
                }
            }
        }
    }
    //-------------------------------------------------------------------------------
    uint32_t TSceneDeserializingProcess::GetTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        return 1;
    }
    //-------------------------------------------------------------------------------
}
