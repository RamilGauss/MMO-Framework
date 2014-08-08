/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeAloneGUI_DevH
#define PrototypeAloneGUI_DevH

#include "TypeDef.h"

class DllExport PrototypeAloneGUI_Dev
{
public:
  PrototypeAloneGUI_Dev();
  virtual ~PrototypeAloneGUI_Dev();

  virtual void Start() = 0;
  virtual void Stop() = 0;
};


#endif