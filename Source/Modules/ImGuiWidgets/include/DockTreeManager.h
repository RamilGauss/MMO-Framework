/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/CallbackPool.h"

#include "GraphicEngine/IRenderable.h"

#include "DockTree.h"
#include "LightDockTreeManager.h"

namespace nsImGuiWidgets
{
    class DllExport TDockTreeManager : public nsGraphicEngine::IRenderable
    {
        std::vector<TDockTree> mTrees;

        TLightDockTreeManager mLightTrees;
        TLightDockTreeManager mLightForFrameTrees;

    public:
        TCallbackPool<> mChangeTreeCB;

        void Render() override final;// For time quant

        std::vector<TDockTree>& GetTrees();
        
        void ClearTrees();
        void ApplyTreesAndBuildLight();
    private:

        void ApplyTrees();
        
        void DestroyTrees();
    };
}
