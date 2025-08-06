/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "TornadoEditor/Sources/Features/FileHierarchyWindowRefreshSystem.h"
#include "TornadoEditor/Sources/Features/ObjectHierarchyWindowRefreshSystem.h"

#include "TornadoEditor/Sources/Features/InitWindowsFeature.h"

namespace nsTornadoEditor
{
    class DllExport TMainFeature : public nsECSFramework::TFeature
    {
        TInitWindowsFeature mInitWindowsFeature;

        //TFileHierarchyWindowRefreshSystem mFileHierarchyWindowRefreshSystem;
        //TObjectHierarchyWindowRefreshSystem mObjectHierarchyWindowRefreshSystem;

    public:
        void InitConveyor() override;
    };
}
