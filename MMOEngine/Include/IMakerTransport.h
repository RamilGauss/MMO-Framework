/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef IMAKERTRANSPORT_H
#define IMAKERTRANSPORT_H

#include "INetTransport.h"

namespace nsMMOEngine
{
  class MMO_ENGINE_EI IMakerTransport
  {

  public:
    IMakerTransport(){}
    virtual ~IMakerTransport(){}
    
    virtual INetTransport* New() = 0;
    virtual void Delete(INetTransport* pTransport)= 0;
  };
}

#endif