/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EditorShape.h"

#include "Precompiled.h"
#include <atlconv.h>

#include "ModuleLogic.h"
#include "ListModules.h"
#include "Client.h"
#include "LogicEventCallBack.h"

#include "ClientLogic.h"
#include "ModuleGraphicEngine.h"

#include <OgreManualObject.h>

TEditorShape::TEditorShape() 
{
  mBar                       = nullptr;
  mPopupMenu_File            = nullptr;
  mPopupMenu_NewShape        = nullptr;
  mPopupMenu_Instruments     = nullptr;
  miOpen                     = nullptr;
  miSave                     = nullptr;
  miExit                     = nullptr;
  miNewShape_Plastina        = nullptr;
  miNewShape_PlastinaVarGeom = nullptr;
  miNewShape_Sphere          = nullptr;
  miNewShape_Cylinder        = nullptr;
  miNewShape_Cone            = nullptr;
  miNewShape_Pyramid3        = nullptr;
  miNewShape_Pyramid4        = nullptr;
}
//------------------------------------------------------
TEditorShape::~TEditorShape()
{

}
//-------------------------------------------------------------------------------------
void TEditorShape::Activate()
{
  assignWidget(mBar, "Menu");
  // меню для виджетов
  mPopupMenu_File = mBar->findItemById("File", true)->getItemChild();
  mPopupMenu_File->eventMenuCtrlAccept += MyGUI::newDelegate(this, &TEditorShape::sl_WidgetsSelect);

  mPopupMenu_NewShape = mBar->findItemById("NewShape", true)->getItemChild();
  mPopupMenu_File->eventMenuCtrlAccept += MyGUI::newDelegate(this, &TEditorShape::sl_WidgetsSelect);

  miOpen = mPopupMenu_File->findItemById("Command_FileOpen");
  miSave = mPopupMenu_File->findItemById("Command_FileSave");
  miExit = mPopupMenu_File->findItemById("Command_FileExit");

  miNewShape_Plastina        = mPopupMenu_NewShape->findItemById("Command_NewShape_Plastina");
  miNewShape_PlastinaVarGeom = mPopupMenu_NewShape->findItemById("Command_NewShape_PlastinaVarGeom");
  miNewShape_Sphere          = mPopupMenu_NewShape->findItemById("Command_NewShape_Sphere");
  miNewShape_Cylinder        = mPopupMenu_NewShape->findItemById("Command_NewShape_Cylinder");
  miNewShape_Cone            = mPopupMenu_NewShape->findItemById("Command_NewShape_Cone");
  miNewShape_Pyramid3        = mPopupMenu_NewShape->findItemById("Command_NewShape_Pyramid3");
  miNewShape_Pyramid4        = mPopupMenu_NewShape->findItemById("Command_NewShape_Pyramid4");
}
//-------------------------------------------------------------------------------------
const char* TEditorShape::GetNameLayout()
{
  return "EditorShape.layout";
}
//-------------------------------------------------------------------------------------
void* TEditorShape::GetParent()
{
  return nullptr;
}
//-------------------------------------------------------------------------------------
void TEditorShape::SetupTabChild()
{

}
//-------------------------------------------------------------------------------------
void TEditorShape::KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
{
  switch(_key.getValue())
  {
    case MyGUI::KeyCode::Return:
      //sl_Enter(_sender);
      break;
    default:;
  }
}
//-------------------------------------------------------------------------------------
void TEditorShape::sl_WidgetsSelect(MyGUI::MenuControl* _sender, MyGUI::MenuItem* _item)
{
  if(_item==miOpen)
    OpenShape();
  if(_item==miSave)
    SaveShape();
  if(_item==miExit)
    TModuleLogic::Get()->Exit();
  if(_item==miNewShape_Plastina)
    NewPlastina();
  if(_item==miNewShape_PlastinaVarGeom)
    NewPlastinaVarGeom();
  if(_item==miNewShape_Sphere)
    NewSphere();
  if(_item==miNewShape_Cylinder)
    NewCylinder();
  if(_item==miNewShape_Cone)
    NewCone();
  if(_item==miNewShape_Pyramid3)
    NewPyramid3();
  if(_item==miNewShape_Pyramid4)
    NewPyramid4();
}
//-------------------------------------------------------------------------------------
void TEditorShape::OpenShape()
{

}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewShape()
{
  // выбрать из списка шаблон
  


  const float size = 60;
  Ogre::ManualObject mo("Cube");

  mo.begin("Cube", Ogre::RenderOperation::OT_TRIANGLE_LIST);
  
  mo.position(-size, -size, -size);
  mo.textureCoord(0, 0);

  mo.position(-size, size, -size);
  mo.textureCoord(1, 0);

  mo.position(size, size, -size);
  mo.textureCoord(1, 1);

  mo.position(size, -size, -size);
  mo.textureCoord(0, 1);
  //-----------------------------------  
  mo.position(-size, -size, size);
  mo.textureCoord(1, 0);

  mo.position(-size, size, size);
  mo.textureCoord(0, 0);

  mo.position(size, size, size);
  mo.textureCoord(1, 1);

  mo.position(size, -size, size);
  mo.textureCoord(0, 1);

  mo.triangle(0,1,2);
  mo.triangle(0,2,3);

  mo.triangle(0,4,5);
  mo.triangle(0,5,1);

  mo.triangle(3,2,6);
  mo.triangle(3,6,7);

  mo.triangle(0,7,4);
  mo.triangle(0,3,7);

  mo.triangle(1,5,6);
  mo.triangle(1,6,2);

  mo.triangle(4,6,5);
  mo.triangle(4,7,6);
  mo.end();

  Ogre::MeshPtr ptr = mo.convertToMesh("GrassBladesMesh");
  Ogre::MeshSerializer ser;
  ser.exportMesh(ptr.getPointer(), "../../Resources/Graphic/models/EditorShape/Cube.mesh");

  Ogre::SceneManager* pSM = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager();
  pSM->setAmbientLight(Ogre::ColourValue(1, 1, 1));
  Ogre::Entity* pEnt = pSM->createEntity(ptr);
  pEnt->setCastShadows(false);

  Ogre::SceneNode* pNode = pSM->getRootSceneNode()->createChildSceneNode();
  pNode->attachObject(pEnt);

  const Ogre::Vector3 pos(0,0,0);
  pNode->setPosition(pos);
}
//---------------------------------------------------------------------------------------------
void TEditorShape::SaveShape()
{

}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewPlastina()
{

}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewPlastinaVarGeom()
{

}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewSphere()
{

}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewCylinder()
{

}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewCone()
{

}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewPyramid3()
{

}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewPyramid4()
{

}
//---------------------------------------------------------------------------------------------
