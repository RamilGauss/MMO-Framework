/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ChooseSystem.h"

using namespace nsTest;

void TChooseSystem::Init()
{
    mWindow = new TChooseWindow("Choose window");

    mInitCB.Notify();
}
//--------------------------------------------------------------------
void TChooseSystem::TearDown()
{
    delete mWindow;
    mWindow = nullptr;
}
//--------------------------------------------------------------------