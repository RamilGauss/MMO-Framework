/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SceneInstantiatingSystem.h"

#include "Modules/Common/Modules.h"
#include "Modules/Common/ModuleManager.h"

using namespace nsTornadoEngine;

namespace nsLogicWrapper
{
    void TSceneInstantiatingSystem::Execute()
    {
        Modules()->SceneMng()->Work();
    }
}
