/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "OnOpenSystemViewerClickHandler.h"


#include "Modules.h"
#include "Gizmo.h"

#include "GraphicEngineModule.h"
#include "UniverseIndexComponent.h"
#include "GraphicEngineContext.h"

using namespace nsTornadoEditor;

void TOnOpenSystemViewerClickHandler::Handle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pC)
{
    auto entMng = nsTornadoEngine::Modules()->EntMng();
    auto universeIndex = entMng->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid)->value;

    auto pCtx = nsTornadoEngine::Modules()->G()->GetContext(universeIndex);

    auto pSystemViewer = nsTornadoEngine::Modules()->Gizmo()->GetSystemViewer();

    ((nsTornadoEngine::TGraphicEngineContext*)(pCtx))->GetGraphicEngineContext()->AddRender(pSystemViewer);
}
