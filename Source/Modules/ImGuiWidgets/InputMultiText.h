/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Unit.h"

#include "CallbackPool.h"

namespace nsImGuiWidgets
{
    class DllExport TInputMultiText : public TUnit
    {
    public:
        std::string GetText();
        void SetText(const std::string& str);

        using TCallback = TCallbackPool<TInputMultiText*>;
        TCallback mTextEditCB;
    protected:
        static const size_t SIZE = 1024 * 4;
        char mValue[SIZE] = {0};

        void RenderInheritance() override final;
    };
}
