/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterDevToolH
#define AdapterDevToolH

#include "PrototypeDev.h"

class DllExport AdapterDevTool : public PrototypeDev
{
public:
  AdapterDevTool();
  virtual ~AdapterDevTool();

  virtual bool Work();
};

#endif
