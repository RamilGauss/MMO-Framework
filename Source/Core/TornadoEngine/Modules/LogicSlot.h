/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include <ECS/include/Feature.h>

namespace nsTornadoEngine
{
    class DllExport TLogicSlot
    {
        nsECSFramework::TEntityManager* mEntMng = nullptr;
        std::list<nsECSFramework::TFeature*> mFeatures;
    public:
        void AddFeature(nsECSFramework::TFeature* p);
        void RemoveFeature(nsECSFramework::TFeature* p);

        void Work();

        const std::list<nsECSFramework::TFeature*>* GetFeatures() const;

        void SetEntMng(nsECSFramework::TEntityManager* pEntMng);
        nsECSFramework::TEntityManager* GetEntMng() const;
    };
}