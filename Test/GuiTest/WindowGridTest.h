#pragma once

#include "ImGuiWidgets/include/Window.h"
#include "ImGuiWidgets/include/Button.h"

#include "GraphicEngine/GraphicEngineContext.h"

namespace nsTest
{
    class TWindowGridTest
    {
        nsImGuiWidgets::TWindow mWindow;

        nsImGuiWidgets::TButton mExitButton;
        nsImGuiWidgets::TButton mAButton;
        nsImGuiWidgets::TButton mBButton;
        nsImGuiWidgets::TButton mCButton;

    public:
        void Create(nsGraphicEngine::TGraphicEngineContext* pCtx);
        void Destroy(nsGraphicEngine::TGraphicEngineContext* pCtx);
    };
}