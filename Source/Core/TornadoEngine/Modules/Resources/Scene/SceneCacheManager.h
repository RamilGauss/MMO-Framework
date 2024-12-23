/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>
#include <unordered_map>
#include <memory>

#include "Base/Common/TypeDef.h"

namespace nsTornadoEngine
{
    struct TSceneResourceContent;

    class DllExport TSceneCacheManager
    {
    public:
        using TSceneResourceContentPtr = std::shared_ptr<TSceneResourceContent>;

        void Add(const std::string& guid, TSceneResourceContentPtr ptr);

        TSceneResourceContentPtr Get(const std::string& guid) const;

        void Remove(const std::string& guid);

        std::list<std::string> GetGuids() const;
    private:
        std::unordered_map<std::string, TSceneResourceContentPtr> mScenes;
    };
}
