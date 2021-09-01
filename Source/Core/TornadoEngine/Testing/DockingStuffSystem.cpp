/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DockingStuffSystem.h"

using namespace nsTest;

void TDockingStuffSystem::Init()
{
    for (int i = 0; i < WIDGET_COUNT; i++) {
        mWindows.push_back(new TDockingStuffWindow(std::to_string(i)));
    }
    mMainWindow = new TMainWindow();
}
