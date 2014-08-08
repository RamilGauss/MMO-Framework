/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeGraphicEngineGUIH
#define PrototypeGraphicEngineGUIH

#include <string>
#include "TypeDef.h"

struct TGUIDescWindow;

class DllExport PrototypeGraphicEngineGUI
{
public:
  PrototypeGraphicEngineGUI();
  virtual ~PrototypeGraphicEngineGUI();

  virtual void AddResourceLocation(const std::string& _name, bool _recursive = false ) = 0;

  virtual bool AddWindow(TGUIDescWindow* descWindow) = 0;

  virtual void Render()     = 0;
  virtual void Resize()     = 0;
  virtual void Destroy()    = 0;
  virtual void LostDevice() = 0;
};

#endif