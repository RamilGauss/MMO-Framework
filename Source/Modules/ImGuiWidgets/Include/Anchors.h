/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

namespace nsImGuiWidgets
{
    class DllExport TAnchors
    {
    public:
        struct DllExport TAnchor
        {
            bool isUsed = false;
            int offset = 0;
        };

        bool IsAnyAnchor() const;

        TAnchor GetLeftAnchor() const;
        TAnchor GetRightAnchor() const;
        TAnchor GetTopAnchor() const;
        TAnchor GetBottomAnchor() const;

        void SetLeftAnchor(const TAnchor& value);
        void SetRightAnchor(const TAnchor& value);
        void SetTopAnchor(const TAnchor& value);
        void SetBottomAnchor(const TAnchor& value);
    private:
        TAnchor mLeftAnchor;
        TAnchor mRightAnchor;
        TAnchor mTopAnchor;
        TAnchor mBottomAnchor;
    };
}
