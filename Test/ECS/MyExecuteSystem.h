/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <fmt/core.h>

#include "ExecuteSystem.h"

#include "NameComponent.h"

class TMyExecuteSystem : public nsECSFramework::TExecuteSystem
{
    int mCounter = 0;
public:
    void Execute() override
    {
        if (mCounter == 2) {
            auto nameList = *(mEntMng->GetByHas<TNameComponent>());
            for (auto& eid : nameList) {
                mEntMng->RemoveComponent<TNameComponent>(eid);
            }
        } else {
            auto& nameList = *(mEntMng->GetByHas<TNameComponent>());
            for (auto& eid : nameList) {
                auto nameComponent = mEntMng->ViewComponent<TNameComponent>(eid);

                nameComponent->name = fmt::format("{}", mCounter);

                mEntMng->UpdateComponent(eid, nameComponent);
            }
        }

        mCounter++;
    }
};
