/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "CallbackPool.h"

#include "IRenderable.h"

#include "Identity.h"

namespace nsImGuiWidgets
{
    class DllExport TDockNode : public nsGraphicEngine::IRenderable, public TIdentity
    {
    public:
        using TChangeCallback = TCallbackPool<>;

        TChangeCallback mCB;

        TDockNode();

        void Render() override final;
    protected:
    };
}
