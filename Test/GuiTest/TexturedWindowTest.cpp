/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TexturedWindowTest.h"

#include "GraphicEngine/TextureFactory.h"

namespace nsTest
{
    void TTexturedWindowTest::Create(nsGraphicEngine::TGraphicEngineContext* pCtx, nsGraphicEngine::TCamera* pCamera)
    {
        auto texture = nsGraphicEngine::TTextureFactory::Load("c:\\Data\\Github\\MMOFramework\\Exe\\hole.jpg");

        //auto texture = pCamera->GetRenderedTexture();

        mTFrame.SetTextureId((void*)texture->mId);
        mTFrame.SetTextureSize(texture->mWidth, texture->mHeight);

        mTFrame.SetTextureMinUv({ 1, 0 });
        mTFrame.SetTextureMaxUv({ 0, 1 });

        mWindow.SetTitle("TexturedWindowTest");
        mWindow.Add(&mTFrame);

        mTFrame.SetLeftAnchor({ true, 0 });
        mTFrame.SetRightAnchor({ true, 0 });
        mTFrame.SetTopAnchor({ true, 0 });
        mTFrame.SetBottomAnchor({ true, 0 });

        mTFrame.Add(&mExitButton);

        mExitButton.SetPosition({ 20, 20 });
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