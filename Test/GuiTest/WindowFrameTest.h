/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Window.h"
#include "Frame.h"
#include "Button.h"

#include "GraphicEngineContext.h"

namespace nsTest
{
    class TWindowFrameTest
    {
        nsImGuiWidgets::TWindow mWindow;

        nsImGuiWidgets::TFrame mFrame;
        nsImGuiWidgets::TButton mExitButton;

    public:
        void Create(nsGraphicEngine::TGraphicEngineContext* pCtx);
        void Destroy(nsGraphicEngine::TGraphicEngineContext* pCtx);
    };
}