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
    protected:
        ImGuiID mParentDockId = 0;
        bool mIsDocked = false;


        ImGuiID mNewParentDockId = 0;
        bool mNeedSetParentDockId = false;
    public:
        using TDockCallback = TCallbackPool<>;
        using TShowCallback = TCallbackPool<bool>;
        using TSizeCallback = TCallbackPool<const ImVec2*>;
        using TPositionCallback = TCallbackPool<const ImVec2*>;

        TDockCallback mDockCB;
        TShowCallback mShowCB;
        TSizeCallback mSizeCB;
        TPositionCallback mPosCB;

        ImGuiID GetDockId() const;
        ImGuiID GetParentDockId() const;
        bool IsDocked() const;

        void SetParentDockId(ImGuiID parentId);
    protected:
        void BeginRender() override;
        void EndRender() override;
    };
}
