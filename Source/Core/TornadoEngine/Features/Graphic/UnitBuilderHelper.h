/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/EntityManager.h>

#include <ImGuiWidgets/include/Widget.h>

#include "ButtonComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TUnitBuilderHelper
    {
    public:
        static void SetupButton(nsECSFramework::TEntityManager* entMng,
            nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pButtonComponent);

        static void AddWidgetToParent(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID parentEid,
            nsImGuiWidgets::TWidget* pWidget);
    };
}