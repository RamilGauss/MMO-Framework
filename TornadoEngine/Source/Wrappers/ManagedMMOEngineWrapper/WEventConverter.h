/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagedMMOEngineWrapperWEventConverterH
#define ManagedMMOEngineWrapperWEventConverterH

#include "WBaseEvent.h"
#include "DstEvent.h"

namespace ManagedMMOEngineWrapper
{
  public class WEventConverter : public TDstEvent
  {
  public:
    WEventConverter();
    virtual ~WEventConverter();

    WBaseEvent^ GetEvent();
  };
}

#endif