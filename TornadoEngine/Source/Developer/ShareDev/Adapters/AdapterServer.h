/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterServerH
#define AdapterServerH

#include "PrototypeDev.h"

class DllExport AdapterServer : public PrototypeDev
{
public:

  AdapterServer();
  virtual ~AdapterServer();

  virtual bool Work();
};

#endif
