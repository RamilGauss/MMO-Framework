/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "Systems/Project/ProjectDeleteGeneratedFilesSystem.h"

#include "Systems/Common/SaveConfigFileSystem.h"
#include "Systems/Common/GenerateFilesByReflectionSystem.h"
#include "Systems/Common/DestroyReflectionConfigSystem.h"
#include "Systems/Common/ParseFileListSystem.h"
#include "Systems/Common/DestroyFileListSystem.h"
#include "Systems/Common/DestroyTypeListSystem.h"

#include "Systems/Project/ProjectPrepareComponentConfigSystem.h"
#include "Systems/Project/ProjectMakeFileListSystem.h"
#include "Systems/Project/ProjectHandleTypeListToHandlerListSystem.h"
#include "Systems/Project/ProjectPrepareHandlerConfSystem.h"
#include "Systems/Project/ProjectPrepareSystemConfigSystem.h"

namespace nsContainerCodeGenerator
{
    class DllExport TProjectGeneratorFeature : public nsECSFramework::TFeature
    {

        // Think algorithmically!
        TProjectDeleteGeneratedFilesSystem mProjectDeleteGeneratedFilesSystem;

        // Components
        TProjectPrepareComponentConfigSystem mProjectPrepareComponentConfigSystem;

        TSaveConfigFileSystem mSaveComponentConfigSystem;
        TGenerateFilesByReflectionSystem mGenerateComponentFilesSystem;
        TDestroyReflectionConfigSystem mDestroyComponentConfigSystem;

        // Handlers
        TProjectMakeFileListSystem mProjectMakeFileListSystem;
        TParseFileListSystem mParseFileListSystem;
        TProjectHandleTypeListToHandlerListSystem mProjectHandleTypeListToHandlerListSystem;

        TProjectPrepareHandlerConfSystem mProjectPrepareHandlerConfSystem;

        TSaveConfigFileSystem mSaveHandlerConfigSystem;
        TGenerateFilesByReflectionSystem mGenerateHandlerFilesSystem;

        TDestroyFileListSystem mDestroyFileListSystem;
        TDestroyTypeListSystem mDestroyHandlerListSystem;
        TDestroyReflectionConfigSystem mDestroyFileTypeListsSystem;

        // Systems
        TProjectPrepareSystemConfigSystem mProjectPrepareSystemConfigSystem;

        TSaveConfigFileSystem mSaveSystemConfigSystem;
        TGenerateFilesByReflectionSystem mGenerateSystemFilesSystem;
        TDestroyReflectionConfigSystem mDestroySystemConfigSystem;

    public:
        void InitConveyor() override;
    };
}