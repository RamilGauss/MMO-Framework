/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ImGuiWidgets/include/Window.h"
#include "ImGuiWidgets/include/TreeView.h"
#include "ImGuiWidgets/include/TreeNode.h"

#include "GraphicEngine/GraphicEngineContext.h"

namespace nsTest
{
    class TTreeNodeTest
    {
        nsImGuiWidgets::TWindow mWindow;

        nsImGuiWidgets::TTreeView mTreeView;

    public:
        void Create(nsGraphicEngine::TGraphicEngineContext* pCtx);
        void Destroy(nsGraphicEngine::TGraphicEngineContext* pCtx);
    };
}