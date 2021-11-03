/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include "Unit.h"
#include "CallbackPool.h"

namespace nsImGuiWidgets
{
    class DllExport TCheckBox : public TUnit
    {
    protected:
        bool mValue = false;
    public:
        bool GetValue();
        void SetValue(bool value);

        using TCheckChange = TCallbackPool<bool>;
        TCheckChange mOnCheckChangeCB;

    protected:
        void RenderInheritance() override final;
    };
}
