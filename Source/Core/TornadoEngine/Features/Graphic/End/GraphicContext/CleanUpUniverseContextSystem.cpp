/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Features/Graphic/End/GraphicContext/CleanUpUniverseContextSystem.h"

#include "Modules/Common/Modules.h"
#include "Modules/Implementations/GraphicEngineModule.h"

using namespace nsGraphicWrapper;

void TCleanUpUniverseContextSystem::Execute()
{
    nsTornadoEngine::Modules()->G()->CleanUp();
}