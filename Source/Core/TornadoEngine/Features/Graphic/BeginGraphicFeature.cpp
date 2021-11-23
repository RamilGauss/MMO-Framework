/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BeginGraphicFeature.h"

using namespace nsGraphicWrapper;

void TBeginGraphicFeature::SetEntMng(nsECSFramework::TEntityManager* entMng)
{
    TFeature::SetEntMng(entMng);

    Add(&mGuiMakerFeature);
    Add(&mGuiBuilderFeature);
}