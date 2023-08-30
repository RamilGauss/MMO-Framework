/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include "SceneInstanceState.h"

namespace nsTornadoEngine
{
    class DllExport TSceneInstanceLoader
    {
    public:
        static void AsyncWork(TSceneInstanceState* pSceneInstanceState);

        static void SyncWork(TSceneInstanceState* pSceneInstanceState, int maxDuration);
    };
}
