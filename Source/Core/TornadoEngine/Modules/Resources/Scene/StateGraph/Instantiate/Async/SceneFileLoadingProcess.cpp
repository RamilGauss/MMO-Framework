/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneFileLoadingProcess.h"

#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    void TSceneFileLoadingProcess::Launch(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        ctx->file.ReOpen((char*)ctx->sceneAbsPath.c_str());
    }
    //-------------------------------------------------------------------------------
    void TSceneFileLoadingProcess::Work(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);

        unsigned int offset = ctx->fileContent.size();
        auto fileSize = ctx->file.Size();
        int remainSize = fileSize - offset;
        unsigned int partSize = std::min(remainSize, FILE_PART_SIZE);

        ctx->file.Read(ctx->fileBuffer.GetPtr(), partSize, offset);

        ctx->fileContent.append(ctx->fileBuffer.GetPtr(), partSize);
    }
    //-------------------------------------------------------------------------------
    uint32_t TSceneFileLoadingProcess::GetTotalPartCount(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        auto size = ctx->file.Size();
        auto partCount = size / FILE_PART_SIZE;
        if (partCount == 0) {
            partCount = 1;
        }
        return partCount;
    }
    //-------------------------------------------------------------------------------
    void TSceneFileLoadingProcess::Finalize(nsBase::nsZones::SharedPtrHopProcessContext pCtx)
    {
        auto ctx = std::static_pointer_cast<TSceneContext>(pCtx);
        ctx->file.Close();
    }
    //-------------------------------------------------------------------------------
}
