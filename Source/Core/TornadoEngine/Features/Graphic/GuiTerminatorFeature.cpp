/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GuiTerminatorFeature.h"

using namespace nsGraphicWrapper;

void TGuiTerminatorFeature::SetEntMng(nsECSFramework::TEntityManager* entMng)
{
    TFeature::SetEntMng(entMng);

    Add(&mButtonTerminatorSystem);
    Add(&mWindowTerminatorSystem);
    Add(&mButtonClickHandlerTerminatorSystem);
}
