/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FrameMouseMoveHandlerMakerSystem.h"
#include "Modules.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "EngineLogger.h"

using namespace nsGraphicWrapper;

void TFrameMouseMoveHandlerMakerSystem::Reactive(nsECSFramework::TEntityID eid,
    const nsGuiWrapper::TFrameMouseMoveHandlerComponent* pFrameMouseMoveHandlerComponent)
{
    auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

    int rtti;
    auto convertResult = handlerReflection->mTypeInfo->ConvertNameToType(pFrameMouseMoveHandlerComponent->handlerTypeName, rtti);
    if (convertResult == false) {
        nsTornadoEngine::TEngineLogger::Log("Not converted typename \"%s\"", pFrameMouseMoveHandlerComponent->handlerTypeName);
        return;
    }
    pFrameMouseMoveHandlerComponent->handler = (nsGuiWrapper::IFrameMouseMoveHandler*) (handlerReflection->mTypeFactory->New(rtti));
}
