/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "ProtoFrame.h"
#include "Events.h"
#include "CallbackPool.h"

namespace nsImGuiWidgets
{
    class DllExport TFrame : public TProtoFrame
    {
    public:
        TFrame();

    protected:

        void BeginRender() override;
    };
}
