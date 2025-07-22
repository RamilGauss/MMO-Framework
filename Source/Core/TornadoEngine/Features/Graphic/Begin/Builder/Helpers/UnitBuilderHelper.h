/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/EntityManager.h"

#include "ImGuiWidgets/Include/Widget.h"
#include "ImGuiWidgets/Include/MenuNode.h"
#include "ImGuiWidgets/Include/TreeNode.h"
#include "ImGuiWidgets/Include/Label.h"


namespace nsGraphicWrapper
{
    class DllExport TUnitBuilderHelper
    {
    public:
        static void SetupSize(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, nsImGuiWidgets::TSize* pGeometry);
        static void SetupPosition(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, nsImGuiWidgets::TPosition* pGeometry);

        static void SetupWidget(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, nsImGuiWidgets::TWidget* pWidget);

        static void SetupLabel(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, nsImGuiWidgets::TLabel* pLabel);

        static void SetupMenuNode(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, nsImGuiWidgets::TMenuNode* pMenuNode);

        static void SetupTreeNode(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, nsImGuiWidgets::TTreeNode* pTreeNode);

        static void SetupTreeView(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, nsImGuiWidgets::TTreeView* pTreeNode);

        static void AddWidgetToParent(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID parentEid,
            nsImGuiWidgets::TWidget* pWidget);

        static void UnlinkParent(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID eid,
            nsImGuiWidgets::TWidget* pWidget);

        static void UnlinkMenuNode(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID eid,
            nsImGuiWidgets::TMenuNode* pMenuNode);

        static void UnlinkTreeNode(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID eid,
            nsImGuiWidgets::TTreeNode* pTreeNode);
    };
}
