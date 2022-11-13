/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ObjectInstantiationCompletionHandlerTerminatorSystem.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"
#include "LogicModule.h"
#include "Modules.h"

using namespace nsLogicWrapper;

void TObjectInstantiationCompletionHandlerTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent* pC)
{
    auto copy = *pC;
    auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

    auto logger = GetLogger()->Get(nsTornadoEngine::TTimeSliceEngine::NAME);

    int rtti;
    auto convertResult = handlerReflection->mTypeInfo->ConvertNameToType(pC->handlerTypeName, rtti);
    if (convertResult == false) {
        logger->WriteF_time("Not converted typename \"%s\"", pC->handlerTypeName);
        return;
    }

    handlerReflection->mTypeFactory->Delete(pC->handler, rtti);

    pC->handler = nullptr;
}