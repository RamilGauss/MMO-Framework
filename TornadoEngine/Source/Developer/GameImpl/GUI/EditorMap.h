/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef EditorMapH
#define EditorMapH

#include "BaseGUI.h"
#include <MyGUI.h>
#include <Ogre.h>

#include <boost/smart_ptr/scoped_ptr.hpp>

class TEditorMap : public TBaseGUI
{
public:
  TEditorMap();
  virtual ~TEditorMap();

protected:
  virtual void Activate();
  virtual void* GetParent();
  virtual const char* GetNameLayout();
  virtual void SetupTabChild();

  virtual void KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char);
protected:
	void SetNameMode(std::string sMode);
protected:
  void sl_Open(MyGUI::Widget* _sender);
	void sl_Save(MyGUI::Widget* _sender);
  void sl_Exit(MyGUI::Widget* _sender);
	void sl_ToggleUsePhysic(MyGUI::Widget* _sender);
  
	void sl_Mode_Fly(MyGUI::Widget* _sender);
  void sl_Mode_TerrainExtent(MyGUI::Widget* _sender);
  void sl_Mode_TerrainHeight(MyGUI::Widget* _sender);
  void sl_Mode_TerrainPainter(MyGUI::Widget* _sender);
  void sl_Mode_MapParameter(MyGUI::Widget* _sender);
  void sl_Mode_Objects(MyGUI::Widget* _sender);

protected:
  MyGUI::MenuBar*     mBar;
  MyGUI::MenuControl* mPopupMenu_File;
  MyGUI::MenuControl* mPopupMenu_Mode;
	

  //MyGUI::MenuControl* mPopupMenu_Instruments;
	// File
  MyGUI::MenuItem* miOpen;
  MyGUI::MenuItem* miSave;
  MyGUI::MenuItem* miExit;
	// Mode
	MyGUI::MenuItem* miMode_Fly;
	MyGUI::MenuItem* miMode_TerrainExtent;
	MyGUI::MenuItem* miMode_TerrainHeight;
	MyGUI::MenuItem* miMode_TerrainPainter;
	MyGUI::MenuItem* miMode_MapParameter;
	MyGUI::MenuItem* miMode_Objects;

	MyGUI::Button* cbUsePhysic;
};

#endif 
