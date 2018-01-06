/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "WIP_Port.h"

namespace ManagedMMOEngineWrapper
{
  WIP_Port::WIP_Port()
  {

  }
  //--------------------------------------------------------------
  WIP_Port::WIP_Port(unsigned int _ip, unsigned short _port)
  {
    ip   = _ip;
    port = _port;
  }
  //--------------------------------------------------------------
  void WIP_Port::Set(unsigned int _ip, unsigned short _port)
  {
    ip   = _ip;
    port = _port;
  }
  //--------------------------------------------------------------
}
