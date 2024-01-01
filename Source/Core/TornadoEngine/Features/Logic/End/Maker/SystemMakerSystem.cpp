/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SystemMakerSystem.h"
#include "ProjectConfigContainer.h"
#include "Modules.h"
#include "Base/Common/Logger.h"
#include "EngineLogger.h"
#include "ScenePartReflectionAggregator.h"

using namespace nsLogicWrapper;

void TSystemMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TSystemComponent* pC)
{
    auto copy = *pC;
    auto systemEids = mEntMng->GetByValueCopy(copy);

    for (auto& systemEid : systemEids) {
        auto systemComponent = mEntMng->ViewComponent<nsLogicWrapper::TSystemComponent>(systemEid);
        if (systemComponent == nullptr) {
            continue;
        }

        if (systemComponent->value == nullptr) {
            continue;
        }

        pC->value = systemComponent->value;
        return;
    }

    auto systemReflection = nsTornadoEngine::Project()->mScenePartAggregator->mSystems;

    int rtti;
    auto convertResult = systemReflection->mRtti->ConvertNameToType(pC->typeName, rtti);
    if (convertResult == false) {
        nsTornadoEngine::Modules()->Log()->Log("Not converted typename \"%s\"", pC->typeName);
        return;
    }

    auto newSystem = systemReflection->mTypeFactory->New(rtti);

    auto systemRtti = SingletonManager()->Get<TRunTimeTypeIndex<>>()->Type<nsECSFramework::TSystem>();

    pC->value = (nsECSFramework::TSystem*) systemReflection->mDynamicCaster->Cast(rtti, newSystem, systemRtti);//!!!
}
