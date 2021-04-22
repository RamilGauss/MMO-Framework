/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Config.h"
#include "TypeManager.h"
#include "ProgramInfo.h"
#include "TypeNameDataBase.h"

namespace nsReflectionCodeGenerator
{
    class IGenerator
    {
    protected:
        TConfig* mConfig = nullptr;
        TTypeManager* mTypeManager = nullptr;
    public:
        using TStrList = std::list<std::string>;
        using TStrListPair = std::pair<std::string, TStrList>;
        using TPairList = std::list<TStrListPair>;
    public:
        IGenerator();

        virtual void Work() = 0;
    };
}