/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeMMOActiveServerH
#define PrototypeMMOActiveServerH

#include "PrototypeMMOBaseServer.h"

class DllExport PrototypeMMOActiveServer : public PrototypeMMOBaseServer
{
public:
  PrototypeMMOActiveServer();
  virtual ~PrototypeMMOActiveServer();

  virtual void ConnectUp(unsigned int ip, unsigned short port, unsigned char subNet = 0) = 0;
};

#endif
