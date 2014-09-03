/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MakerTransportH
#define MakerTransportH

#include "IMakerTransport.h"

class TMakerTransport : public IMakerTransport
{
public:
  virtual INetTransport* New();
  virtual void Delete(INetTransport* pTransport);

};

#endif