/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowFrameTest.h"

using namespace nsImGuiWidgets;

namespace nsTest
{
    void TWindowFrameTest::Create(nsGraphicEngine::TGraphicEngineContext* pCtx)
    {
        mWindow.SetTitle("WindowFrameTest");

        mWindow.SetSize({ 200, 200 });
        mWindow.SetPos({ 100, 100 });

        mWindow.SetMinSize({ 10, 10 });
        mWindow.SetMaxSize({ 500, 500 });

        mExitButton.mOnClickCB.Register(nullptr, [](auto) { _exit(0); });
        mExitButton.SetTitle("Exit");
        mExitButton.SetSize({ 70, 30 });
        mExitButton.SetPos({ 30, 50 });

        mFrame.SetLeftMinDistance(4);
        mFrame.SetRightMinDistance(4);
        mFrame.SetTopMinDistance(4);
        mFrame.SetBottomMinDistance(4);

        mFrame.Add(&mExitButton);
        
        mFrame.SetPos({ 30, 30 });
        mFrame.SetSize({110, 90});
        //mFrame.SetLeftAnchor({ true, 10 });
        //mFrame.SetRightAnchor({ true, 10 });
        //mFrame.SetTopAnchor({ true, 10 });
        //mFrame.SetBottomAnchor({ true, 10 });

        mFrame.SetLeftMinDistance(10);
        mFrame.SetRightMinDistance(10);
        mFrame.SetTopMinDistance(10);
        mFrame.SetBottomMinDistance(10);

        mWindow.Add(&mFrame);

        pCtx->AddRender(&mWindow);
    }
    //-----------------------------------------------------------------------------------------------------
    void TWindowFrameTest::Destroy(nsGraphicEngine::TGraphicEngineContext* pCtx)
    {
        pCtx->RemoveRender(&mWindow);
    }
    //-----------------------------------------------------------------------------------------------------
}