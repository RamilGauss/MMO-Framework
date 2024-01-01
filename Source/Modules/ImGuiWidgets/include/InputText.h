/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Unit.h"
#include "InputTextValue.h"

#include "Base/Common/CallbackPool.h"

namespace nsImGuiWidgets
{
    namespace nsInputText
    {
        static int EditCallback(ImGuiInputTextCallbackData* data);
    }

    class DllExport TInputText : public TUnit, public TInputTextValue
    {
        bool mIsTextEdited = false;

    public:
        using TCallback = TCallbackPool<TInputText*>;

        TCallback mOnTextEditCB;
        TCallback mOnTextEditEndsCB;

    protected:
        void RenderInheritance() override final;

    private:
        friend int nsInputText::EditCallback(ImGuiInputTextCallbackData* data);
        void SetTextEdited();
    };
}
