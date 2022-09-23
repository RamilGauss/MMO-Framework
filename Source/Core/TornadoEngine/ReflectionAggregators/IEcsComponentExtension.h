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

namespace nsTornadoEngine
{
    class DllExport IEcsComponentExtension
    {
    protected:
        nsECSFramework::TEntityManager* mEntMng = nullptr;
    public:
        virtual ~IEcsComponentExtension() {}

        void SetEntityManager(nsECSFramework::TEntityManager* pEntMng) { mEntMng = pEntMng; }
        nsECSFramework::TEntityManager* GetEntityManager() { return mEntMng; }

        virtual void CreateComponent(nsECSFramework::TEntityID eid, int rtti, 
            std::function<void(void*)> onAfterCreation, bool isNotify = true) = 0;
        virtual void SetComponent(nsECSFramework::TEntityID eid, int rtti, 
            void* p, bool isNotify = true) = 0;
        virtual const void* ViewComponent(nsECSFramework::TEntityID eid, int rtti) = 0;
        virtual bool HasComponent(nsECSFramework::TEntityID eid, int rtti) = 0;
        virtual void RemoveComponent(nsECSFramework::TEntityID eid, int rtti) = 0;
    };
}