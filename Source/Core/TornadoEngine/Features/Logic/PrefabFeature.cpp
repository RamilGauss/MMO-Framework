/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrefabFeature.h"

using namespace nsLogicWrapper;

void TPrefabFeature::InitConveyor()
{
    Add(&mNeedUnloadPrefabSystem);
    Add(&mNeedDestroyPrefabSystem);
}