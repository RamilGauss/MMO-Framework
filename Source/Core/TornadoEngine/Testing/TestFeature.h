/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

#include <ECS/include/Feature.h>

#include "TestAllWidgetsSystem.h"
#include "DebugWindow.h"
#include "DockingSystem.h"
#include "DockingStuffSystem.h"
#include "TreeViewSystem.h"
#include "UnderMouseSystem.h"

#include "ChooseSystem.h"

namespace nsTest
{
    class DllExport TTestFeature : public nsECSFramework::TFeature
    {
        // Testing all possible widgets
        TTestAllWidgetsSystem mTestAllWidgetsSystem;

        // View what imgui docking can
        TDockingSystem mDockingSystem;

        // Docking experiments with tools
        TDockingStuffSystem mDockingStuffSystem;

        // TreeView
        TTreeViewSystem mTreeViewSystem;

        // Under mouse position
        TUnderMouseSystem mUnderMouseSystem;

        TChooseSystem mChooseSystem;

    public:
        void SetEntMng(nsECSFramework::TEntityManager* entMng) override;

    private:
        template <typename T>
        void AddSystemOnClick(T& system)
        {
            Add(&system);
            Remove(&mChooseSystem);
        }
    };
}