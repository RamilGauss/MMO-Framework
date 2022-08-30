/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowGridTest.h"

using namespace nsImGuiWidgets;

namespace nsTest
{
    void TWindowGridTest::Create(nsGraphicEngine::TGraphicEngineContext* pCtx)
    {
        mWindow.SetTitle("WindowGridTest");

        mWindow.SetSize({ 200, 200 });
        mWindow.SetPos({ 100, 100 });

        mWindow.SetMinSize({ 10, 10 });
        mWindow.SetMaxSize({ 700, 700 });

        mExitButton.mOnClickCB.Register(nullptr, [](auto) { _exit(0); });
        mExitButton.SetTitle("Exit");
        mAButton.SetTitle("A");
        mBButton.SetTitle("B");
        mCButton.SetTitle("C");

        mExitButton.SetMinSize({ 60, 60 });
        mExitButton.SetMaxSize({ 100, 100 });

        mAButton.SetMinSize({ 60, 60 });
        mAButton.SetMaxSize({ 100, 100 });

        mBButton.SetMinSize({ 60, 60 });
        mBButton.SetMaxSize({ 100, 100 });

        mCButton.SetMinSize({ 60, 60 });
        mCButton.SetMaxSize({ 100, 100 });

        mWindow.Add(&mExitButton);
        mWindow.Add(&mAButton);
        mWindow.Add(&mBButton);
        mWindow.Add(&mCButton);

        mWindow.SetUseGrid(true);

        mWindow.AddCellInGrid({ &mExitButton, {0,0}, {1,1} });
        mWindow.AddCellInGrid({ &mAButton,    {0,1}, {1,1} });
        mWindow.AddCellInGrid({ &mBButton,    {1,0}, {1,1} });
        mWindow.AddCellInGrid({ &mCButton,    {1,1}, {1,1} });

        mWindow.SetTopPadding(20);
        mWindow.SetRightPadding(9);
        mWindow.SetLeftPadding(6);
        mWindow.SetBottomPadding(9);

        mWindow.SetSpacing(1);

        pCtx->AddRender(&mWindow);
    }
    //-----------------------------------------------------------------------------------------------------
    void TWindowGridTest::Destroy(nsGraphicEngine::TGraphicEngineContext* pCtx)
    {
        pCtx->RemoveRender(&mWindow);
    }
    //-----------------------------------------------------------------------------------------------------
}