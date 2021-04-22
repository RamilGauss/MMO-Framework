/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ConfigContainer.h"

namespace nsReflectionCodeGenerator
{
    class TSetupConfig
    {
        int mArgc = 0;
        char** mArgv = nullptr;

    public:
        TSetupConfig();

        bool Work();

    public:
        TConfigContainer* mConfigContainer;

        std::string mAbsPathDirJson;
        std::string mAbsPathJsonFile;
    protected:
        void ShowManual();
        void DefaultConfig();
    private:
        bool TryLoadConfig();
        void ResolvePathes();

        std::string ResolvePathRelativeConfig(const std::string& path);

        void ResolveJsonPath();

        //void LoadExternalSources(nsReflectionCodeGenerator::TConfig* config);

        //void LoadExternalSources(nsReflectionCodeGenerator::TSerializer* serializer);
    };
}