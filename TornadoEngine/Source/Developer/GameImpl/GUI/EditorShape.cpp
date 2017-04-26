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
#include "ModuleGraphicEngine.h"
#include "ListModules.h"
#include "LogicEventCallBack.h"

#include <OgreManualObject.h>

#include "PlateParam.h"
#include "PlateVarGeomParam.h"
#include "ShapeItem.h"

TEditorShape::TEditorShape() : 
mPlateParamForm(new TPlateParam),
mPlateVarGeomParamForm(new TPlateVarGeomParam)
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

  mCurNewShape = nullptr;
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
  mPopupMenu_NewShape->eventMenuCtrlAccept += MyGUI::newDelegate(this, &TEditorShape::sl_WidgetsSelect);

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
    NewPlate();
  if(_item==miNewShape_PlastinaVarGeom)
    NewPlateVarGeom();
  if(_item==miNewShape_Sphere)
    NewSphere();
  if(_item==miNewShape_Cylinder)
    NewCylinder();
  if(_item==miNewShape_Cone)
    NewCone();
  if(_item==miNewShape_Pyramid3)
    NewTriangularPyramid();
  if(_item==miNewShape_Pyramid4)
    NewQuadrangularPyramid();
}
//-------------------------------------------------------------------------------------
void TEditorShape::OpenShape()
{
#if 0
  // взять имя из предложенных
  std::string name = "PlateVarGeom";//###

  TShapeItem* pItem = (TShapeItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Shape, name);
  Ogre::Entity* pEnt = mBuilder.Build(pItem);
	if( pEnt==NULL )
		return;

	Ogre::SceneManager* pSM = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager();
	pSM->setAmbientLight(Ogre::ColourValue(1, 1, 1));

	pEnt->setCastShadows(false);
  Ogre::SceneNode* pNode = pEnt->getParentSceneNode();
  pNode->attachObject(pEnt);

  const Ogre::Vector3 pos(0,0,0);
  pNode->setPosition(pos);
#endif
}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewShape()
{
  //nsParamBuilderShape::TPlate mPlastina;
  //Ogre::MeshPtr ptr = mBuilder.Build(&mPlastina);
  //Ogre::MeshSerializer ser;
  //ser.exportMesh(ptr.getPointer(), "../../Resources/Graphic/models/EditorShape/Cube.mesh");

  //Ogre::SceneManager* pSM = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()->GetSceneManager();
  //pSM->setAmbientLight(Ogre::ColourValue(1, 1, 1));
  //Ogre::Entity* pEnt = pSM->createEntity(ptr);
  //pEnt->setCastShadows(false);

  //Ogre::SceneNode* pNode = pSM->getRootSceneNode()->createChildSceneNode();
  //pNode->attachObject(pEnt);

  //const Ogre::Vector3 pos(0,0,0);
  //pNode->setPosition(pos);
}
//---------------------------------------------------------------------------------------------
void TEditorShape::SaveShape()
{

}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewPlate()
{
  ShowNewShape(mPlateParamForm.get());
  //ShowNewShape(mClientMain.get());
}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewPlateVarGeom()
{
  ShowNewShape(mPlateVarGeomParamForm.get());
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
void TEditorShape::NewTriangularPyramid()
{

}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewQuadrangularPyramid()
{

}
//---------------------------------------------------------------------------------------------
void TEditorShape::NewTrianglePrism()
{

}
//---------------------------------------------------------------------------------------------
void TEditorShape::ShowNewShape(TBaseGUI* pForm)
{
  if(mCurNewShape)
    mCurNewShape->Hide();

  mCurNewShape = pForm;
  mCurNewShape->Show();
}
//---------------------------------------------------------------------------------------------
