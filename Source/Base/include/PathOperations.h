/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <set>

#include "TypeDef.h"

namespace nsBase
{
    class DllExport TPathOperations
    {
    public:
        static std::string CalculatePathBy(const std::string& abs, const std::string& absOrRel);
        static std::string FileDirPath(const std::string& filePath);
        static std::string GetCurrentDir();

        static void AddAbsPathsByDirectory(const std::string& directory, const std::set<std::string>& extensions,
            std::list<std::string>& fileList, bool recursive = true);


        // Example:
        // absBase = "C:\X\D"
        // abs = C:\Y\S
        // rel => ..\..\Y\S
        static bool GetRelativePath(const std::string& absBase, const std::string& abs, std::string& rel);

    private:
        template <typename DirectoryIterator>
        static void AddAbsPathsByDirectory(const std::string& directory, const std::set<std::string>& extensions, 
            std::list<std::string>& fileList);

    };
}