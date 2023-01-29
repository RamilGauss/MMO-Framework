/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>
#include <map>
#include <vector>

#include "TypeDef.h"
#include <ECS/include/EntityManager.h>

#include "Archetype.h"
#include "RelativeProperties.h"

namespace nsTornadoEngine
{
    class DllExport TPropertyManager
    {
        std::unordered_map<std::string, TArchetype> mTypeNameDeps;

        TRelativeProperties mRelativeProperties;

    public:
        void Init();

        void SetupProperties(nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid,
            const std::string& typeName, void* pObject);

    protected:

        void GetDownCasters(const std::string& typeName, std::list<std::string>& downCasters) const;
        void GetProperties(const std::string& typeName, TRelativeProperties& properties) const;
    };
}