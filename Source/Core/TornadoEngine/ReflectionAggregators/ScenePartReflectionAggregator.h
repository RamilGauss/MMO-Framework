/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TornadoEngine/ReflectionAggregators/ComponentReflectionAggregator.h"
#include "TornadoEngine/ReflectionAggregators/HandlerReflectionAggregator.h"
#include "TornadoEngine/ReflectionAggregators/SystemReflectionAggregator.h"
#include "TornadoEngine/ReflectionAggregators/MenuItemReflectionAggregator.h"
#include "TornadoEngine/ReflectionAggregators/ImGuiWidgetsReflectionAggregator.h"

namespace nsTornadoEngine
{
    struct DllExport TScenePartReflectionAggregator
    {
        virtual ~TScenePartReflectionAggregator() {}

        void Init()
        {
            mComponents->Init();
            mHandlers->Init();
            mSystems->Init();
            //mMenuItems->Init();
            mImGuiWidgets->Init();
        }

        TComponentReflectionAggregator* mComponents = nullptr;
        THandlerReflectionAggregator* mHandlers = nullptr;
        TSystemReflectionAggregator* mSystems = nullptr;
        TMenuItemReflectionAggregator* mMenuItems = nullptr;
        TImGuiWidgetsReflectionAggregator* mImGuiWidgets = nullptr;
    };
}
