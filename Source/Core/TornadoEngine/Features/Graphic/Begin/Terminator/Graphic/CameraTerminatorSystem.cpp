/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Implementations/GraphicEngineModule.h"

#include "TornadoEngine/Features/Graphic/Begin/Terminator/Graphic/CameraTerminatorSystem.h"

using namespace nsGraphicWrapper;

void TCameraTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGraphicWrapper::TCameraComponent* pCameraComponent)
{
    auto universeIndex = GetEntMng()->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid)->value;
    auto pCtx = (nsTornadoEngine::TGraphicEngineContext*)(nsTornadoEngine::Modules()->G()->GetContext(universeIndex));

    pCtx->GetGraphicEngineContext()->DestroyCamera(pCameraComponent->value);
}
