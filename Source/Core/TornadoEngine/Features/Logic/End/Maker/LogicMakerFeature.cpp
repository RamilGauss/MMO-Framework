/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Logic/End/Maker/LogicMakerFeature.h"

using namespace nsLogicWrapper;

void TLogicMakerFeature::InitConveyor()
{
    Add(&mSystemMakerSystem);
    Add(&mGlobalHandlerMakerSystem);
    Add(&mLocalHandlerMakerSystem);
}
