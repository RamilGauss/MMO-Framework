/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/Builder/GuiBuilderFeature.h"

using namespace nsGraphicWrapper;

void TGuiBuilderFeature::InitConveyor()
{
    Add(&mButtonBuilderSystem);
    Add(&mLabelBuilderSystem);
    Add(&mMenuNodeBuilderSystem);
    Add(&mInputTextBuilderSystem);
    Add(&mWindowBuilderSystem);
    Add(&mDialogBuilderSystem);

    Add(&mAddPropertiesFeature);

    Add(&mTreeNodeBuilderSystem);
    Add(&mTreeViewBuilderSystem);

    Add(&mMainWindowBuilderSystem);
    Add(&mCameraBuilderFeature);
}
