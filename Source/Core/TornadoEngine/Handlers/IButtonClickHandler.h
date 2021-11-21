/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IHandler.h"

namespace nsGuiWrapper
{
    class DllExport IButtonClickHandler : public nsTornadoEngine::IHandler
    {
        virtual void Handle() = 0;
    };
}