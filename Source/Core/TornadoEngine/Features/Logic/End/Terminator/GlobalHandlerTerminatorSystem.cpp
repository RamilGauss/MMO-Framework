/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GlobalHandlerTerminatorSystem.h"
#include "ProjectConfigContainer.h"
#include "Base/Common/Logger.h"
#include "EngineLogger.h"
#include "LogicModule.h"
#include "Modules.h"
#include "ScenePartReflectionAggregator.h"

using namespace nsLogicWrapper;

void TGlobalHandlerTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TGlobalHandlerComponent* pC)
{
    auto copy = *pC;
    auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

    int rtti;
    auto convertResult = handlerReflection->mRtti->ConvertNameToType(pC->handlerTypeName, rtti);
    if (convertResult == false) {
        nsTornadoEngine::Modules()->Log()->Log("Not converted typename \"%s\"", pC->handlerTypeName);
        return;
    }

    handlerReflection->mTypeFactory->Delete(pC->handler, rtti);

    pC->handler = nullptr;
}