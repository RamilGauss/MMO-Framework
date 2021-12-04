/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FeatureTerminatorSystem.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"
#include "LogicModule.h"
#include "Modules.h"

using namespace nsLogicWrapper;

void TFeatureTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TFeatureComponent* pC)
{
    auto copy = *pC;
    auto featureEids = mEntMng->GetByValueCopy(copy);

    auto featureReflection = nsTornadoEngine::Project()->mScenePartAggregator->mFeatures;

    auto logger = GetLogger()->Get(nsTornadoEngine::TTimeSliceEngine::NAME);

    int rtti;
    auto convertResult = featureReflection->mTypeInfo->ConvertNameToType(pC->featureTypeName, rtti);
    if (convertResult == false) {
        logger->WriteF_time("Not converted typename \"%s\"", pC->featureTypeName);
        return;
    }

    if (featureEids.size() == 1) {
        nsTornadoEngine::Modules()->L()->GetWorkSlots()->RemoveFeature(pC->feature);
        featureReflection->mTypeFactory->Delete(pC->feature, rtti);
    }

    pC->feature = nullptr;
}