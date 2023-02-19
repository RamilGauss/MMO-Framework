/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowAndFrameTest.h"

using namespace nsImGuiWidgets;

namespace nsTest
{
    void TWindowAndFrameTest::Create(nsGraphicEngine::TGraphicEngineContext* pCtx)
    {
        mWindow.SetTitle("WindowAndFrameTest");

        mWindow.SetSize({ 250, 250 });
        mWindow.SetPosition({ 100, 100 });

        mWindow.SetMinSize({ 10, 10 });
        mWindow.SetMaxSize({ 500, 500 });

        mExitButton.mOnClickCB.Register(nullptr, [](auto) { _exit(0); });
        mExitButton.SetTitle("Exit");
        mAButton.SetTitle("A");
        mBButton.SetTitle("B");
        mCButton.SetTitle("C");

        mExitButton.SetLeftAnchor({ true, 30 });
        mExitButton.SetRightAnchor({ true, 100 });
        mExitButton.SetTopAnchor({ true, 50 });
        mExitButton.SetBottomAnchor({ true, 120 });
        mExitButton.SetMinSize({ 65, 25 });
        mExitButton.SetMaxSize({ 200, 200 });
        mExitButton.SetSize({ 70, 30 });
        mExitButton.SetPosition({ 30, 50 });

        mExitButton.SetVerticalAlign(TVerticalAlign::Type::BOTTOM);
        mExitButton.SetHorizontalAlign(THorizontalAlign::Type::LEFT);

        mAButton.SetRightAnchor({ true, 100 });
        mAButton.SetBottomAnchor({ true, 80 });
        mAButton.SetMinSize({ 65, 25 });
        mAButton.SetMaxSize({ 200, 200 });
        mAButton.SetSize({ 70, 30 });
        mAButton.SetPosition({ 30, 90 });

        mBButton.SetBottomAnchor({ true, 120 });
        mBButton.SetMinSize({ 65, 25 });
        mBButton.SetMaxSize({ 200, 200 });
        mBButton.SetSize({ 70, 30 });
        mBButton.SetPosition({ 110, 50 });

        mCButton.SetMinSize({ 65, 25 });
        mCButton.SetMaxSize({ 100, 45 });
        mCButton.SetSize({ 70, 30 });
        mCButton.SetPosition({ 110, 90 });

        mFrame.SetSize({200, 200});
        mFrame.SetPosition({ 30, 30 });

        mFrame.Add(&mExitButton);
        mFrame.Add(&mAButton);
        mFrame.Add(&mBButton);
        mFrame.Add(&mCButton);

        mFrame.SetLeftMinDistance(10);
        mFrame.SetRightMinDistance(10);
        mFrame.SetTopMinDistance(20);
        mFrame.SetBottomMinDistance(10);

        mWindow.Add(&mFrame);

        pCtx->AddRender(&mWindow);
    }
    //-----------------------------------------------------------------------------------------------------
    void TWindowAndFrameTest::Destroy(nsGraphicEngine::TGraphicEngineContext* pCtx)
    {
        pCtx->RemoveRender(&mWindow);
    }
    //-----------------------------------------------------------------------------------------------------
}