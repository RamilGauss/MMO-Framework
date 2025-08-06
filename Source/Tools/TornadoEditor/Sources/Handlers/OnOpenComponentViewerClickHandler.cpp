/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Gizmos/Gizmo.h"
#include "TornadoEngine/Modules/Implementations/GraphicEngineModule.h"

#include "TornadoEngine/Components/Meta/UniverseIndexComponent.h"
#include "TornadoEngine/Modules/Contexts/GraphicEngineContext.h"

#include "TornadoEditor/Sources/Handlers/OnOpenComponentViewerClickHandler.h"

using namespace nsTornadoEditor;

void TOnOpenComponentViewerClickHandler::Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pC)
{
    auto entMng = nsTornadoEngine::Modules()->EntMng();
    auto universeIndex = entMng->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid)->value;

    auto pCtx = nsTornadoEngine::Modules()->G()->GetContext(universeIndex);

    auto pComponentViewer = nsTornadoEngine::Modules()->Gizmo()->GetComponentViewer();

    ((nsTornadoEngine::TGraphicEngineContext*)(pCtx))->GetGraphicEngineContext()->AddRender(pComponentViewer);
}
