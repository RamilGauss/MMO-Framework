/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef WrapperMMOEngineBaseEventH
#define WrapperMMOEngineBaseEventH

#include "WEventType.h"

namespace WrapperMMOEngine
{
  public ref class WBaseEvent
  {
  public:
    // переназначить в наследуемом классе
    EventType mType;
  };
}

#endif