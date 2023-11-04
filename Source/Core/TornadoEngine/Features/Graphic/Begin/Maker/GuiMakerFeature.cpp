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
    Add(&mLabelMakerSystem);
    Add(&mMenuNodeMakerSystem);
    Add(&mInputTextMakerSystem);
    Add(&mWindowMakerSystem);
    Add(&mDialogMakerSystem);

    Add(&mTreeNodeMakerSystem);
    Add(&mTreeViewMakerSystem);

    Add(&mMainWindowMakerSystem);
    
    Add(&mTextureMakerSystem);

    Add(&mCameraMakerSystem);
}
