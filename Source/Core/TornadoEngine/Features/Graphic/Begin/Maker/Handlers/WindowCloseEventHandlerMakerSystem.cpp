/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowCloseEventHandlerMakerSystem.h"
#include "Modules.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "EngineLogger.h"

using namespace nsGraphicWrapper;

void TWindowCloseEventHandlerMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowCloseEventHandlerComponent* pWindowCloseEventHandlerComponent)
{
    auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

    int rtti;
    auto convertResult = handlerReflection->mTypeInfo->ConvertNameToType(pWindowCloseEventHandlerComponent->handlerTypeName, rtti);
    if (convertResult == false) {
        nsTornadoEngine::TEngineLogger::Log("Not converted typename \"%s\"", pWindowCloseEventHandlerComponent->handlerTypeName);
        return;
    }
    pWindowCloseEventHandlerComponent->handler = (nsGuiWrapper::IWindowCloseEventHandler*) (handlerReflection->mTypeFactory->New(rtti));
}
