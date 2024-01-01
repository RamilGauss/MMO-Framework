/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SystemTerminatorSystem.h"
#include "ProjectConfigContainer.h"
#include "Base/Common/Logger.h"
#include "EngineLogger.h"
#include "LogicModule.h"
#include "Modules.h"

#include "ScenePartReflectionAggregator.h"

using namespace nsLogicWrapper;

void TSystemTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TSystemComponent* pC)
{
    auto copy = *pC;
    auto featureEids = mEntMng->GetByValueCopy(copy);

    auto featureReflection = nsTornadoEngine::Project()->mScenePartAggregator->mSystems;

    int rtti;
    auto convertResult = featureReflection->mRtti->ConvertNameToType(pC->typeName, rtti);
    if (convertResult == false) {
        nsTornadoEngine::Modules()->Log()->Log("Not converted typename \"%s\"", pC->typeName);
        return;
    }

    if (featureEids.size() == 1) {
        nsTornadoEngine::Modules()->L()->GetWorkSlots()->RemoveSystem(pC->value);
        featureReflection->mTypeFactory->Delete(pC->value, rtti);
    }

    pC->value = nullptr;
}