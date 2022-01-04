/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Frame.h"

namespace nsImGuiWidgets
{
    class TDialogStack;
    class DllExport TDialog : public TFrame
    {
        bool mLastIsShown = false;

        TDialogStack* mDialogStack = nullptr;
    public:
        using TShowCallback = TCallbackPool<bool>;

        TShowCallback mOnShowCB;

        void SetStack(TDialogStack* pDialogStack);

    protected:
        void BeginRender() override;
        void EndRender() override;
    };
}
