/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "OnAddUniverseContextSystem.h"

#include "Modules.h"
#include "GraphicEngineModule.h"

using namespace nsGraphicWrapper;

void TOnAddUniverseContextSystem::Reactive(nsECSFramework::TEntityID eid, const nsCommonWrapper::TUniverseIndexComponent* pC)
{
    nsTornadoEngine::Modules()->G()->TryAdd(pC->value);
}