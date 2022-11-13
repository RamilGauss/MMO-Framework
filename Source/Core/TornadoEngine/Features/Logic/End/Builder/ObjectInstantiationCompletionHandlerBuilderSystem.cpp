/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ObjectInstantiationCompletionHandlerBuilderSystem.h"

#include "Modules.h"
#include "LogicModule.h"
#include "HandlerCallCollector.h"

using namespace nsLogicWrapper;

void TObjectInstantiationCompletionHandlerBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent* pC)
{
    auto handler = pC->handler;
    if (handler == nullptr) {
        return;
    }

    auto handlerCallCollector = nsTornadoEngine::Modules()->HandlerCalls();

    handlerCallCollector->Add([handler, eid]()
    {
        handler->Handle(eid);
    });
}