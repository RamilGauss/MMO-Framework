/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FeatureMakerSystem.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"

using namespace nsLogicWrapper;

void TFeatureMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TFeatureComponent* pC)
{
    auto copy = *pC;
    auto featureEids = mEntMng->GetByValueCopy(copy);

    for (auto& featureEid : featureEids) {
        auto featureComponent = mEntMng->ViewComponent<nsLogicWrapper::TFeatureComponent>(featureEid);
        if (featureComponent == nullptr) {
            continue;
        }

        if (featureComponent->feature == nullptr) {
            continue;
        }

        pC->feature = featureComponent->feature;
        return;
    }

    auto featureReflection = nsTornadoEngine::Project()->mScenePartAggregator->mFeatures;

    auto logger = GetLogger()->Get(nsTornadoEngine::TTimeSliceEngine::NAME);

    int rtti;
    auto convertResult = featureReflection->mTypeInfo->ConvertNameToType(pC->featureTypeName, rtti);
    if (convertResult == false) {
        logger->WriteF_time("Not converted typename \"%s\"", pC->featureTypeName);
        return;
    }
    pC->feature = (nsECSFramework::TFeature*) (featureReflection->mTypeFactory->New(rtti));
}