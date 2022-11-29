/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ConfigContainer.h"

namespace nsContainerCodeGenerator
{
    class TSetupConfig
    {
        int mArgc = 0;
        char** mArgv = nullptr;
    public:
        void Init(int argc, char** argv);
        bool Work();

    public:
        TConfigContainer* mConfigContainer;

        std::string mAbsPathDirJson;
        std::string mAbsPathJsonFile;
    private:
        bool TryLoadConfig();

        void ResolvePath(std::string& path);
        void ResolvePathes();

        void ResolveJsonPath();
    };
}