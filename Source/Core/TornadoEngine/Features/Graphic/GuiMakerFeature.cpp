/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GuiMakerFeature.h"

using namespace nsGraphicWrapper;

void TGuiMakerFeature::InitConveyor()
{
    Add(&mButtonMakerSystem);
    Add(&mWindowMakerSystem);
    Add(&mDialogMakerSystem);
    
    Add(&mButtonClickHandlerMakerSystem);
    Add(&mDialogCloseEventHandlerMakerSystem);
    Add(&mWindowCloseEventHandlerMakerSystem);
}
