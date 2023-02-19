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

#include "GuiDemo.h"

const int W = 1024;
const int H = 800;

const int CAMERA_COUNT = 6;

using namespace nsGraphicEngine;

TCamera* pCamera[CAMERA_COUNT];

TGuiDemo g_GuiDemo0;
TGuiDemo g_GuiDemo1;

TMesh* CreateCube()
{
    auto pMesh = nsGraphicEngine::TMeshFactory::CreateEmpty();

    pMesh->AddPoint({ -0.5f, -0.5f, -0.5f,  0.0f, 0.0f });
    pMesh->AddPoint({ 0.5f, -0.5f, -0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({ 0.5f,  0.5f, -0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({ 0.5f,  0.5f, -0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({ -0.5f,  0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({ -0.5f, -0.5f, -0.5f,  0.0f, 0.0f });

    pMesh->AddPoint({ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f });
    pMesh->AddPoint({ 0.5f, -0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({ 0.5f,  0.5f,  0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({ 0.5f,  0.5f,  0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({ -0.5f,  0.5f,  0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f });

    pMesh->AddPoint({ -0.5f,  0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({ -0.5f,  0.5f, -0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({ -0.5f, -0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({ -0.5f, -0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f });
    pMesh->AddPoint({ -0.5f,  0.5f,  0.5f,  1.0f, 0.0f });

    pMesh->AddPoint({ 0.5f,  0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({ 0.5f,  0.5f, -0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({ 0.5f, -0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({ 0.5f, -0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({ 0.5f, -0.5f,  0.5f,  0.0f, 0.0f });
    pMesh->AddPoint({ 0.5f,  0.5f,  0.5f,  1.0f, 0.0f });

    pMesh->AddPoint({ -0.5f, -0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({ 0.5f, -0.5f, -0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({ 0.5f, -0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({ 0.5f, -0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f });
    pMesh->AddPoint({ -0.5f, -0.5f, -0.5f,  0.0f, 1.0f });

    pMesh->AddPoint({ -0.5f,  0.5f, -0.5f,  0.0f, 1.0f });
    pMesh->AddPoint({ 0.5f,  0.5f, -0.5f,  1.0f, 1.0f });
    pMesh->AddPoint({ 0.5f,  0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({ 0.5f,  0.5f,  0.5f,  1.0f, 0.0f });
    pMesh->AddPoint({ -0.5f,  0.5f,  0.5f,  0.0f, 0.0f });
    pMesh->AddPoint({ -0.5f,  0.5f, -0.5f,  0.0f, 1.0f });

    return pMesh;
}

void CreateContext0(TGraphicEngine& ge, int offset)
{
    auto pCtx = ge.CreateContext(TGraphicEngine::PipeLineType::SIMPLE);

    pCtx->AddRender(&g_GuiDemo0);

    pCamera[offset + 0] = pCtx->CreateCamera();
    pCamera[offset + 0]->SetPosition({ 0, 0, 0 });
    pCamera[offset + 0]->SetWindowPosition({ 0 , 0 });
    pCamera[offset + 0]->SetWindowSize({ W / 2 , H / 2 });

    pCamera[offset + 1] = pCtx->CreateCamera();
    pCamera[offset + 1]->SetPosition({ 0, 0, 0 });
    pCamera[offset + 1]->SetWindowPosition({ W / 2 , 0 });
    pCamera[offset + 1]->SetWindowSize({ W / 2 , H / 2 });

    pCamera[offset + 2] = pCtx->CreateCamera();
    pCamera[offset + 2]->SetTextureSize({ W, H });
    pCamera[offset + 2]->SetPosition({ 0, 0, 0 });
    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("stone.tga");
        auto pMesh = CreateCube();

        pObject->SetTexture(pTexture);
        pObject->SetMesh(pMesh);

        pObject->SetPosition({ 1, 0, 3 });
        pObject->SetRotation({ 45, 45, 0 });
    }
    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("hole.jpg");
        auto pMesh = CreateCube();

        pObject->SetTexture(pTexture);
        pObject->SetMesh(pMesh);

        pObject->SetPosition({ -1, 0, 3 });
        pObject->SetRotation({ 45, 45, 0 });
    }
    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("wood.png");
        auto pMesh = CreateCube();

        pObject->SetTexture(pTexture);
        pObject->SetMesh(pMesh);

        pObject->SetPosition({ -1, 1, 5 });
        pObject->SetRotation({ 45, 45, 0 });
    }
    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("hole.jpg");
        auto pMesh = CreateCube();

        pObject->SetTexture(pTexture);
        pObject->SetMesh(pMesh);

        pObject->SetPosition({ 1, 1, 5 });
        pObject->SetRotation({ 45, 45, 0 });
    }

    pCtx->SetGuiCamera(pCamera[offset + 0]);
}

void CreateContext1(TGraphicEngine& ge, int offset)
{
    auto pCtx = ge.CreateContext(TGraphicEngine::PipeLineType::SIMPLE);

    pCtx->AddRender(&g_GuiDemo1);

    pCamera[offset + 0] = pCtx->CreateCamera();
    pCamera[offset + 0]->SetPosition({ 0, 0, 0 });
    pCamera[offset + 0]->SetWindowPosition({ 0 , H / 2 });
    pCamera[offset + 0]->SetWindowSize({ W / 2 , H / 2 });

    pCamera[offset + 1] = pCtx->CreateCamera();
    pCamera[offset + 1]->SetPosition({ 0, 0, 0 });
    pCamera[offset + 1]->SetWindowPosition({ W / 2 , H / 2 });
    pCamera[offset + 1]->SetWindowSize({ W / 2 , H / 2 });

    pCamera[offset + 2] = pCtx->CreateCamera();
    pCamera[offset + 2]->SetTextureSize({ W, H });
    pCamera[offset + 2]->SetPosition({ 0, 0, 0 });
    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("stone.tga");
        auto pMesh = CreateCube();

        pObject->SetTexture(pTexture);
        pObject->SetMesh(pMesh);

        pObject->SetPosition({ 1, 0, 3 });
        pObject->SetRotation({ 45, 45, 0 });
    }
    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("wood.png");
        auto pMesh = CreateCube();

        pObject->SetTexture(pTexture);
        pObject->SetMesh(pMesh);

        pObject->SetPosition({ -1, 1, 5 });
        pObject->SetRotation({ 45, 45, 0 });
    }
    {
        auto pObject = pCtx->CreateRenderableObject();
        auto pTexture = TTextureFactory::Load("hole.jpg");
        auto pMesh = CreateCube();

        pObject->SetTexture(pTexture);
        pObject->SetMesh(pMesh);

        pObject->SetPosition({ 1, 1, 5 });
        pObject->SetRotation({ 45, 45, 0 });
    }

    pCtx->SetGuiCamera(pCamera[offset + 1]);
}

int main(int argc, char** argv)
{
    TKeyMouseEventContainer kmc;
    TGraphicEngine ge;

    ge.SetKeyMouseEventContainer(&kmc);

    ge.SetTitle("BigJack");
    ge.SetPosition(100, 100);
    ge.SetSize(W, H);

    auto initResult = ge.Init();
    if (!initResult) {
        return 1;
    }

    CreateContext0(ge, 0);
    CreateContext1(ge, 3);

    g_GuiDemo0.SetTexture(pCamera[5]->GetRenderedTexture());
    g_GuiDemo1.SetTexture(pCamera[2]->GetRenderedTexture());

    int cameraIndex = 0;

    while (true) {
        auto w = ge.GetWidth();
        auto h = ge.GetHeight();

        pCamera[0]->SetWindowPosition({ 0 , 0 });
        pCamera[0]->SetWindowSize({ w / 2 , h / 2 });

        pCamera[1]->SetWindowPosition({ w / 2 , 0 });
        pCamera[1]->SetWindowSize({ w / 2 , h / 2 });

        pCamera[3]->SetWindowPosition({ 0 , h / 2 });
        pCamera[3]->SetWindowSize({ w / 2 , h / 2 });

        pCamera[4]->SetWindowPosition({ w / 2 , h / 2 });
        pCamera[4]->SetWindowSize({ w / 2 , h / 2 });

        auto workResult = ge.GenerateInputEvents();
        if (!workResult) {
            break;
        }

        const float X_MULTI = -0.002f;
        const float Y_MULTI = 0.002f;

        auto pC = pCamera[cameraIndex];

        if (kmc.mouseButtonState[(int)MouseButton::LEFT]) {
            for (auto& mm : kmc.mouseMotionEvents) {
                pC->AddRotation({ mm.yrel * Y_MULTI, mm.xrel * X_MULTI, 0 });
            }
        }

        for (auto& key : kmc.keyEvents) {

            if (key.state != KeyState::DOWN) {
                continue;
            }

            if (key.keyCode == KeyCodes::W) {
                pC->MoveForward(0.05f);
            }
            if (key.keyCode == KeyCodes::S) {
                pC->MoveForward(-0.05f);
            }
            if (key.keyCode == KeyCodes::A) {
                pC->MoveRight(0.05f);
            }
            if (key.keyCode == KeyCodes::D) {
                pC->MoveRight(-0.05f);
            }
            if (key.keyCode == KeyCodes::Q) {
                pC->MoveUp(-0.05f);
            }
            if (key.keyCode == KeyCodes::E) {
                pC->MoveUp(0.05f);
            }

            if (key.keyCode == KeyCodes::T) {
                cameraIndex++;
                cameraIndex %= CAMERA_COUNT;
            }
        }

        g_GuiDemo0.SetCameraIndex(cameraIndex);
        g_GuiDemo1.SetCameraIndex(cameraIndex);

        ge.Draw();
    }

    return 0;
}

