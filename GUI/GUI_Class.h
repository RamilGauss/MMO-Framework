/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GUI_ClassH
#define GUI_ClassH

#include "IGUI.h"
#include "MyGUI_Manager.h"

class TGUI_Class : public IGUI
{

  TMyGUI_Manager mMyGUI;
  
public:
  TGUI_Class();
  virtual ~TGUI_Class();

  virtual void AddResourceLocation(const std::string& _name, bool _recursive = false );

  virtual bool AddWindow(TGUIDescWindow* descWindow);
  virtual void Render();
  virtual void Resize();
  virtual void Destroy();
  virtual void LostDevice();

protected:


};

#endif