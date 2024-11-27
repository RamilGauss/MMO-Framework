/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneFileOpeningProcess.h"

#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    void TSceneFileOpeningProcess::Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        ctx->file.ReOpen((char*)ctx->sceneAbsPath.c_str());

        auto size = ctx->file.Size();

        ctx->fileProgress.SetTotal(size);
        ctx->fileContent.reserve(size);
    }
    //-------------------------------------------------------------------------------
    uint32_t TSceneFileOpeningProcess::GetSubProcessTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        return 1;
    }
    //-------------------------------------------------------------------------------
}
