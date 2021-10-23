/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#pragma once

#include "ProjectConfigUnloader.h"
#include "MakerLoaderDLL.h"

using namespace nsTornadoEngine;

bool TProjectConfigUnloader::Unload(TProjectConfigContainer* pcc)
{
    if (pcc->mFreeScenePartContainer) {
        pcc->mFreeScenePartContainer(pcc->mScenePartContainer);
    }
    if (pcc->mLoader) {
        TMakerLoaderDLL maker;
        maker.Delete(pcc->mLoader);
        pcc->mLoader = nullptr;
    }

    return true;
}
