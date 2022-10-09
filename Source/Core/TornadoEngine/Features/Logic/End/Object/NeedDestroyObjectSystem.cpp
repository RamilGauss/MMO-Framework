/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "NeedDestroyObjectSystem.h"

using namespace nsLogicWrapper;

void TNeedDestroyObjectSystem::Reactive(nsECSFramework::TEntityID eid,
    const nsCommonWrapper::TNeedDestroyObjectTagComponent* pC)
{
    GetEntMng()->DestroyEntity(eid);
}
