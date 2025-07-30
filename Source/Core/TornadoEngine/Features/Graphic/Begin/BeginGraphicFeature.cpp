/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/BeginGraphicFeature.h"

using namespace nsGraphicWrapper;

void TBeginGraphicFeature::InitConveyor()
{
    Add(&mOnAddUniverseContextSystem);

    Add(&mGuiMakerFeature);
    Add(&mGuiBuilderFeature);
    Add(&mGuiTerminatorFeature);
    Add(&mGuiUpdaterToModuleFeature);
}
