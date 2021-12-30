/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GuiTerminatorFeature.h"

using namespace nsGraphicWrapper;

void TGuiTerminatorFeature::InitConveyor()
{
    Add(&mButtonTerminatorSystem);
    Add(&mLabelTerminatorSystem);
    Add(&mMenuNodeTerminatorSystem);
    Add(&mInputTextTerminatorSystem);
    Add(&mWindowTerminatorSystem);
    Add(&mDialogTerminatorSystem);

    Add(&mTreeNodeTerminatorSystem);
    Add(&mTreeViewTerminatorSystem);

    Add(&mMainWindowTerminatorSystem);

    Add(&mButtonClickHandlerTerminatorSystem);
    Add(&mMenuNodeClickHandlerTerminatorSystem);
    Add(&mDialogCloseEventHandlerTerminatorSystem);
    Add(&mWindowCloseEventHandlerTerminatorSystem);
}
