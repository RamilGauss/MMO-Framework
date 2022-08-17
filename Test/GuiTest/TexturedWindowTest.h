/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Window.h"
#include "TexturedFrame.h"
#include "Button.h"

#include "GraphicEngineContext.h"

namespace nsTest
{
    class TTexturedWindowTest
    {
        nsImGuiWidgets::TWindow mWindow;

        nsImGuiWidgets::TTexturedFrame mTFrame;

        nsImGuiWidgets::TButton mExitButton;

    public:
        void Create(nsGraphicEngine::TGraphicEngineContext* pCtx, nsGraphicEngine::TCamera* pCamera);
        void Destroy(nsGraphicEngine::TGraphicEngineContext* pCtx);
    };
}