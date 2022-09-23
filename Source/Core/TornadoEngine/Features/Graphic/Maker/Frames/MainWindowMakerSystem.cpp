/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MainWindowMakerSystem.h"

#include <ImGuiWidgets/include/MainWindow.h>

using namespace nsGraphicWrapper;

void TMainWindowMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMainWindowComponent* pMainWindowComponent)
{
    pMainWindowComponent->value = new nsImGuiWidgets::TMainWindow();
}
