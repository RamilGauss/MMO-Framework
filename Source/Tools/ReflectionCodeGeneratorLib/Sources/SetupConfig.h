/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/ConfigContainer.h"

namespace nsReflectionCodeGenerator
{
    class TSetupConfig
    {
        int mArgc = 0;
        char** mArgv = nullptr;
    public:
        void Init(TConfigContainer* configContainer, TCache* cache, int argc, char** argv);
        bool Work();

    public:
        TConfigContainer* mConfigContainer = nullptr;
        TCache* mCache = nullptr;

        std::string mAbsPathDirJson;
        std::string mAbsPathJsonFile;
    protected:
        void ShowManual();
        void DefaultConfig();
    private:
        bool TryLoadConfig();
        void ConvertConfigToCache();

        void ResolveJsonPath();
    };
}