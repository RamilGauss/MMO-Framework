/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include "LoopList.h"

namespace nsECSFramework
{
    using TypeIndexType = short;

    using TEntityID = unsigned int;
    const TEntityID NONE = (TEntityID) (-1);

    using TEntityList = std::list<TEntityID>;
    using TEntityLoopList = TLoopList<TEntityID>;
}