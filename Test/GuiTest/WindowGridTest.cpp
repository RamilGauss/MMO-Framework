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
        mWindow.SetTitle("Layout window");

        mWindow.SetSize({ 200, 200 });
        mWindow.SetPos({ 100, 100 });

        mWindow.SetMinSize({ 10, 10 });
        mWindow.SetMaxSize({ 500, 500 });

        mExitButton.mOnClickCB.Register(nullptr, [](auto) { _exit(0); });
        mExitButton.SetTitle("Exit");
        mAButton.SetTitle("A");
        mBButton.SetTitle("B");
        mCButton.SetTitle("C");

        mExitButton.SetLeft({ true, 30 });
        mExitButton.SetRight({ true, 100 });
        mExitButton.SetTop({ true, 50 });
        mExitButton.SetBottom({ true, 120 });
        mExitButton.SetMinSize({ 65, 25 });
        mExitButton.SetMaxSize({ 200, 200 });
        mExitButton.SetSize({ 70, 30 });
        mExitButton.SetPos({ 30, 50 });

        mExitButton.SetVerticalAlign(TVerticalAlign::Type::BOTTOM);
        mExitButton.SetHorizontalAlign(THorizontalAlign::Type::RIGHT);

        mAButton.SetRight({ true, 100 });
        mAButton.SetBottom({ true, 80 });
        mAButton.SetMinSize({ 65, 25 });
        mAButton.SetMaxSize({ 200, 200 });
        mAButton.SetSize({ 70, 30 });
        mAButton.SetPos({ 30, 90 });

        mBButton.SetBottom({ true, 120 });
        mBButton.SetMinSize({ 65, 25 });
        mBButton.SetMaxSize({ 200, 200 });
        mBButton.SetSize({ 70, 30 });
        mBButton.SetPos({ 110, 50 });

        mCButton.SetMinSize({ 65, 25 });
        mCButton.SetMaxSize({ 1000, 1000 });
        mCButton.SetSize({ 70, 30 });
        mCButton.SetPos({ 110, 90 });

        mWindow.Add(&mExitButton);
        mWindow.Add(&mAButton);
        mWindow.Add(&mBButton);
        mWindow.Add(&mCButton);

        mWindow.SetUseGrid(true);

        mWindow.BeginAddingInGrid();

        mWindow.AddCellInGrid({ &mExitButton, {0,0}, {1,1} });
        mWindow.AddCellInGrid({ &mAButton, {0,1}, {1,1} });
        mWindow.AddCellInGrid({ &mBButton, {1,0}, {1,1} });
        mWindow.AddCellInGrid({ &mCButton, {1,1}, {1,1} });

        mWindow.EndAddingInGrid();

        mWindow.SetTopPadding(1);
        mWindow.SetRightPadding(1);
        mWindow.SetLeftPadding(1);
        mWindow.SetBottomPadding(1);

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