/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "CallbackPool.h"

#include "IRenderable.h"
#include "DockTree.h"

namespace nsImGuiWidgets
{
    class DllExport TDockTreeManager : public nsGraphicEngine::IRenderable
    {
        std::vector<TDockTree> mTrees;

        std::vector<TDockTree> mTempTrees;

    public:
        TCallbackPool<> mChangeTreeCB;

        void Render() override final;// For time quant

        std::vector<TDockTree>& GetTrees();
        
        void ClearTrees();
        void ApplyTrees();
    protected:
    };
}
