/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/EventHub.h"

namespace nsBase::nsCommon
{
    extern DllExport TEventHub* GetEventHub(std::string&& source = "Common", std::source_location loc = std::source_location::current());
}
