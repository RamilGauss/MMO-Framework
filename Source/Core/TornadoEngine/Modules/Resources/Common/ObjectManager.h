/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"
#include "Base/Common/GuidGenerator.h"

#include "ECS/Include/EntityManager.h"

#include "TornadoEngine/Modules/Resources/Common/ResourceContentMap.h"
#include "TornadoEngine/Modules/Resources/Common/GuidConstants.h"

#include "TornadoEngine/Components/Meta/ParentGuidComponent.h"
#include "TornadoEngine/Components/Meta/GuidComponent.h"

#include "TornadoEngine/Modules/Resources/Common/EntityContent.h"

#include "TornadoEngine/Modules/Resources/Common/ResourceManager.h"

namespace nsTornadoEngine
{
    class DllExport TObjectManager : public TResourceManager
    {
    protected:
        nsECSFramework::TEntityManager* mEntityManager = nullptr;
    public:
        void SetEntityManager(nsECSFramework::TEntityManager* entMng);

        // Каскадное уничтожение детей, только для редактирования префабов и сцен
        // доступ только в редакторе!
        void DestroyObject(const std::string& guid);
    };
}
