/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MainWindowBuilderSystem.h"

#include <ImGuiWidgets/include/MainWindow.h>

#include "Modules.h"
#include "GraphicEngineModule.h"

using namespace nsGraphicWrapper;

void TMainWindowBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMainWindowComponent* pMainWindowComponent)
{
    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(pMainWindowComponent->value);
}
