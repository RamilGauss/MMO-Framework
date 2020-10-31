/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>
#include <filesystem>

#include "Config.h"
#include "SingletonManager.h"
#include "ConfigContainer.h"

#include "Parser/Sources/Parser.h"

namespace nsReflectionCodeGenerator
{
    class TParser
    {
        typedef std::set<std::string> TSetStr;

        std::set<std::string> mFilePathForParseSet;

        nsCppParser::TParser mCppParser;
    public:
        void Work();

    private:
        void Tokenize();

        template <typename DirectoryIterator>
        void CollectAbsPaths()
        {
            auto config = SingletonManager()->Get<nsReflectionCodeGenerator::TConfigContainer>()->Config();
            TSetStr extSet(config->filter.extensions.begin(), config->filter.extensions.end());

            for ( auto& dir : config->targetForParsing.directories )
            {
                for ( auto& p : DirectoryIterator((char*)dir.data()) )
                {
                    auto path = p.path();
                    std::string ext = path.extension().string();
                    if ( extSet.find(ext) == extSet.end() )
                        continue;
                    auto str = std::filesystem::canonical(path).string();
                    mFilePathForParseSet.insert(str);
                }
            }
        }
    };
}