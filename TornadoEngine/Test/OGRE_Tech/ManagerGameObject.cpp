/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerGameObject.h"

SINGLETON_CPP(TManagerGameObject)

TManagerGameObject::TManagerGameObject()
{

}
//-----------------------------------------------------------------------------
TManagerGameObject::~TManagerGameObject()
{

}
//-----------------------------------------------------------------------------
bool TManagerGameObject::SetPathList(std::string sPathXML)
{
  
  return false;
}
//-----------------------------------------------------------------------------
bool TManagerGameObject::Load(std::string sNameXML, TGameObject* pObject)
{
  return false;
}
//-----------------------------------------------------------------------------
bool TManagerGameObject::Load(unsigned int id, TGameObject* pObject)
{
  return false;
}
//-----------------------------------------------------------------------------
//bool TManagerGameObject::Load()
//{
//  pEnt->setCastShadows(false);
//  Ogre::SceneNode* pNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
//  pNode->attachObject(pEnt);
//
//  pNode->setScale(orient.scale);
//  pNode->rotate(orient.axisRotate, orient.angleRotate);
//  pNode->setPosition(orient.pos);
//}
//-----------------------------------------------------------------------------
bool TManagerGameObject::GetTypeByID(unsigned int id, std::string& sType)
{
  return false;
}
//-----------------------------------------------------------------------------
bool TManagerGameObject::GetTypeByNameXML(std::string sNameXML, std::string& sType)
{
  return false;
}
//-----------------------------------------------------------------------------
