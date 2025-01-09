/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "LocalHandlerTerminatorSystem.h"
#include "TimeSliceEngine/ProjectConfigContainer.h"
#include "Base/Common/Logger.h"
#include "Modules/Implementations/LogicModule.h"
#include "Modules/Common/Modules.h"
#include "ReflectionAggregators/ScenePartReflectionAggregator.h"

using namespace nsLogicWrapper;

void TLocalHandlerTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TLocalHandlerComponent* pC)
{
    auto copy = *pC;
    auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

    int rtti;
    auto convertResult = handlerReflection->mRtti->ConvertNameToType(pC->handlerTypeName, rtti);
    if (convertResult == false) {
        nsTornadoEngine::Modules()->Log()->AddWarningEvent("Not converted typename \"{}\"", pC->handlerTypeName);
        return;
    }

    handlerReflection->mTypeFactory->Delete(pC->handler, rtti);

    pC->handler = nullptr;
}
