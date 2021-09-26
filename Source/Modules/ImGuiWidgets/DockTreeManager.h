/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "CallbackPool.h"

#include "IRenderable.h"

namespace nsImGuiWidgets
{
    class TDockNode;

    class DllExport TDockTreeManager : public nsGraphicEngine::IRenderable
    {
        std::list<TDockNode*> mRoots;

    public:
        using TChangeCallback = TCallbackPool<>;

        TChangeCallback mCB;

        TDockTreeManager();

        void Render() override final;
    protected:
    };
}
