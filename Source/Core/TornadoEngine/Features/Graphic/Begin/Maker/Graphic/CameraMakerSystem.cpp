/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/Maker/Graphic/CameraMakerSystem.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Implementations/GraphicEngineModule.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TCameraMakerSystem::Reactive(nsECSFramework::TEntityID eid, const TCameraComponent* pCameraComponent)
{
    auto universeIndex = GetEntMng()->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid)->value;
    auto pCtx = (nsTornadoEngine::TGraphicEngineContext*)(nsTornadoEngine::Modules()->G()->GetContext(universeIndex));
    pCameraComponent->value = pCtx->GetGraphicEngineContext()->CreateCamera();
}
