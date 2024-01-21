/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GuiCameraBuilderSystem.h"

#include "Modules/Common/Modules.h"
#include "Modules/Implementations/GraphicEngineModule.h"

#include "Components/Graphic/CameraComponent.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TGuiCameraBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const TGuiCameraTagComponent* pGuiCameraTagComponent)
{
    auto universeIndex = GetEntMng()->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid)->value;
    auto pCtx = (nsTornadoEngine::TGraphicEngineContext*)(nsTornadoEngine::Modules()->G()->GetContext(universeIndex));
    auto pCamera = GetEntMng()->ViewComponent<nsGraphicWrapper::TCameraComponent>(eid)->value;
    
    pCtx->GetGraphicEngineContext()->SetGuiCamera(pCamera);
}
