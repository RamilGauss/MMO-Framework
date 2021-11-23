/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GuiMakerFeature.h"

using namespace nsGraphicWrapper;

void TGuiMakerFeature::SetEntMng(nsECSFramework::TEntityManager* entMng)
{
    TFeature::SetEntMng(entMng);

    Add(&mButtonMakerSystem);
    Add(&mWindowMakerSystem);
}
