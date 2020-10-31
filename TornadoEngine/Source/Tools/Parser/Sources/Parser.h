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
#include "ParserResultContainer.h"
#include "LexemaEngine.h"

namespace nsCppParser
{
    // content -> 
    // {token} -> 
    // blocks + lines -> {LineSplitter} -> 
    // lexemaEngine -> blocks + lexemas -> 
    // container {TypeInfo, Functions, etc}
    class DllExport TParser
    {
        TBlockTokenEntity mRoot;

        TLineSplitter mLineSplitter;

        TLexemaEngine mLexemaEngine;

        TParserResultContainer mContainer;
    public:
        // Get results from TypeManager
        void Parse(const std::string& content);

        const TParserResultContainer* GetResult() const;

    private:
        void LineSplit(TBlockTokenEntity* blockToken);
    };
}