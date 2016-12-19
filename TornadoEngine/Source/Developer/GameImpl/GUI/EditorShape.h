/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef EditorShapeH
#define EditorShapeH

#include "BaseGUI.h"
#include <MyGUI.h>
#include <Ogre.h>

#include <memory>
#include "BuilderShape_Ogre.h"

class TPlateParam;
class TPlateVarGeomParam;

class TClientMain;

class TEditorShape : public TBaseGUI
{
  std::auto_ptr<TPlateParam>        mPlateParamForm;
  std::auto_ptr<TPlateVarGeomParam> mPlateVarGeomParamForm;

  TBaseGUI* mCurNewShape;

  Ogre::MeshPtr mCurMesh;

  TBuilderShape_Ogre mBuilder;
public:
  TEditorShape();
  virtual ~TEditorShape();

protected:
  virtual void Activate();
  virtual void* GetParent();
  virtual const char* GetNameLayout();
  virtual void SetupTabChild();

  virtual void KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char);
protected:
  void OpenShape();
  void NewShape();
  void SaveShape();

  void NewPlate();
  void NewPlateVarGeom();
  void NewSphere();
  void NewCylinder();
  void NewCone();
  void NewTriangularPyramid();
  void NewQuadrangularPyramid();
  void NewTrianglePrism();

  void ShowNewShape(TBaseGUI* pForm);
protected:
  void sl_WidgetsSelect(MyGUI::MenuControl* _sender, MyGUI::MenuItem* _item);

  MyGUI::MenuBar*     mBar;
  MyGUI::MenuControl* mPopupMenu_File;
  MyGUI::MenuControl* mPopupMenu_NewShape;
  MyGUI::MenuControl* mPopupMenu_Instruments;

  MyGUI::MenuItem* miOpen;
  MyGUI::MenuItem* miSave;
  MyGUI::MenuItem* miExit;

  MyGUI::MenuItem* miNewShape_Plastina;
  MyGUI::MenuItem* miNewShape_PlastinaVarGeom;
  MyGUI::MenuItem* miNewShape_Sphere;
  MyGUI::MenuItem* miNewShape_Cylinder;
  MyGUI::MenuItem* miNewShape_Cone;
  MyGUI::MenuItem* miNewShape_Pyramid3;
  MyGUI::MenuItem* miNewShape_Pyramid4;
};

#endif 
