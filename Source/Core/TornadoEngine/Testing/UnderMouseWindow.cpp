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

#include <fmt/core.h>
#include <ImGuiWidgets/Helper.h>

using namespace nsTest;
using namespace nsImGuiWidgets;

TUnderMouseWindow::TUnderMouseWindow(std::string name)
{
    mWindow.SetTitle(name.c_str());
    mWindow.SetSize({300, 300});
    mWindow.SetPos({20, 20});

    mWindow.mOnPosCB.Register(this, [&](const ImVec2* newPos)
    {
        auto labelPos = *newPos + mLabel.GetPos();
        mLabel.SetText(fmt::format("{} {}", labelPos.x, labelPos.y).c_str());
    });

    mWindow.mOnMouseMoveCB.Register(this, [&](nsGraphicEngine::TMouseMotionEvent event)
    {
        ImVec2 mousePos(event.x, event.y);
        auto p = mWindow.GetChildByGlobalPos(mousePos);
        if (p == &mLabel) {
            mToolTip.Show();
            mToolTip.SetTitle(fmt::format("Label:{}, {}", event.x, event.y));
        } else if (p == &mTreeView) {
            mToolTip.Show();
            mToolTip.SetTitle(fmt::format("TreeView:{}, {}", event.x, event.y));
        } else if (p == &mButton) {
            mToolTip.Show();
            mToolTip.SetTitle(fmt::format("Button:{}, {}", event.x, event.y));
        } else {
            mToolTip.Hide();
        }
    });

    
    mButton.SetTitle("Exit");
    mButton.SetPos({10,20});
    mButton.SetSize({50, 20});
    mButton.mOnClickCB.Register(this, [&](nsImGuiWidgets::TButton* p)
    {
        nsTornadoEngine::Modules()->StopAccessor()->SetStop();
    });

    mLabel.SetPos({10,50});
    mLabel.SetSize({100, 100});

    mTreeView.SetPos({20,160});
    mTreeView.SetSize({100, 100});

    mToolTip.Hide();

    mWindow.Add(&mLabel);
    mWindow.Add(&mTreeView);
    mWindow.Add(&mButton);

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mWindow);
    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mToolTip);
}
//--------------------------------------------------------------------------------------------------------
