/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#pragma once

#include "TornadoEngine/ReflectionAggregators/ScenePartReflectionAggregator.h"

namespace nsGuiProject
{
    struct DllExport TScenePartReflectionAggregatorImpl : public nsTornadoEngine::TScenePartReflectionAggregator
    {
        TScenePartReflectionAggregatorImpl();
        virtual ~TScenePartReflectionAggregatorImpl();
    };
}
