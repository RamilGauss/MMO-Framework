/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/TextFile.h"

#include "TornadoEngine/Modules/PropertyManager/PropertyManager.h"
#include "TornadoEngine/Modules/PropertyManager/PropertyManagerConfigs.h"

namespace nsTornadoEngine
{
    void TPropertyManager::Init()
    {
        std::list<TArchetype> archetypes;
        TPropertyManagerConfigs::GetArchetypes(archetypes);

        for (auto& archetype : archetypes) {
            mTypeNameDeps.insert({ archetype.typeName, archetype });
        }

        TPropertyManagerConfigs::GetRelativeProperties(mRelativeProperties);
    }
    //-------------------------------------------------------------------------------------------
    void TPropertyManager::GetDownCasters(const std::string& typeName, std::list<std::string>& downCasters) const
    {
        auto fit = mTypeNameDeps.find(typeName);

        if (fit == mTypeNameDeps.end()) {
            return;
        }

        downCasters.push_back(fit->second.typeName);

        for (auto& parentName : fit->second.parentNames) {
            GetDownCasters(parentName, downCasters);
        }
    }
    //-------------------------------------------------------------------------------------------
    void TPropertyManager::GetProperties(const std::string& typeName, std::list<std::string>& properties) const
    {
        auto fit = mTypeNameDeps.find(typeName);

        if (fit == mTypeNameDeps.end()) {
            return;
        }

        properties = fit->second.properties;
    }
    //-------------------------------------------------------------------------------------------
}