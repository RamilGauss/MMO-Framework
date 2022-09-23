/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CleanUpUniverseContextSystem.h"

#include "Modules.h"
#include "GraphicEngineModule.h"

using namespace nsGraphicWrapper;

void TCleanUpUniverseContextSystem::Execute()
{
    nsTornadoEngine::Modules()->G()->CleanUp();
}