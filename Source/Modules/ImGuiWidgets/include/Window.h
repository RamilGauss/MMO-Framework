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
    class TDockTreeManager;

    class DllExport TWindow : public TFrame
    {
    public:
        using TShowCallback = TCallbackPool<bool>;

        TShowCallback mOnShowCB;
    protected:
        void BeginRender() override;
        void EndRender() override;
    };
}
