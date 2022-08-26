/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowGridedFrameTest.h"

using namespace nsImGuiWidgets;

namespace nsTest
{
    void TWindowGridedFrameTest::Create(nsGraphicEngine::TGraphicEngineContext* pCtx)
    {
        mWindow.SetTitle("WindowGridedFrameTest");

        mWindow.SetSize({ 250, 250 });
        mWindow.SetPos({ 100, 100 });

        mWindow.SetMinSize({ 10, 10 });
        mWindow.SetMaxSize({ 500, 500 });

        mExitButton.mOnClickCB.Register(nullptr, [](auto) { _exit(0); });
        mExitButton.SetTitle("Exit");
        mAButton.SetTitle("A");
        mBButton.SetTitle("B");
        mCButton.SetTitle("C");
        mDButton.SetTitle("D");
        mEButton.SetTitle("E");

        mExitButton.SetLeftAnchor({ true, 10 });
        mExitButton.SetRightAnchor({ true, 10 });
        mExitButton.SetTopAnchor({ true, 10 });
        mExitButton.SetBottomAnchor({ true, 10 });
        mExitButton.SetMinSize({ 65, 25 });
        mExitButton.SetMaxSize({ 100, 100 });

        mExitButton.SetVerticalAlign(TVerticalAlign::Type::BOTTOM);
        mExitButton.SetHorizontalAlign(THorizontalAlign::Type::LEFT);

        mAButton.SetRightAnchor({ true, 10 });
        mAButton.SetBottomAnchor({ true, 10 });
        mAButton.SetMinSize({ 65, 25 });
        mAButton.SetMaxSize({ 100, 100 });

        mBButton.SetBottomAnchor({ true, 10 });
        mBButton.SetMinSize({ 65, 25 });
        mBButton.SetMaxSize({ 100, 100 });

        mCButton.SetMinSize({ 65, 25 });
        mCButton.SetMaxSize({ 100, 100 });


        mDButton.SetMinSize({ 65, 25 });
        mDButton.SetMaxSize({ 100, 100 });

        mEButton.SetMinSize({ 65, 25 });
        mEButton.SetMaxSize({ 100, 100 });

        mFrame.SetUseGrid(true);
        mWindow.SetUseGrid(true);

        mFrame.SetSpacing(3);
        mFrame.SetLeftPadding(3);
        mFrame.SetRightPadding(3);
        mFrame.SetTopPadding(3);
        mFrame.SetBottomPadding(3);

        mFrame.Add(&mExitButton);
        mFrame.Add(&mAButton);
        mFrame.Add(&mBButton);
        mFrame.Add(&mCButton);

        mFrame.AddCellInGrid({ &mExitButton, {0,0}, {1,1} });
        mFrame.AddCellInGrid({ &mAButton,    {0,1}, {1,1} });
        mFrame.AddCellInGrid({ &mBButton,    {1,0}, {1,1} });
        mFrame.AddCellInGrid({ &mCButton,    {1,1}, {1,1} });

        mWindow.SetSpacing(3);
        mWindow.SetLeftPadding(0);
        mWindow.SetRightPadding(0);
        mWindow.SetTopPadding(0);
        mWindow.SetBottomPadding(0);

        mWindow.AddCellInGrid({ &mDButton, {0,0}, {1,1} });
        mWindow.AddCellInGrid({ &mEButton, {1,0}, {1,1} });
        mWindow.AddCellInGrid({ &mFrame,   {0,1}, {2,2} });

        mWindow.Add(&mDButton);
        mWindow.Add(&mEButton);
        mWindow.Add(&mFrame);

        pCtx->AddRender(&mWindow);
    }
    //-----------------------------------------------------------------------------------------------------
    void TWindowGridedFrameTest::Destroy(nsGraphicEngine::TGraphicEngineContext* pCtx)
    {
        pCtx->RemoveRender(&mWindow);
    }
    //-----------------------------------------------------------------------------------------------------
}