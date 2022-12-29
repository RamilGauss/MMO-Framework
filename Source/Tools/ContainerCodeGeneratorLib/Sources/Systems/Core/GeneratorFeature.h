/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "Systems/Common/SaveConfigFileSystem.h"
#include "Systems/Common/GenerateFilesByReflectionSystem.h"
#include "Systems/Common/DestroyReflectionConfigSystem.h"
#include "Systems/Common/ParseFileListSystem.h"
#include "Systems/Common/DestroyFileListSystem.h"
#include "Systems/Common/DestroyTypeListSystem.h"

#include "Systems/Core/DeleteGeneratedFilesSystem.h"
#include "Systems/Core/PrepareComponentConfigSystem.h"

namespace nsContainerCodeGenerator::nsCore
{
    class DllExport TGeneratorFeature : public nsECSFramework::TFeature
    {
        // Think algorithmically!
        TDeleteGeneratedFilesSystem                mDeleteGeneratedFilesSystem;

        // Components
        TPrepareComponentConfigSystem              mPrepareComponentConfigSystem;

        nsCommon::TSaveConfigFileSystem            mSaveComponentConfigSystem;
        nsCommon::TGenerateFilesByReflectionSystem mGenerateComponentFilesSystem;
        nsCommon::TDestroyReflectionConfigSystem   mDestroyComponentConfigSystem;
    public:
        void InitConveyor() override;
    };
}