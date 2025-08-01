/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/UpdateToModule/GuiUpdaterToModuleFeature.h"

using namespace nsGraphicWrapper;

void TGuiUpdaterToModuleFeature::InitConveyor()
{
    Add(&mTitleUpdaterSystem);
    Add(&mInputTextValueUpdaterSystem);
    Add(&mCameraUpdaterToModuleSystem);
}
