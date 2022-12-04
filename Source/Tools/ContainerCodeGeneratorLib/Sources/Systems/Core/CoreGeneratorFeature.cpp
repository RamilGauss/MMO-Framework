/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CoreGeneratorFeature.h"

namespace nsContainerCodeGenerator
{
    void TCoreGeneratorFeature::InitConveyor()
    {
        Add(&mCoreComponentGeneratorFeature);
        Add(&mCoreHandlerGeneratorFeature);
        Add(&mCoreEcsSystemGeneratorFeature);
        Add(&mCoreSystemGeneratorFeature);
    }
}