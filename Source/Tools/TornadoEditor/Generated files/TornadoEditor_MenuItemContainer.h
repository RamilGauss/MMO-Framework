/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "MenuItemContainer.h"

namespace nsTornadoEditor
{
    struct DllExport TTornadoEditor_MenuItemContainer : public nsTornadoEngine::TMenuItemContainer
    {
        TTornadoEditor_MenuItemContainer();
        virtual ~TTornadoEditor_MenuItemContainer();
    };
}