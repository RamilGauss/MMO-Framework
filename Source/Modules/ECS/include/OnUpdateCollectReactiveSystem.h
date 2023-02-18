/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "BaseCollectReactiveSystem.h"

namespace nsECSFramework
{
    template <typename Component, typename SystemTypeImplementation>
    class DllExport TOnUpdateCollectReactiveSystem : public TBaseCollectReactiveSystem
    {
    public:
        void TearDown() override final
        {
            if (mReactiveId != -1) {
                mEntMng->UnregisterOnUpdateCollectorComponent<Component>(mReactiveId);
            }
        }

        void SetEntMng(TEntityManager* entMng) override final
        {
            TSystem::SetEntMng(entMng);

            mReactiveId = mEntMng->RegisterOnUpdateCollectorComponent<Component>();
        }

        void ClearEvents() override final
        {
            mEntMng->ClearUpdateEvents<Component>(mReactiveId);
        }

        void Execute() override final
        {
            auto& events = *(mEntMng->GetUpdateEvents<Component>(mReactiveId));
            if (events.size() == 0) {
                return;
            }

            for (auto& event : events) {
                auto hasComponent = mEntMng->HasComponent<Component>(event.eid);
                if (hasComponent) {
                    ((SystemTypeImplementation*) this)->Reactive(event.eid, (const Component*) event.pComponent);
                }
            }

            mEntMng->ClearUpdateEvents<Component>(mReactiveId);
        }
    };
}
