/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef WrapperMakerTransportH
#define WrapperMakerTransportH

#include "IMakerTransport.h"

class TWrapperMakerTransport : public IMakerTransport
{
public:
  TWrapperMakerTransport();
  virtual ~TWrapperMakerTransport();
  
  virtual INetTransport* New();
  virtual void Delete(INetTransport* pTransport);
};

#endif