/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <vector>
#include <map>

#include "LightDockNode.h"
#include "DockTree.h"

namespace nsImGuiWidgets
{
    class DllExport TLightDockTreeManager
    {
        std::list<TLightDockNode> mNodes;

        std::map<ImGuiID, TLightDockNode*> mNodeMap;
    public:
        void DestroyImGuiDock();
        void Build();
        void CloneTo(std::vector<TDockTree>& dstTrees);

        bool operator == (const TLightDockTreeManager& other);

        int GetNodeCount() const;

    private:
        std::list<TLightDockNode*> ResolveTrees();

        void CloneTo(TLightDockNode* lightNode, TDockNode* dockNode);
    };
}
