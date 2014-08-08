/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterAloneGUI_DevH
#define AdapterAloneGUI_DevH

#include "PrototypeAloneGUI_Dev.h"

class IQtLib;

class AdapterAloneGUI_Dev : public PrototypeAloneGUI_Dev
{
  IQtLib* mQtLib;

public:
  AdapterAloneGUI_Dev();
  virtual ~AdapterAloneGUI_Dev();

  virtual void Start();
  virtual void Stop();

  IQtLib* Get();
};


#endif