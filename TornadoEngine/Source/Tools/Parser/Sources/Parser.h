/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <memory>

#include "TypeDef.h"
#include "SingletonManager.h"
#include "ITokenEntity.h"
#include "TypeInfo.h"
#include "BlockTokenEntity.h"
#include "LineSplitter.h"

namespace nsCppParser
{
    // content -> tokenizer -> blocks + lines -> {LineSplitter} -> lexer -> {TypeInfo}
    class DllExport TParser
    {
        TBlockTokenEntity mRoot;

        TLineSplitter lineSplitter;
    public:
        // Get results from TypeManager
        void Parse(const std::string& content);
    private:
        void LineSplit(TBlockTokenEntity* blockToken);
    };
}