/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#include <SDL_main.h>

#include "GraphicEngine.h"
#include "GraphicEngineContext.h"

#include "TextureFactory.h"
#include "ShaderFactory.h"
#include "MeshFactory.h"

#include "Window.h"
#include "Button.h"

const int W = 1024;
const int H = 800;

using namespace nsGraphicEngine;
using namespace nsImGuiWidgets;

TCamera* g_Camera;

TWindow g_Window;

TButton g_ExitButton;
TButton g_AButton;
TButton g_BButton;
TButton g_CButton;

void CreateContext(TGraphicEngine& ge)
{
    auto pCtx = ge.CreateContext(TGraphicEngine::PipeLineType::SIMPLE);

    pCtx->AddRender(&g_Window);

    g_Window.SetTitle("Layout window");

    g_Window.SetSize({ 200, 200 });
    g_Window.SetPos({ 100, 100 });

    g_ExitButton.mOnClickCB.Register(nullptr, [](TButton* pBtn) { _exit(0); });

    g_ExitButton.SetTitle("Exit");
    g_AButton.SetTitle("A");
    g_BButton.SetTitle("B");
    g_CButton.SetTitle("C");

    g_ExitButton.SetSize({70, 30});
    g_AButton.SetSize({ 70, 30 });
    g_BButton.SetSize({70, 30});
    g_CButton.SetSize({70, 30});

    g_ExitButton.SetPos({ 30, 50 });
    g_AButton.SetPos({ 30, 90 });
    g_BButton.SetPos({ 110, 50 });
    g_CButton.SetPos({ 110, 90 });

    g_Window.Add(&g_ExitButton);
    g_Window.Add(&g_AButton);
    g_Window.Add(&g_BButton);
    g_Window.Add(&g_CButton);

    g_Camera = pCtx->CreateCamera();
    g_Camera->SetPosition({ 0, 0, 0 });
    g_Camera->SetWindowPosition({ 0 , 0 });
    g_Camera->SetWindowSize({ W , H });

    pCtx->SetGuiCamera(g_Camera);
}

int main(int argc, char** argv)
{
    TKeyMouseEventContainer kmc;
    TGraphicEngine ge;

    ge.SetKeyMouseEventContainer(&kmc);

    ge.SetTitle("BigJack");
    ge.SetPosition(100, 100);
    ge.SetSize(W, H);

    TWidget::SetInputContainer(&kmc);

    auto initResult = ge.Init();
    if (!initResult) {
        return 1;
    }

    CreateContext(ge);

    while (true) {

        auto workResult = ge.GenerateInputEvents();
        if (!workResult) {
            break;
        }

        ge.Draw();
    }

    return 0;
}

