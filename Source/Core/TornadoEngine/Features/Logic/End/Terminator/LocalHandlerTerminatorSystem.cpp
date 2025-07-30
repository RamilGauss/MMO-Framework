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

#include "TornadoEngine/Features/Logic/End/Terminator/LocalHandlerTerminatorSystem.h"

using namespace nsLogicWrapper;

void TLocalHandlerTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TLocalHandlerComponent* pC)
{
    auto copy = *pC;
    auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

    int rtti;
    auto convertResult = handlerReflection->mRtti->ConvertNameToType(pC->handlerTypeName, rtti);
    if (convertResult == false) {
        nsTornadoEngine::Modules()->CoreLog()->AddWarningEvent("Not converted typename \"{}\"", pC->handlerTypeName);
        return;
    }

    handlerReflection->mTypeFactory->Delete(pC->handler, rtti);

    pC->handler = nullptr;
}
