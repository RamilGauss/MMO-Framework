/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ImGuiWidgets/include/Window.h"
#include "ImGuiWidgets/include/Button.h"
#include "ImGuiWidgets/include/ComboBox.h"

#include "GraphicEngine/GraphicEngineContext.h"

namespace nsTest
{
    class TWindowTest
    {
        nsImGuiWidgets::TWindow mWindow;

        //nsImGuiWidgets::TButton mExitButton;
        nsImGuiWidgets::TButton mAButton;
        nsImGuiWidgets::TButton mBButton;
        nsImGuiWidgets::TButton mCButton;

        nsImGuiWidgets::TComboBox mCB;

    public:
        void Create(nsGraphicEngine::TGraphicEngineContext* pCtx);
        void Destroy(nsGraphicEngine::TGraphicEngineContext* pCtx);
    };
}