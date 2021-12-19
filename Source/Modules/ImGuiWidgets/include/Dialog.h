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

        ImVec2 mOldSize;
        ImVec2 mOldPos;

        TDialogStack* mDialogStack = nullptr;
    public:
        using TShowCallback = TCallbackPool<bool>;
        using TSizeCallback = TCallbackPool<const ImVec2*>;
        using TPositionCallback = TCallbackPool<const ImVec2*>;

        TShowCallback mOnShowCB;
        TSizeCallback mOnSizeCB;
        TPositionCallback mOnPosCB;


        void SetStack(TDialogStack* pDialogStack);

    protected:
        void BeginRender() override;
        void EndRender() override;
    };
}
