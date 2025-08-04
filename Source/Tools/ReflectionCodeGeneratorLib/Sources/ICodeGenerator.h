/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Parser/Sources/TypeInfo.h"

#include "ReflectionCodeGeneratorLib/Sources/IGenerator.h"

namespace nsReflectionCodeGenerator
{
    class DllExport ICodeGenerator : public IGenerator
    {
    protected:
        std::string mName;
        TPairList* mPairList;
    public:
        ICodeGenerator(const std::string& name);

        // abs path file - list parts of file
        void Init(TPairList& result);
    };
}