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

#include "WindowTest.h"
#include "WindowGridTest.h"

const int W = 1024;
const int H = 800;

using namespace nsGraphicEngine;
using namespace nsImGuiWidgets;

TCamera* g_Camera;

nsTest::TWindowGridTest g_WindowTest;

void CreateContext(TGraphicEngine& ge)
{
    auto pCtx = ge.CreateContext(TGraphicEngine::PipeLineType::SIMPLE);

    g_Camera = pCtx->CreateCamera();
    g_Camera->SetPosition({ 0, 0, 0 });
    g_Camera->SetWindowPosition({ 0 , 0 });
    g_Camera->SetWindowSize({ W , H });

    g_WindowTest.Create(pCtx);
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

        g_Camera->SetWindowSize({ ge.GetWidth(), ge.GetHeight() });

        auto workResult = ge.GenerateInputEvents();
        if (!workResult) {
            break;
        }

        ge.Draw();
    }

    return 0;
}

