/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneDeserializingProcess.h"

#include "Generated files/TornadoEngineJsonSerializer.h"

#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    void TSceneDeserializingProcess::Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);

        ctx->sceneContent.reset(new TSceneResourceContent);

        std::string err;
        auto deserResult = TTornadoEngineJsonSerializer::Deserialize(ctx->sceneContent.get(), ctx->fileContent, err);
    }
    //-------------------------------------------------------------------------------
    uint32_t TSceneDeserializingProcess::GetTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        return 1;
    }
    //-------------------------------------------------------------------------------
}
