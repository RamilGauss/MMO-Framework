/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterGraphicEngineGUI_DX9H
#define AdapterGraphicEngineGUI_DX9H

#include "MyGUI_Manager.h"
#include "PrototypeGraphicEngineGUI.h"

class AdapterGraphicEngineGUI_DX9 : public PrototypeGraphicEngineGUI
{
  TMyGUI_Manager mMyGUI;
public:
  AdapterGraphicEngineGUI_DX9();
  virtual ~AdapterGraphicEngineGUI_DX9();

  virtual void AddResourceLocation(const std::string& _name, bool _recursive = false );

  virtual bool AddWindow(TGUIDescWindow* descWindow);
  virtual void Render();
  virtual void Resize();
  virtual void Destroy();
  virtual void LostDevice();
};

#endif