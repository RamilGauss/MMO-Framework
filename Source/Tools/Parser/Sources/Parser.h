/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <memory>

#include "Base/Common/TypeDef.h"
#include "Base/Common/SingletonManager.h"

#include "Parser/Sources/ITokenEntity.h"
#include "Parser/Sources/TypeInfo.h"
#include "Parser/Sources/BlockTokenEntity.h"
#include "Parser/Sources/LineSplitter.h"
#include "Parser/Sources/ParserResultContainer.h"
#include "Parser/Sources/LexemaEngine.h"
#include "Parser/Sources/BlockLexemaEntity.h"
#include "Parser/Sources/TypeInfoCollector.h"
#include "Parser/Sources/ExtendedInfoTypeExtractor.h"

namespace nsCppParser
{
    class TLineLexemaEntity;
    // content -> 
    // {token} -> 
    // blocks + lines -> {LineSplitter} -> 
    // lexemaEngine -> blocks + lexemas -> 
    // container {TypeInfo, Functions, etc}
    class DllExport TParser
    {
        std::string mLastError;

        std::shared_ptr<TBlockTokenEntity> mTokenRoot;
        std::shared_ptr<TBlockLexemaEntity> mLexemaRoot;


        TLineSplitter mLineSplitter;

        TLexemaEngine mLexemaEngine;

        TParserResultContainer mContainer;

        TTypeInfoCollector mTypeInfoCollector;

        TExtendedInfoTypeExtractor mExtendedInfoMaker;
    public:
        void SetupTypes(std::map<std::string, TypeCategory>& nameTypeMap, bool append = false);

        // Get results from TypeManager
        void Parse(const std::string& content, const std::string& fileName, const std::string& absFileName = "");

        const TParserResultContainer* GetResult() const;
        static std::string GetInfo();

        std::string GetLastError() const;

        static void AddError(std::string& str);
    private:
        void LineSplit(TBlockTokenEntity* blockToken);
        void ConvertTokenTreeToLexemaTree(TBlockTokenEntity* blockToken, TBlockLexemaEntity* blockLexema);

        void FillExtendedInfo();
    };
}