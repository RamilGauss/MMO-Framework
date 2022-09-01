/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngineContext.h"
#include "ShaderFactory.h"
#include "ShaderPrefabs.h"

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

    // Draw all renderable objects
    mRenderableObjectShader->MakeCurrentInConveyer();
    mRenderableObjectShader->SetInt("texture1", 0);

    for (auto& camera : mCameras) {

        camera->Begin();

        auto winSize = camera->GetWindowSize();
        auto winPos = camera->GetWindowPosition();

        // In OpenGL a lower left corner has (0,0), in BigJack a top left corner has (0,0)
        glViewport(winPos.x, windowHeight - winSize.y - winPos.y, winSize.x, winSize.y);

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
            mImGuiContext.Render(winPos.x, windowHeight - winSize.y - winPos.y, winSize.x, winSize.y);
        }

        camera->End();
    }

    for (auto& camera : mCameras) {
        if (camera->IsRenderOnDisplay()) {
            mCamerasRenderOnDisplayShader->MakeCurrentInConveyer();
            mCamerasRenderOnDisplayShader->SetInt("texture1", 0);
            mCamerasRenderOnDisplayShader->SetFloat2("pos", 0.0f, 0.0f);
            mCamerasRenderOnDisplayShader->SetFloat2("size", 2.0f, 2.0f);

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
void TGraphicEngineContext::HandleEvents(const std::list<SDL_Event>& events, std::list<SDL_Event>& unusedEvents)
{
    if (mGuiCamera) {
        auto pos = mGuiCamera->GetWindowPosition();

        mImGuiContext.HandleEvents(events, unusedEvents, pos.x, pos.y);
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
void TGraphicEngineContext::AddRender(IRenderable* pRenderable)
{
    mImGuiContext.AddRender(pRenderable);
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::RemoveRender(IRenderable* pRenderable)
{
    mImGuiContext.RemoveRender(pRenderable);
}
//--------------------------------------------------------------------------------------------