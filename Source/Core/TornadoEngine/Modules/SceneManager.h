/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include <string>

namespace nsTornadoEngine
{
    class DllExport TSceneManager
    {
    public:
        void Init();

        void LoadByGuid(const std::string& guid);//???
        void LoadByAbsPath(const std::string& absPath);

        void Unload(const std::string& guid);

        void Save(const std::string& guid);

        void InstantiateByGuid(const std::string& guid);//???
        void InstantiateByAbsPath(const std::string& absPath);
    };
}