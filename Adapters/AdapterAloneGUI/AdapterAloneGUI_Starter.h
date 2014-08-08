/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterAloneGUI_StarterH
#define AdapterAloneGUI_StarterH

#include "PrototypeAloneGUI_Starter.h"

class DllExport AdapterAloneGUI_Starter : public PrototypeAloneGUI_Starter
{
  PrototypeAloneGUI_Dev* mDevGUI;
public:
  AdapterAloneGUI_Starter();
  virtual ~AdapterAloneGUI_Starter();

  virtual void SetDev(PrototypeAloneGUI_Dev* pDev);

  virtual PrototypeBaseModule* NewExample();
  virtual void DeleteExample(PrototypeBaseModule* ptr);

  virtual int GetVersionAdapter();

  virtual bool Work();
};


#endif