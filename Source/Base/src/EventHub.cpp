/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/EventHub.h"

namespace nsBase::nsCommon
{
void TEventHub::TakeEvents(std::list<std::string>& events)
{
    std::swap(events, mEvents);
}
}
