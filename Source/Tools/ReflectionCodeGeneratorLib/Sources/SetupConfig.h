/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/Config.h"

namespace nsReflectionCodeGenerator
{
    class TSetupConfig
    {
        int mArgc = 0;
        char** mArgv = nullptr;
    public:
        void Init(TResolvedConfig* resolvedConfig, int argc, char** argv);
        bool Work();
    protected:
        TConfig mConfig;
        TResolvedConfig* mResolvedConfig = nullptr;

        std::string mAbsPathDirJson;
        std::string mAbsPathJsonFile;
        void ShowManual();
        void DefaultConfig();
    private:
        bool TryLoadConfig();
        void ResolveConfig();

        void ResolveJsonPath();

        void CollectAbsPaths(const std::string& dir,
           const std::unordered_set<std::string>& extSet, std::unordered_set<std::string>& fileList);
    };
}
