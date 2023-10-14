/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TargetHandlerMakerSystem.h"

#include "ProjectConfigContainer.h"
#include "Modules.h"
#include "Logger.h"
#include "EngineLogger.h"

using namespace nsLogicWrapper;

void TTargetHandlerMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TTargetHandlerComponent* pC)
{
    auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

    int rtti;
    auto convertResult = handlerReflection->mTypeInfo->ConvertNameToType(pC->handlerTypeName, rtti);
    if (convertResult == false) {
        nsTornadoEngine::Modules()->Log()->Log("Not converted typename \"%s\"", pC->handlerTypeName);
        return;
    }
    pC->handler = handlerReflection->mTypeFactory->New(rtti);
}
