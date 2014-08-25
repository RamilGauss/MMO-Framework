/*!
	@file
	@author		Albert Semenov
	@date		08/2008
*/
#include "Precompiled.h"
#include "DemoKeeper.h"
#include "Base/Main.h"

namespace demo
{

	void DemoKeeper::setupResources()
	{
		base::BaseManager::setupResources();
    addResourceLocation(getRootMedia() + "/Demos/Demo_Themes");
    addResourceLocation(getRootMedia() + "/Common/Themes");
    addResourceLocation(getRootMedia() + "/../form");
	}
  //-------------------------------------------------------------------------------------
	void DemoKeeper::createScene()
	{
    MyGUI::ResourceManager::getInstance().load("MyGUI_BlackBlueTheme.xml");// загрузка скина
    getRoot()->getRenderSystem()->_initRenderTargets();
    //============================================================================
    //Ogre::Entity* ent = getSceneManager()->createEntity("MyEntity","sinbad.mesh");
    //Ogre::SceneNode* node = getSceneManager()->createSceneNode("Node1");
    //getSceneManager()->getRootSceneNode()->addChild(node);
    //node->attachObject(ent);

    //Ogre::Entity* ent2 = getSceneManager()->createEntity("MyEntity2","sinbad.mesh");
    //Ogre::SceneNode* node2 = getSceneManager()->getRootSceneNode()->createChildSceneNode("Node2");
    //node2->setPosition(10,0,0);
    //node2->yaw(Ogre::Degree(90));
    //node2->roll(Ogre::Degree(90));
    //node2->attachObject(ent2);

    //Ogre::Entity* ent3 = getSceneManager()->createEntity("MyEntity3","Sinbad.mesh");
    //Ogre::SceneNode* node3 = node->createChildSceneNode("node3");
    //node3->setPosition(20,0,0);
    //node3->yaw(Ogre::Degree(90),Ogre::Node::TS_WORLD);
    //node3->roll(Ogre::Degree(90),Ogre::Node::TS_WORLD);
    //node3->attachObject(ent3);

    //// Set ambient light
    //getSceneManager()->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    //// Create a light
    //Ogre::Light* l = getSceneManager()->createLight("MainLight");
    //l->setPosition(20,80,50);
  }
  //-------------------------------------------------------------------------------------
  void DemoKeeper::destroyScene()
	{
	}
  //-------------------------------------------------------------------------------------
} // namespace demo
