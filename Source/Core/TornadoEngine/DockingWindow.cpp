/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DockingWindow.h"

#include "Modules.h"
#include "ModuleGraphicEngine.h"
#include "StopAccessor.h"

using namespace nsTest;

TDockingWindow::TDockingWindow(std::string name)
{
    mWindow.SetTitle(name.c_str());
    mWindow.SetSize({300, 300});
    mWindow.SetPos({20, 20});

    nsTornadoEngine::Modules()->G()->GetGE()->AddRender(&mWindow);
}
//--------------------------------------------------------------------------------------------------------
