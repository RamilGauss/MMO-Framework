/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MainWindowTerminatorSystem.h"
#include "Modules.h"
#include "GraphicEngineModule.h"

#include <ImGuiWidgets/include/MainWindow.h>

using namespace nsGraphicWrapper;

void TMainWindowTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMainWindowComponent* pMainWindowComponent)
{
    nsTornadoEngine::Modules()->G()->GetGE()->RemoveRender(pMainWindowComponent->value);

    delete pMainWindowComponent->value;
    pMainWindowComponent->value = nullptr;
}
