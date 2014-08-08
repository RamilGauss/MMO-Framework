/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeMMOClientH
#define PrototypeMMOClientH

#include "PrototypeMMOBase.h"

class DllExport PrototypeMMOClient : public PrototypeMMOBase
{
public:
  PrototypeMMOClient();
  virtual ~PrototypeMMOClient();

  virtual void Login(unsigned int ip, unsigned short port, void* data, int size) = 0;
  virtual void LeaveQueue() = 0;
};

#endif
