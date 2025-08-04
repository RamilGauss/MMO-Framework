/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "ReflectionCodeGeneratorLib/Sources/ResolvedConfig.h"
#include "ReflectionCodeGeneratorLib/Sources/TypeManager.h"
#include "ReflectionCodeGeneratorLib/Sources/ProgramInfo.h"
#include "ReflectionCodeGeneratorLib/Sources/TypeNameDataBase.h"

namespace nsReflectionCodeGenerator
{
    class DllExport IGenerator
    {
    protected:
        TTypeManager* mTypeManager = nullptr;
        TResolvedConfig* mResolvedConfig = nullptr;
    public:
        using TStrList = std::list<std::string>;
        using TStrListPair = std::pair<std::string, TStrList>;
        using TPairList = std::list<TStrListPair>;
    public:
        IGenerator() = default;

        virtual void Work() = 0;

        void SetTypeManager(TTypeManager* typeManager);
        void SetResolvedConfig(TResolvedConfig* resolvedConfig);
    };
}
