/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "UnderMouseWindow.h"

#include "Modules.h"
#include "ModuleGraphicEngine.h"
#include "StopAccessor.h"

using namespace nsTest;

TUnderMouseWindow::TUnderMouseWindow(std::string name)
{
    mWindow.SetTitle(name.c_str());
    mWindow.SetSize({300, 300});
    mWindow.SetPos({20, 20});

    mWindow.mMouseMoveCB.Register([&](nsGraphicEngine::TMouseMotionEvent event)
    {
        ImVec2 mousePos(event.x, event.y);
        auto pNode = mWindow.GetUnderMouseChild(mousePos);
        if (pNode == &mLabel) {
            mToolTip.Show();
        } else {
            mToolTip.Hide();
        }
    });

    mLabel.SetPos({70,70});
    mLabel.SetSize({150, 120});

    mToolTip.SetTitle("UnderLabel");
    mToolTip.Hide();

    mWindow.Add(&mLabel);

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mWindow);
    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mToolTip);
}
//--------------------------------------------------------------------------------------------------------
