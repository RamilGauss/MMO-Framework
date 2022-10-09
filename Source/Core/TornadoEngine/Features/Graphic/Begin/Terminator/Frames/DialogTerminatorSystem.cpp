/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DialogTerminatorSystem.h"
#include "Modules.h"
#include "GraphicEngineModule.h"

#include <ImGuiWidgets/include/Dialog.h>

using namespace nsGraphicWrapper;

void TDialogTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogComponent* pDialogComponent)
{
    auto universeIndex = GetEntMng()->ViewComponent<nsCommonWrapper::TUniverseIndexComponent>(eid)->value;

    auto pContext = (nsTornadoEngine::TGraphicEngineContext*)(nsTornadoEngine::Modules()->G()->GetContext(universeIndex));

    auto dialogStack = pContext->GetDialogStack();
    dialogStack->Remove(pDialogComponent->value);

    delete pDialogComponent->value;
    pDialogComponent->value = nullptr;
}
