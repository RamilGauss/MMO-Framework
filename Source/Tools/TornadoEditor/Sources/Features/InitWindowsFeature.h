/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "TornadoEditor/Sources/Features/FileHierarchyWindowInitSystem.h"
#include "TornadoEditor/Sources/Features/ObjectHierarchyWindowInitSystem.h"

namespace nsTornadoEditor
{
    class DllExport TInitWindowsFeature :  public nsECSFramework::TFeature
    {
        TFileHierarchyWindowInitSystem mFileHierarchyWindowInitSystem;
        TObjectHierarchyWindowInitSystem mObjectHierarchyWindowInitSystem;

    public:
        void InitConveyor() override;
    };
}
