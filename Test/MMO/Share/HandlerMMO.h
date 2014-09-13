/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HandlerMMOH
#define HandlerMMOH

#include "DstEvent.h"
#include "BaseEvent.h"
#include <set>

class THandlerMMO : public TDstEvent
{
public:
  THandlerMMO();
  void Work();

  static void IncreaseCountConnection();
  static void DecreaseCountConnection();
  static int  GetCountConnection();
protected:
  virtual void HandleFromMMOEngine(nsEvent::TEvent* pEvent) = 0;
  std::string GetStrError(int code);
};

#endif
