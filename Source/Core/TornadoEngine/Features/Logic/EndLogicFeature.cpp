/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "EndLogicFeature.h"

using namespace nsLogicWrapper;

void TEndLogicFeature::SetEntMng(nsECSFramework::TEntityManager* entMng)
{
    TFeature::SetEntMng(entMng);
    Add(&mStartedScenesInitSystem);
    Add(&mNeedUnloadSceneSystem);
}