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

#include "TypeDef.h"

namespace nsTornadoEngine
{
    class DllExport TSceneCacheManager
    {
        std::unordered_map<std::string, void*> mScenes;
    public:
        template <typename T>
        void Add(const std::string& guid, T* p);

        template <typename T>
        const T* Get(const std::string& guid) const;

        void Remove(const std::string& guid);

        std::list<std::string> GetGuids() const;
    };
    //-------------------------------------------------------------------------------
    template <typename T>
    void TSceneCacheManager::Add(const std::string& guid, T* p)
    {
        mScenes.insert({ guid, p });
    }
    //-------------------------------------------------------------------------------
    template <typename T>
    const T* TSceneCacheManager::Get(const std::string& guid) const
    {
        auto fit = mScenes.find();
        if (fit == mScenes.end()) {
            return nullptr;
        }
        return (const T*)fit->second;
    }
    //-------------------------------------------------------------------------------
}
