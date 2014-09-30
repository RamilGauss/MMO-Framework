/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HandlerMMO_SlaveH
#define HandlerMMO_SlaveH

#include "HandlerMMO.h"

class THandlerMMO_Slave : public THandlerMMO
{
public:
  THandlerMMO_Slave();
protected:
  virtual void HandleFromMMOEngine(nsEvent::TEvent* pEvent);
};

#endif
