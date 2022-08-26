/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TexturedWindowTest.h"

#include "TextureFactory.h"

namespace nsTest
{
    void TTexturedWindowTest::Create(nsGraphicEngine::TGraphicEngineContext* pCtx, nsGraphicEngine::TCamera* pCamera)
    {
        //auto texture = nsGraphicEngine::TTextureFactory::Load("c:\\Sources\\MMOFramework\\Exe\\hole.jpg");

        auto texture = pCamera->GetRenderedTexture();

        mTFrame.SetTexture(texture->mId);
        mTFrame.SetTextureSize(texture->mWidth, texture->mHeight);

        mWindow.Add(&mTFrame);

        mTFrame.SetLeftAnchor({ true, 0 });
        mTFrame.SetRightAnchor({ true, 0 });
        mTFrame.SetTopAnchor({ true, 0 });
        mTFrame.SetBottomAnchor({ true, 0 });

        mTFrame.Add(&mExitButton);

        mExitButton.SetPos({20, 20});
        mExitButton.SetSize({ 70, 30 });
        mExitButton.SetTitle("Exit");
        mExitButton.mOnClickCB.Register(nullptr, [](auto) { _exit(0); });

        mWindow.SetSize({ 120, 120 });

        pCtx->AddRender(&mWindow);
    }
    //-----------------------------------------------------------------------------------
    void TTexturedWindowTest::Destroy(nsGraphicEngine::TGraphicEngineContext* pCtx)
    {
        pCtx->RemoveRender(&mWindow);
    }
    //-----------------------------------------------------------------------------------
}