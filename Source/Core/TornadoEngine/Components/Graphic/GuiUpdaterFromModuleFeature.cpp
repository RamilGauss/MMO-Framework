/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GuiUpdaterFromModuleFeature.h"

using namespace nsGraphicWrapper;

void TGuiUpdaterFromModuleFeature::InitConveyor()
{
    Add(&mWindowPositionUpdaterSystem);
    Add(&mWindowSizeUpdaterSystem);

    Add(&mDialogPositionUpdaterSystem);
    Add(&mDialogSizeUpdaterSystem);
}
