/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/CallbackPool.h"

#include "ImGuiWidgets/Include/Unit.h"

namespace nsImGuiWidgets
{
    class DllExport TButton : public TUnit
    {
    public:
        using TCallback = TCallbackPool<TButton*>;

        TCallback mOnClickCB;
    protected:
        void RenderInheritance() override final;

    };
}
