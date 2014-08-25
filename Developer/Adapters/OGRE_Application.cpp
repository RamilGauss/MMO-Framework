/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "OGRE_Application.h"
#include "..\..\Base\Share\BL_Debug.h"
#include "MapXML_Field.h"
#include "StorePathResources.h"

TOGRE_Application::TOGRE_Application()
{
#ifdef _DEBUG
  //mResourcePath = "../../Exe/Debug/";
	mResourcePath = "../Exe/Debug/";
#else
  mResourcePath = "../../Exe/Release/";
#endif
  mConfigPath = mResourcePath;
}
//------------------------------------------------------------------------------------------
TOGRE_Application::~TOGRE_Application()
{
  // clean up
  //destroyScene();	
	mGUI->shutdown();
	delete mGUI;
	mGUI = 0;   
	mPlatform->shutdown();
	delete mPlatform;
	mPlatform = 0;
}
//------------------------------------------------------------------------------------------
void TOGRE_Application::createScene() 
{
	// Инициализируем MyGUI
	mPlatform = new MyGUI::OgrePlatform();
	mPlatform->initialise(mWindow, mSceneMgr);
	mGUI = new MyGUI::Gui();
	mGUI->initialise("../resources/media/MyGUI_Media/MyGUI_Core.xml");

	/*TMapXML_Field* pMap = GetStorePathResources();
	int cntGUI = pMap->GetCount("GUI");
	for(int i = 0 ; i < cntGUI ; i++ )
	{
		mGUI->addResourceLocation(mGUI->getRootMedia() + pMap->GetSecond("GUI",i),false);
  }
  //------------------------------------------------------------------------
	}
	int cntSkin = pMap->GetCount("GUI_skin");
	for(int i = 0 ; i < cntSkin ; i++ )
	{
		bool res = MyGUI::ResourceManager::getInstance().load(pMap->GetSecond("GUI_skin",i));// загрузка скина
		BL_ASSERT(res);
	}*/
  Ogre::Entity* ent = mSceneMgr->createEntity("MyEntity","sinbad.mesh");
  Ogre::SceneNode* node = mSceneMgr->createSceneNode("Node1");
  mSceneMgr->getRootSceneNode()->addChild(node);
  node->attachObject(ent);

  Ogre::Entity* ent2 = mSceneMgr->createEntity("MyEntity2","sinbad.mesh");
  Ogre::SceneNode* node2 = mSceneMgr->getRootSceneNode()->createChildSceneNode("Node2");
  node2->setPosition(10,0,0);
  node2->yaw(Ogre::Degree(90));
  node2->roll(Ogre::Degree(90));
  node2->attachObject(ent2);

  Ogre::Entity* ent3 = mSceneMgr->createEntity("MyEntity3","Sinbad.mesh");
  Ogre::SceneNode* node3 = node->createChildSceneNode("node3");
  node3->setPosition(20,0,0);
  node3->yaw(Ogre::Degree(90),Ogre::Node::TS_WORLD);
  node3->roll(Ogre::Degree(90),Ogre::Node::TS_WORLD);
  node3->attachObject(ent3);

	// Set ambient light
  mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

  // Create a light
  Ogre::Light* l = mSceneMgr->createLight("MainLight");
  l->setPosition(20,80,50);
}
//------------------------------------------------------------------------------------------
void TOGRE_Application::Work()
{
  bool res = mRoot->renderOneFrame();
  BL_ASSERT(res);
}
//------------------------------------------------------------------------------------------
void TOGRE_Application::Init()
{
  bool res = setup();
  BL_ASSERT(res);
}
//------------------------------------------------------------------------------------------
bool TOGRE_Application::setup(void)
{
  String pluginsPath;
  // only use plugins.cfg if not static
#ifndef OGRE_STATIC_LIB
#if OGRE_DEBUG_MODE
  pluginsPath = mResourcePath + "plugins_d.cfg";
#else
  pluginsPath = mResourcePath + "plugins.cfg";
#endif
#endif
  mRoot = OGRE_NEW Root(pluginsPath, 
    mConfigPath + "ogre.cfg", mResourcePath + "Ogre.log");
  mOverlaySystem = OGRE_NEW OverlaySystem();
#ifdef OGRE_STATIC_LIB
  mStaticPluginLoader.load();
#endif
  setupResources();
  bool carryOn = configure();
  if (!carryOn) 
    return false;

  chooseSceneManager();
  createCamera();
  createViewports();
#ifdef INCLUDE_RTSHADER_SYSTEM
  // Initialize shader generator.
  carryOn = initializeShaderGenerator(mSceneMgr);
  if (!carryOn) 
    return false;
#endif
  // Set default mipmap level (NB some APIs ignore this)
  TextureManager::getSingleton().setDefaultNumMipmaps(5);
  // Create any resource listeners (for loading screens)
  createResourceListener();
  // Load resources
  loadResources();
  // Create the scene
  createScene();
  createFrameListener();
  return true;
}
//------------------------------------------------------------------------------------------