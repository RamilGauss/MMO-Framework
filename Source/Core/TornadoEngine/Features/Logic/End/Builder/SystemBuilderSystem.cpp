/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SystemBuilderSystem.h"

#include "Modules/Common/Modules.h"
#include "Modules/Implementations/LogicModule.h"

using namespace nsLogicWrapper;

void TSystemBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TSystemComponent* pC)
{
    auto slot = nsTornadoEngine::Modules()->L()->GetWorkSlots();

    if (slot->HasSystem(pC->value)) {
        return;
    }

    slot->AddSystem(pC->value);
}