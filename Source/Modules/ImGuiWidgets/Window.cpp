/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Window.h"
#include "Helper.h"
#include "DockTreeManager.h"


using namespace nsImGuiWidgets;


TDockTreeManager* TWindow::mDockTreeManager = nullptr;

void TWindow::SetDockTreeManager(TDockTreeManager* dockTreeManager)
{
    mDockTreeManager = dockTreeManager;
}
//---------------------------------------------------------------------------------------
TDockTreeManager* TWindow::GetDockTreeManager()
{
    return mDockTreeManager;
}
//---------------------------------------------------------------------------------------
TWindow::TWindow()
{
    if (mDockTreeManager == nullptr) {
        return;
    }
}
//---------------------------------------------------------------------------------------
void TWindow::BeginRender()
{
    mOldSize = mSize;
    mOldPos = mPos;

    auto oldIsShown = mIsShown;

    ImGui::SetNextWindowSize(mSize);
    ImGui::SetNextWindowPos(mPos, ImGuiCond_Appearing);

    ImGui::Begin(mTitle.c_str(), &mIsShown);

    if (oldIsShown != mIsShown) {
        mShowCB.Notify(mIsShown);
    }
}
//---------------------------------------------------------------------------------------
void TWindow::EndRender()
{
    mPos = ImGui::GetWindowPos();
    mSize = ImGui::GetWindowSize();

    ImGui::End();

    if (mOldSize != mSize) {
        mSizeCB.Notify(&mSize);
    } else {
        mSize = mOldSize;
    }

    if (mOldPos != mPos) {
        mPosCB.Notify(&mPos);
    } else {
        mPos = mOldPos;
    }
}
//---------------------------------------------------------------------------------------
