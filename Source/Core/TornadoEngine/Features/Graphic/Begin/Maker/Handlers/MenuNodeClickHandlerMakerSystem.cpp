/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MenuNodeClickHandlerMakerSystem.h"
#include "Modules.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "EngineLogger.h"

using namespace nsGraphicWrapper;

void TMenuNodeClickHandlerMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeClickHandlerComponent* pMenuNodeClickHandlerComponent)
{
    auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

    int rtti;
    auto convertResult = handlerReflection->mTypeInfo->ConvertNameToType(pMenuNodeClickHandlerComponent->handlerTypeName, rtti);
    if (convertResult == false) {
        nsTornadoEngine::TEngineLogger::Log("Not converted typename \"%s\"", pMenuNodeClickHandlerComponent->handlerTypeName);
        return;
    }
    pMenuNodeClickHandlerComponent->handler = (nsGuiWrapper::IMenuNodeClickHandler*) (handlerReflection->mTypeFactory->New(rtti));
}
