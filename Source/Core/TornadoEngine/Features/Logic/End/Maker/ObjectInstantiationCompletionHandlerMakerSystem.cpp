/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ObjectInstantiationCompletionHandlerMakerSystem.h"

#include "SceneInstanceGuidComponent.h"

#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"

using namespace nsLogicWrapper;

void TObjectInstantiationCompletionHandlerMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent* pC)
{
    auto hasSceneInstance = GetEntMng()->HasComponent<nsCommonWrapper::TSceneInstanceGuidComponent>(eid);
    if (!hasSceneInstance) {
        return;
    }

    auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;
    auto logger = GetLogger()->Get(nsTornadoEngine::TTimeSliceEngine::NAME);

    int rtti;
    auto convertResult = handlerReflection->mTypeInfo->ConvertNameToType(pC->handlerTypeName, rtti);
    if (convertResult == false) {
        logger->WriteF_time("Not converted typename \"%s\"", pC->handlerTypeName);
        return;
    }
    pC->handler = (nsLogicWrapper::IObjectInstantiationCompletionHandler*) (handlerReflection->mTypeFactory->New(rtti));
}