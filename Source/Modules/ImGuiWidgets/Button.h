/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Unit.h"

#include <functional>

namespace nsImGuiWidgets
{
    class DllExport TButton : public TUnit
    {
    public:
        using TCallback = std::function<void(TButton*)>;

        void SetCallback(TCallback cb);
    protected:
        void RenderInheritance() override final;

        TCallback mCallback;
    };
}
