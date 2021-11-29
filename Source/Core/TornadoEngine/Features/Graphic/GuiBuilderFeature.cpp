/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GuiBuilderFeature.h"

using namespace nsGraphicWrapper;

void TGuiBuilderFeature::SetEntMng(nsECSFramework::TEntityManager* entMng)
{
    TFeature::SetEntMng(entMng);

    Add(&mButtonBuilderSystem);
    Add(&mWindowBuilderSystem);
    Add(&mButtonClickHandlerBuilderSystem);
}
