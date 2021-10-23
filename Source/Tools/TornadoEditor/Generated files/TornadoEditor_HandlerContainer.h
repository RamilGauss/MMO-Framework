/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "HandlerContainer.h"

namespace nsTornadoEditor
{
    struct DllExport TTornadoEditor_HandlerContainer : public nsTornadoEngine::THandlerContainer
    {
        TTornadoEditor_HandlerContainer();
        virtual ~ TTornadoEditor_HandlerContainer();
    };
}