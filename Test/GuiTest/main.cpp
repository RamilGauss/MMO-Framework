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

#include "GraphicEngine/GraphicEngine.h"
#include "GraphicEngine/GraphicEngineContext.h"

#include "GraphicEngine/TextureFactory.h"
#include "GraphicEngine/ShaderFactory.h"
#include "GraphicEngine/MeshFactory.h"

#include "WindowTest.h"
#include "WindowGridTest.h"

#include "WindowAndFrameTest.h"
#include "WindowGridedFrameTest.h"
#include "WindowFrameTest.h"
#include "TreeNodeTest.h"

#include "TexturedWindowTest.h"

const int W = 1024;
const int H = 800;

const float WIN_WIDTH = 0.5f;
const float WIN_HEIGHT = 0.5f;

using namespace nsGraphicEngine;
using namespace nsImGuiWidgets;

TCamera* g_Camera;

nsTest::TWindowTest g_WindowTest;
nsTest::TWindowGridTest g_WindowGridTest;
nsTest::TWindowAndFrameTest g_WindowAndFrameTest;
nsTest::TWindowGridedFrameTest g_WindowGridedFrameTest;
nsTest::TWindowFrameTest g_WindowFrameTest;

nsTest::TTreeNodeTest g_TreeNodeTest;

nsTest::TTexturedWindowTest g_TexturedWindowTest;

void CreateContext(TGraphicEngine& ge)
{
    auto pCtx = ge.CreateContext(TGraphicEngine::PipeLineType::SIMPLE);

    g_Camera = pCtx->CreateCamera();
    g_Camera->SetPosition({ 0, 0, 0 });
    g_Camera->SetWindowPosition({ W * 0.0f , H * 0.0f });// { 0, 0 });
    g_Camera->SetWindowSize({W * WIN_WIDTH, H * WIN_HEIGHT});// { W, H });

    g_WindowTest.Create(pCtx);
    //g_WindowGridTest.Create(pCtx);
    //g_WindowAndFrameTest.Create(pCtx);
    //g_WindowGridedFrameTest.Create(pCtx);
    //g_WindowFrameTest.Create(pCtx);

    //g_TreeNodeTest.Create(pCtx);

    //g_TexturedWindowTest.Create(pCtx, g_Camera);

    pCtx->SetGuiCamera(g_Camera);
}

int main(int argc, char** argv)
{
    TKeyMouseEventContainer kmc;
    TGraphicEngine ge;

    ge.SetKeyMouseEventContainer(&kmc);

    ge.SetTitle("Gui test");
    ge.SetPosition(100, 100);
    ge.SetSize(W, H);

    TWidget::SetInputContainer(&kmc);

    auto initResult = ge.Init();
    if (!initResult) {
        return 1;
    }

    CreateContext(ge);

    while (true) {

        g_Camera->SetWindowSize({ ge.GetWidth() * WIN_WIDTH, ge.GetHeight() * WIN_HEIGHT });


        // Atomic operation
        // --->
        ge.SetupViewports();

        auto workResult = ge.GenerateInputEvents();
        if (!workResult) {
            break;
        }

        ge.Draw();
        // end atomic operation
    }

    return 0;
}

