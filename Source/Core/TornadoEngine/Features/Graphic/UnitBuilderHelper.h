/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/EntityManager.h>

#include <ImGuiWidgets/include/Widget.h>
#include <ImGuiWidgets/include/MenuNode.h>

#include "ButtonComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TUnitBuilderHelper
    {
    public:
        static void SetupWidget(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, nsImGuiWidgets::TWidget* pWidget);

        static void SetupMenuNode(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, nsImGuiWidgets::TMenuNode* pMenuNode);

        static void AddWidgetToParent(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID parentEid,
            nsImGuiWidgets::TWidget* pWidget);

        static void UnlinkParent(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID eid,
            nsImGuiWidgets::TWidget* pWidget);

        static void UnlinkMenuNode(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID eid,
            nsImGuiWidgets::TMenuNode* pMenuNode);
    };
}