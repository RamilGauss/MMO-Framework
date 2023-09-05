/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>

#include "SceneResourceContent.h"

namespace nsTornadoEngine
{
    class DllExport TSceneHashCalculator
    {
    public:
        static std::string Calculate(const std::list<std::string>& entityGuids);
    };
}
