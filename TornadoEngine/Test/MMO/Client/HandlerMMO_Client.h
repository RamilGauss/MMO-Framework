/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HandlerMMO_ClientH
#define HandlerMMO_ClientH

#include "HandlerMMO.h"

class THandlerMMO_Client : public THandlerMMO
{
public:
  THandlerMMO_Client();
protected:
  virtual void HandleFromMMOEngine( nsEvent::TEvent* pEvent );
};

#endif
