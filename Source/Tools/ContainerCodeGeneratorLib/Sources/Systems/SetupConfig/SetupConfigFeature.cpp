/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SetupConfigFeature.h"

namespace nsContainerCodeGenerator
{
    void TSetupConfigFeature::InitConveyor()
    {
        Add(&mCheckArgumentsSystem);
        Add(&mResolveJsonPathSystem);
        Add(&mTryLoadConfigSystem);
        Add(&mResolvePathesSystem);
    }
}