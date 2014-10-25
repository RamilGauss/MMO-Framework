/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterAloneGUIH
#define AdapterAloneGUIH

#include "PrototypeDev.h"

class IQtLib;

class AdapterAloneGUI : public PrototypeDev
{
  IQtLib* mQtLib;

public:
  AdapterAloneGUI();
  virtual ~AdapterAloneGUI();

  virtual bool Work(){return true;}

  void Start();
  void Stop();

  IQtLib* Get();
};


#endif