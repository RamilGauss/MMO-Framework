/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"
#include "ECS/include/EntityManager.h"

namespace nsShareDev
{
    class DllExport IEntityManagerExtension
    {
    protected:
        nsECSFramework::TEntityManager* mEntMng = nullptr;
    public:
        void SetEntityManager(nsECSFramework::TEntityManager* pEntMng) { mEntMng = pEntMng; }

        virtual void SetComponent(nsECSFramework::TEntityID eid, void* p, const std::string& typeName) = 0;
        virtual void* ViewComponent(nsECSFramework::TEntityID eid, const std::string& typeName) = 0;
        virtual bool GetComponent(nsECSFramework::TEntityID eid, void*& p, const std::string& typeName) = 0;
        virtual bool HasComponent(nsECSFramework::TEntityID eid, const std::string& typeName) = 0;
        virtual void RemoveComponent(nsECSFramework::TEntityID eid, const std::string& typeName) = 0;

        virtual void SetComponent(nsECSFramework::TEntityID eid, void* p, int typeIdentifier) = 0;
        virtual void* ViewComponent(nsECSFramework::TEntityID eid, int typeIdentifier) = 0;
        virtual bool GetComponent(nsECSFramework::TEntityID eid, void*& p, int typeIdentifier) = 0;
        virtual bool HasComponent(nsECSFramework::TEntityID eid, int typeIdentifier) = 0;
        virtual void RemoveComponent(nsECSFramework::TEntityID eid, int typeIdentifier) = 0;
    };
}