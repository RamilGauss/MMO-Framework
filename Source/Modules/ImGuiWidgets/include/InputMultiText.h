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
    namespace nsInputMultiText
    {
        static int EditCallback(ImGuiInputTextCallbackData* data);
    }

    class DllExport TInputMultiText : public TUnit, public TInputTextValue
    {
        bool mIsTextEdited = false;
    public:
        using TCallback = TCallbackPool<TInputMultiText*>;
        TCallback mOnTextEditCB;
        TCallback mOnTextEditEndsCB;
    protected:
        void RenderInheritance() override final;

    private:
        friend int nsInputMultiText::EditCallback(ImGuiInputTextCallbackData* data);
        void SetTextEdited();
    };
}
