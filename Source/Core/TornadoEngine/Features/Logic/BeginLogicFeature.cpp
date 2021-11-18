/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BeginLogicFeature.h"

using namespace nsLogicWrapper;

void TBeginLogicFeature::SetEntMng(nsECSFramework::TEntityManager* entMng)
{
    Add(&mStartedScenesInitSystem);
}