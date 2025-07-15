/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine/GraphicEngineContext.h"
#include "GraphicEngine/ShaderFactory.h"
#include "GraphicEngine/ShaderPrefabs.h"

#include "GraphicEngine/TextureFactory.h"
#include "GraphicEngine/Texture.h"

using namespace nsGraphicEngine;

TGraphicEngineContext::TGraphicEngineContext()
{

}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::Init(TGraphicEngine* pGE)
{
    mGE = pGE;

    mRenderableObjectShader = CreateRenderableObjectShader();

    mImGuiContext.Init(pGE->GetSdlWindow(), pGE->GetSdlCtx());


    mCamerasRenderOnDisplayShader = CreateCamerasRenderOnDisplayShader();
    mCamerasRenderOnDisplayObject = new TRenderableObject();

    mCamerasRenderOnDisplayObjectMesh.AddPoint({ -1, -1, 0, 0, 0 });
    mCamerasRenderOnDisplayObjectMesh.AddPoint({  1, -1, 0, 1, 0 });
    mCamerasRenderOnDisplayObjectMesh.AddPoint({ -1,  1, 0, 0, 1 });

    mCamerasRenderOnDisplayObjectMesh.AddPoint({ -1,  1, 0, 0, 1 });
    mCamerasRenderOnDisplayObjectMesh.AddPoint({  1, -1, 0, 1, 0 });
    mCamerasRenderOnDisplayObjectMesh.AddPoint({  1,  1, 0, 1, 1 });

    mCamerasRenderOnDisplayObject->SetMesh(&mCamerasRenderOnDisplayObjectMesh);
}
//--------------------------------------------------------------------------------------------
TGraphicEngineContext::~TGraphicEngineContext()
{
    delete mCamerasRenderOnDisplayObject;
}
//--------------------------------------------------------------------------------------------
TShader* TGraphicEngineContext::CreateCamerasRenderOnDisplayShader()
{
    auto vertexShaderText = TShaderPrefabs::GetRenderTextureOnDisplayVertex();
    auto fragmentShaderText = TShaderPrefabs::GetRenderTextureOnDisplayFragment();

    std::list<nsGraphicEngine::TShaderFactory::TParams> params;

    params.push_back({ GL_VERTEX_SHADER, vertexShaderText });
    params.push_back({ GL_FRAGMENT_SHADER, fragmentShaderText });

    return nsGraphicEngine::TShaderFactory::Create(params);
}
//--------------------------------------------------------------------------------------------
TShader* TGraphicEngineContext::CreateRenderableObjectShader()
{
    auto vertexShaderText = TShaderPrefabs::GetRenderObjectVertex();
    auto fragmentShaderText = TShaderPrefabs::GetRenderObjectFragment();

    std::list<nsGraphicEngine::TShaderFactory::TParams> params;

    params.push_back({ GL_VERTEX_SHADER, vertexShaderText });
    params.push_back({ GL_FRAGMENT_SHADER, fragmentShaderText });

    return nsGraphicEngine::TShaderFactory::Create(params);
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::Render()
{
    auto windowHeight = mGE->GetHeight();
    auto windowWidth = mGE->GetWidth();

    glViewport(0, 0, windowWidth, windowHeight);
    // Draw all renderable objects
    mRenderableObjectShader->MakeCurrentInConveyer();
    mRenderableObjectShader->SetInt("texture1", 0);

    // Accumulate all camera textures.
    for (auto& camera : mCameras) {

        camera->Begin();

        glm::mat4 view = camera->GetViewMatrix();
        glm::mat4 projection = camera->GetProjectionMatrix();
        mRenderableObjectShader->SetMat4("view", view);
        mRenderableObjectShader->SetMat4("projection", projection);

        for (auto& renderableObject : mRenderableObjects) {
            auto model = renderableObject->GetMatrix();
            mRenderableObjectShader->SetMat4("model", model);

            renderableObject->Draw();
        }

        // Draw Gui
        if (camera == mGuiCamera) {
            mImGuiContext.Render();
        }

        camera->End();
    }

    // Render camera textures to the window.
    for (auto& camera : mCameras) {
        if (camera->IsRenderOnDisplay()) {
            mCamerasRenderOnDisplayShader->MakeCurrentInConveyer();
            mCamerasRenderOnDisplayShader->SetInt("texture1", 0);

            auto winSize = camera->GetWindowSize();
            auto winPos = camera->GetWindowPosition();

            float xPos = 2.0f * (2.0f * winPos.x + winSize.x) / windowWidth - 2.0f;
            float yPos = 2.0f * (2.0f * winPos.y + winSize.y) / windowHeight - 2.0f;

            float xSize = (2.0f * winSize.x) / windowWidth;
            float ySize = (2.0f * winSize.y) / windowHeight;

            mCamerasRenderOnDisplayShader->SetFloat2("pos", xPos, yPos);
            mCamerasRenderOnDisplayShader->SetFloat2("size", xSize, ySize);

            auto pTexture = camera->GetRenderedTexture();
            mCamerasRenderOnDisplayObject->SetTexture(pTexture);

            mCamerasRenderOnDisplayObject->Draw();
        }
    }
}
//--------------------------------------------------------------------------------------------
TCamera* TGraphicEngineContext::CreateCamera()
{
    auto pCamera = new TCamera();
    mCameras.push_back(pCamera);
    return pCamera;
}
//--------------------------------------------------------------------------------------------
TRenderableObject* TGraphicEngineContext::CreateRenderableObject()
{
    auto pObject = new TRenderableObject();
    mRenderableObjects.push_back(pObject);
    return pObject;
}
//--------------------------------------------------------------------------------------------
TLight* TGraphicEngineContext::CreateLight()
{
    return nullptr;
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::DestroyCamera(TCamera* pCamera)
{
    mCameras.remove(pCamera);
    delete pCamera;
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::DestroyRenderableObject(TRenderableObject* pRenderableObject)
{
    mRenderableObjects.remove(pRenderableObject);
    delete pRenderableObject;
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::DestroyLight(TLight* pLight)
{

}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::SetupGuiViewport()
{
    if (mGuiCamera) {
        auto winPos = mGuiCamera->GetWindowPosition();
        auto winSize = mGuiCamera->GetWindowSize();
        auto windowHeight = mGE->GetHeight();
        auto windowWidth = mGE->GetWidth();
        mImGuiContext.SetupGuiViewport(windowWidth, windowHeight, winPos.x, winPos.y, winSize.x, winSize.y);
    }
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::HandleEvents(const std::list<SDL_Event>& events, std::list<SDL_Event>& unusedEvents)
{
    if (mGuiCamera) {
        mImGuiContext.HandleEvents(events, unusedEvents);
    } else {
        unusedEvents = events;
    }
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::SetGuiCamera(TCamera* pCamera)
{
    mGuiCamera = pCamera;
}
//--------------------------------------------------------------------------------------------
TCamera* TGraphicEngineContext::GetGuiCamera() const
{
    return mGuiCamera;
}
//--------------------------------------------------------------------------------------------
//void TGraphicEngineContext::AddRender(IRenderable* pRenderable)
//{
//    mImGuiContext.AddRender(pRenderable);
//}
////--------------------------------------------------------------------------------------------
//void TGraphicEngineContext::RemoveRender(IRenderable* pRenderable)
//{
//    mImGuiContext.RemoveRender(pRenderable);
//}
//--------------------------------------------------------------------------------------------