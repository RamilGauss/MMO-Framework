/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "ProjectConfigUnloader.h"

using namespace nsTornadoEngine;

bool TProjectConfigUnloader::Unload(TProjectConfigContainer* pcc)
{
    if (pcc->mFreeScenePartAggregator) {
        pcc->mFreeScenePartAggregator(pcc->mScenePartAggregator);
    }
    if (pcc->mLoader) {
        pcc->mLoader.reset();
    }

    return true;
}
