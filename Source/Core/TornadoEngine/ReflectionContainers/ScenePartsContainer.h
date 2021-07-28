/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ComponentsContainer.h"
#include "HandlersContainer.h"
#include "FeaturesContainer.h"
#include "MenuItemsContainer.h"

namespace nsTornadoEngine
{
    struct DllExport TScenePartsContainer
    {
        TComponentsContainer* mComponentsContainer = nullptr;
        THandlersContainer* mHandlersContainer = nullptr;
        TFeaturesContainer* mFeaturesContainer = nullptr;
        TMenuItemsContainer* mMenuItemsContainer = nullptr;
    };
}