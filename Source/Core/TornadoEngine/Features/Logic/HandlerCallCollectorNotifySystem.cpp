/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "HandlerCallCollectorNotifySystem.h"
#include "Modules.h"
#include "HandlerCallCollector.h"

using namespace nsLogicWrapper;

void THandlerCallCollectorNotifySystem::Execute()
{
    nsTornadoEngine::Modules()->HandlerCalls()->CallAll();
    nsTornadoEngine::Modules()->HandlerCalls()->Clear();
}