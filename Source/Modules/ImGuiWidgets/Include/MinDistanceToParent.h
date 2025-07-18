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
    struct DllExport TMinDistanceToParent
    {
    public:
        virtual void SetLeftMinDistance(int value);
        virtual void SetTopMinDistance(int value);
        virtual void SetRightMinDistance(int value);
        virtual void SetBottomMinDistance(int value);

        virtual int GetLeftMinDistance() const;
        virtual int GetTopMinDistance() const;
        virtual int GetRightMinDistance() const;
        virtual int GetBottomMinDistance() const;
    private:
        int mTop = 0;
        int mLeft = 0;
        int mBottom = 0;
        int mRight = 0;
    };
}
