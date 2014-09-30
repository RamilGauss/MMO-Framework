/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HandlerMMO_SuperServerH
#define HandlerMMO_SuperServerH

#include "HandlerMMO.h"

class THandlerMMO_SuperServer : public THandlerMMO
{
public:
  THandlerMMO_SuperServer();
protected:
  virtual void HandleFromMMOEngine(nsEvent::TEvent* pEvent);
};

#endif
