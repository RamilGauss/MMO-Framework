/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/Logger.h"

#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"

#include "TornadoEngine/Modules/Implementations/LogicModule.h"
#include "TornadoEngine/Modules/Common/Modules.h"

#include "TornadoEngine/ReflectionAggregators/ScenePartReflectionAggregator.h"

#include "TornadoEngine/Features/Logic/End/Terminator/SystemTerminatorSystem.h"

using namespace nsLogicWrapper;

void TSystemTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TSystemComponent* pC)
{
    auto copy = *pC;
    auto featureEids = mEntMng->GetByValueCopy(copy);

    auto featureReflection = nsTornadoEngine::Project()->mScenePartAggregator->mSystems;

    int rtti;
    auto convertResult = featureReflection->mRtti->ConvertNameToType(pC->typeName, rtti);
    if (convertResult == false) {
        nsTornadoEngine::Modules()->CoreLog()->AddWarningEvent("Not converted typename \"{}\"", pC->typeName);
        return;
    }

    if (featureEids.size() == 1) {
        nsTornadoEngine::Modules()->L()->GetWorkSlots()->RemoveSystem(pC->value);
        featureReflection->mTypeFactory->Delete(pC->value, rtti);
    }

    pC->value = nullptr;
}