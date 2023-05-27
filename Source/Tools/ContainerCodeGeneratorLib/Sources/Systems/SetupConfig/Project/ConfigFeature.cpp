/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ConfigFeature.h"

namespace nsContainerCodeGenerator::nsSetupConfig::nsProject
{
    void TConfigFeature::InitConveyor()
    {
        Add(&mResolveJsonPathSystem);
        Add(&mTryLoadConfigSystem);
        Add(&mResolvePathesSystem);
        
        Add(&mValidateCoreConfigSystem);
        Add(&mValidateProjectConfigSystem);
    }
}
