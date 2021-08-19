/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include "Frame.h"

namespace nsImGuiWidgets
{
    class DllExport TWindow : public TFrame
    {
        ImVec2 mOldSize;
        ImVec2 mOldPos;

    public:
        using TShowCallback = TCallbackPool<bool>;
        using TSizeCallback = TCallbackPool<const ImVec2*>;
        using TPositionCallback = TCallbackPool<const ImVec2*>;

        TShowCallback mShowCB;
        TSizeCallback mSizeCB;
        TPositionCallback mPosCB;
    protected:
        void BeginRender() override;
        void EndRender() override;
    };
}
