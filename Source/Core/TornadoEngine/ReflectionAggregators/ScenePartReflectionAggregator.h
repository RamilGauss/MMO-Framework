/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ComponentReflectionAggregator.h"
#include "HandlerReflectionAggregator.h"
#include "FeatureReflectionAggregator.h"
#include "MenuItemReflectionAggregator.h"

namespace nsTornadoEngine
{
    struct DllExport TScenePartReflectionAggregator
    {
        virtual ~TScenePartReflectionAggregator() {}

        TComponentReflectionAggregator* mComponents = nullptr;
        THandlerReflectionAggregator* mHandlers = nullptr;
        TFeatureReflectionAggregator* mFeatures = nullptr;
        TMenuItemReflectionAggregator* mMenuItems = nullptr;
    };
}