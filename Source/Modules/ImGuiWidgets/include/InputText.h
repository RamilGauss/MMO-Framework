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
    class DllExport TInputText : public TUnit
    {
        bool mIsTextEdited = false;

    public:
        std::string GetText();
        void SetText(const std::string& str);

        using TCallback = TCallbackPool<TInputText*>;

        TCallback mOnTextEditCB;
        TCallback mOnTextEditEndsCB;

        void SetTextEdited();
    protected:
        static const size_t SIZE = 1024 * 4;// TODO: use std::vector
        char mValue[SIZE] = {0};

        void RenderInheritance() override final;
    };
}
