/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/End/EndGraphicFeature.h"

using namespace nsGraphicWrapper;

void TEndGraphicFeature::InitConveyor()
{
    Add(&mGuiUpdaterFromModuleFeature);

    Add(&mOnRemoveUniverseContextSystem);

    Add(&mCleanUpUniverseContextSystem);
}
