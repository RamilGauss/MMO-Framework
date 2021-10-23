/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ComponentContainer.h"
#include "HandlerContainer.h"
#include "FeatureContainer.h"
#include "MenuItemContainer.h"

namespace nsTornadoEngine
{
    struct DllExport TScenePartContainer
    {
        virtual ~TScenePartContainer() {}

        TComponentContainer* mComponentContainer = nullptr;
        THandlerContainer* mHandlerContainer = nullptr;
        TFeatureContainer* mFeatureContainer = nullptr;
        TMenuItemContainer* mMenuItemContainer = nullptr;
    };
}