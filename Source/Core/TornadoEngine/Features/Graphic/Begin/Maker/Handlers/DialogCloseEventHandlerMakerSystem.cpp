/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DialogCloseEventHandlerMakerSystem.h"
#include "Modules.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"
#include "EngineLogger.h"

using namespace nsGraphicWrapper;

void TDialogCloseEventHandlerMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogCloseEventHandlerComponent* pDialogCloseEventHandlerComponent)
{
    auto handlerReflection = nsTornadoEngine::Project()->mScenePartAggregator->mHandlers;

    int rtti;
    auto convertResult = handlerReflection->mTypeInfo->ConvertNameToType(pDialogCloseEventHandlerComponent->handlerTypeName, rtti);
    if (convertResult == false) {
        nsTornadoEngine::TEngineLogger::Log("Not converted typename \"%s\"", pDialogCloseEventHandlerComponent->handlerTypeName);
        return;
    }
    pDialogCloseEventHandlerComponent->handler = (nsGuiWrapper::IDialogCloseEventHandler*) (handlerReflection->mTypeFactory->New(rtti));
}
