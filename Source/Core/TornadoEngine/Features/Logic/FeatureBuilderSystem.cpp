/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FeatureBuilderSystem.h"

#include "Modules.h"
#include "LogicModule.h"

using namespace nsLogicWrapper;

void TFeatureBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TFeatureComponent* pC)
{
    auto slot = nsTornadoEngine::Modules()->L()->GetWorkSlots();

    if (slot->HasFeature(pC->feature)) {
        return;
    }

    slot->AddFeature(pC->feature);
}