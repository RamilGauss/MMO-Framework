/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InitSystem.h"

#include "NameComponent.h"


class TMyInitSystem : public nsECSFramework::TInitSystem
{
public:
    void Init() override
    {
        auto eid = mEntMng->CreateEntity();

        TNameComponent nameComponent;
        nameComponent.name = "42";
        mEntMng->SetComponent(eid, nameComponent);
    }
};
