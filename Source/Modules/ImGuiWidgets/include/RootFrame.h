/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "GraphicEngine/Events.h"

#include "Frame.h"
#include "Base/Common/CallbackPool.h"

namespace nsImGuiWidgets
{
    class DllExport TRootFrame : public TFrame
    {
    public:
        TRootFrame();

    protected:

        void BeforeBeginRender();
    };
}
