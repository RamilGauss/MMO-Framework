/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "Systems/Common/SaveConfigFileSystem.h"
#include "Systems/Common/GenerateFilesByReflectionSystem.h"
#include "Systems/Common/DestroyReflectionConfigSystem.h"
#include "Systems/Common/DestroyFileListSystem.h"
#include "Systems/Common/DestroyTypeListSystem.h"

#include "Systems/Core/DeleteGeneratedFilesSystem.h"
#include "Systems/Core/Component/PrepareConfigSystem.h"
#include "Systems/Core/ImGuiWidgets/PrepareConfigSystem.h"

namespace nsContainerCodeGenerator::nsCore
{
    class DllExport TGeneratorFeature : public nsECSFramework::TFeature
    {
        // Think algorithmically!
        TDeleteGeneratedFilesSystem                mDeleteGeneratedFilesSystem;

        // Components
        nsComponent::TPrepareConfigSystem          mPrepareComponentConfigSystem;

        nsCommon::TSaveConfigFileSystem            mSaveComponentConfigSystem;
        nsCommon::TGenerateFilesByReflectionSystem mGenerateComponentFilesSystem;
        nsCommon::TDestroyReflectionConfigSystem   mDestroyComponentConfigSystem;

        // ImGuiWidgets
        nsImGuiWidgets::TPrepareConfigSystem       mPrepareImGuiWidgetsConfigSystem;

        nsCommon::TSaveConfigFileSystem            mSaveImGuiWidgetsConfigSystem;
        nsCommon::TGenerateFilesByReflectionSystem mGenerateImGuiWidgetsFilesSystem;
        nsCommon::TDestroyReflectionConfigSystem   mDestroyImGuiWidgetsConfigSystem;
    public:
        void InitConveyor() override;
    };
}