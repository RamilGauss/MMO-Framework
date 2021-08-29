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

#include "TreeViewWindow.h"

namespace nsTest
{
    class DllExport TTreeViewSystem : public nsECSFramework::TInitSystem
    {
        TTreeViewWindow* mWindow = nullptr;
    public:
        void Init() override;
    };
}