/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HandlerMMO_MasterH
#define HandlerMMO_MasterH

#include "HandlerMMO.h"
#include <list>
#include "SHA256.h"

class THandlerMMO_Master : public THandlerMMO
{
  TSHA256 mSHA256;
  TContainer mSlaveHashLogin;
public:
  THandlerMMO_Master();
protected:
  virtual void HandleFromMMOEngine(nsEvent::TEvent* pEvent);
};

#endif
