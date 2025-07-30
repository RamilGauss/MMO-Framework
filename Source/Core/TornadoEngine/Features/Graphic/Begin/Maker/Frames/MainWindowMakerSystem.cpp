/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/MainWindow.h"

#include "TornadoEngine/Features/Graphic/Begin/Maker/Frames/MainWindowMakerSystem.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/PropertyManager/PropertyManager.h"

using namespace nsGraphicWrapper;

void TMainWindowMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMainWindowComponent* pMainWindowComponent)
{
    auto pMainWindow = new nsImGuiWidgets::TMainWindow();
    pMainWindowComponent->value = pMainWindow;

    nsTornadoEngine::Modules()->PropertyMng()->SetupProperties(GetEntMng(), eid, pMainWindow);
}
