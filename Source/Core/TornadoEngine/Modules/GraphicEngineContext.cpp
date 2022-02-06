/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngineContext.h"

#include <OgreOverlaySystem.h>
#include <OgreOverlayManager.h>

#include <OgreMeshManager.h>
#include <OgreMeshManager2.h>
#include <OgreMesh.h>
#include <OgreMesh2.h>

using namespace nsTornadoEngine;

void TGraphicEngineContext::Init(nsGraphicEngine::TGraphicEngine_Ogre_ImGui* pGE)
{
    mGE = pGE;

    mSceneManager = mGE->GetRoot()->createSceneManager(Ogre::ST_GENERIC, 1, "ExampleSMInstance");

    mSceneManager->addRenderQueueListener(mGE->GetOverlaySystem());
    mSceneManager->getRenderQueue()->setSortRenderQueue(
        Ogre::v1::OverlayManager::getSingleton().mDefaultRenderQueueId,
        Ogre::RenderQueue::StableSort);

    //Set sane defaults for proper shadow mapping
    mSceneManager->setShadowDirectionalLightExtrusionDistance(500.0f);
    mSceneManager->setShadowFarDistance(500.0f);

    CreateCamera();


    Ogre::v1::MeshManager::getSingleton().createPlane("MyPlane",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        Ogre::Plane(Ogre::Vector3::UNIT_Y, 1.0f), 50.0f, 50.0f,
        1, 1, true, 1, 8.1f, 8.12f, Ogre::Vector3::UNIT_Z,
        Ogre::v1::HardwareBuffer::HBU_STATIC,
        Ogre::v1::HardwareBuffer::HBU_STATIC);

    ImportV1Mesh("MyPlane");

    // Context
    //auto keyMouse = Modules()->KeyMouse();
    //mGE->SetKeyMouseEventContainer(keyMouse);
    //nsImGuiWidgets::TWidget::SetInputContainer(keyMouse);

    ////###
    //// Костыль
    //mGE->AddRender(&mDialogStack);
    //###
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::AddRender(nsGraphicEngine::IRenderable* pRenderable)
{

}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::RemoveRender(nsGraphicEngine::IRenderable* pRenderable)
{

}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::CreateCamera()
{
    auto mCamera = mSceneManager->createCamera("Main Camera");

    // Position it at 500 in Z direction
    mCamera->setPosition(Ogre::Vector3(0, 5, 15));
    // Look back along -Z
    mCamera->lookAt(Ogre::Vector3(0, 0, 0));
    mCamera->setNearClipDistance(0.2f);
    mCamera->setFarClipDistance(1000.0f);
    mCamera->setAutoAspectRatio(true);
}
//-----------------------------------------------------------------------------------
void TGraphicEngineContext::ImportV1Mesh(const Ogre::String& meshName)
{
    Ogre::v1::MeshPtr v1Mesh;
    Ogre::MeshPtr v2Mesh;

    v1Mesh = Ogre::v1::MeshManager::getSingleton().load(
        meshName, Ogre::ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME,
        Ogre::v1::HardwareBuffer::HBU_STATIC, Ogre::v1::HardwareBuffer::HBU_STATIC);

    //Create a v2 mesh to import to, with a different name (arbitrary).
    v2Mesh = Ogre::MeshManager::getSingleton().createByImportingV1(
        meshName, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        v1Mesh.get(), true, true, true);

    //Free memory
    v1Mesh->unload();

    // Do not destroy mesh, it could be used to recover from lost device.
    //Ogre::v1::MeshManager::getSingleton().remove( meshName );
}
//--------------------------------------------------------------------------------------------