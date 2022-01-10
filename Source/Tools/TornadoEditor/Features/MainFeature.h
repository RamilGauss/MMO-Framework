/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>
#include "FileHierarchyWindowRefreshSystem.h"
#include "ObjectHierarchyWindowRefreshSystem.h"

namespace nsTornadoEditor
{
    class DllExport TMainFeature : public nsECSFramework::TFeature
    {
        TFileHierarchyWindowRefreshSystem mFileHierarchyWindowRefreshSystem;
        TObjectHierarchyWindowRefreshSystem mObjectHierarchyWindowRefreshSystem;

    public:
        void InitConveyor() override;
    };
}