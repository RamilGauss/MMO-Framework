/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FrameKeyHandlerMakerSystem.h"
#include "Modules.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "EngineLogger.h"

using namespace nsGraphicWrapper;

void TFrameKeyHandlerMakerSystem::Reactive(nsECSFramework::TEntityID eid,
    const nsGuiWrapper::TFrameKeyHandlerComponent* pFrameKeyHandlerComponent)
{
    auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

    int rtti;
    auto convertResult = handlerReflection->mTypeInfo->ConvertNameToType(pFrameKeyHandlerComponent->handlerTypeName, rtti);
    if (convertResult == false) {
        nsTornadoEngine::TEngineLogger::Log("Not converted typename \"%s\"", pFrameKeyHandlerComponent->handlerTypeName);
        return;
    }
    pFrameKeyHandlerComponent->handler = (nsGuiWrapper::IFrameKeyHandler*) (handlerReflection->mTypeFactory->New(rtti));
}
