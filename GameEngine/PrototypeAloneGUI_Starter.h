/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeAloneGUI_StarterH
#define PrototypeAloneGUI_StarterH

#include "TypeDef.h"
#include "PrototypeBaseModule.h"

class PrototypeAloneGUI_Dev;

class DllExport PrototypeAloneGUI_Starter : public PrototypeBaseModule
{
public:
  PrototypeAloneGUI_Starter();
  virtual ~PrototypeAloneGUI_Starter();

  virtual void SetDev(PrototypeAloneGUI_Dev* pDev) = 0;

  virtual int GetVersionPrototype();
};


#endif