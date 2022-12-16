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

#include "Systems/Core/CoreDeleteGeneratedFilesSystem.h"
#include "Systems/Core/CorePrepareComponentConfigSystem.h"
#include "Systems/Core/CorePrepareHandlerConfSystem.h"
#include "Systems/Core/CoreHandlerParserSystem.h"
#include "Systems/Core/CoreMakeFileListSystem.h"
#include "Systems/Core/CoreHandleTypeListToHandlerListSystem.h"
#include "Systems/Core/CorePrepareEcsSystemConfigSystem.h"
#include "Systems/Core/CorePrepareSystemConfigSystem.h"

namespace nsContainerCodeGenerator
{
    class DllExport TCoreGeneratorFeature : public nsECSFramework::TFeature
    {
        // Think algorithmically!
        TCoreDeleteGeneratedFilesSystem mCoreDeleteGeneratedFilesSystem;

        // Components
        TCorePrepareComponentConfigSystem mCorePrepareComponentConfigSystem;

        TSaveConfigFileSystem mSaveComponentConfigSystem;
        TGenerateFilesByReflectionSystem mGenerateComponentFilesSystem;
        TDestroyReflectionConfigSystem mDestroyComponentConfigSystem;

        // Handlers
        TCoreMakeFileListSystem mCoreMakeFileListSystem;
        TParseFileListSystem mParseFileListSystem;
        TCoreHandleTypeListToHandlerListSystem mHandleTypeListToHandlerListSystem;
        
        TCorePrepareHandlerConfSystem mCorePrepareHandlerConfSystem;

        TSaveConfigFileSystem mSaveHandlerConfigSystem;
        TGenerateFilesByReflectionSystem mGenerateHandlerFilesSystem;

        TDestroyFileListSystem mDestroyFileListSystem;
        TDestroyTypeListSystem mDestroyHandlerListSystem;
        TDestroyReflectionConfigSystem mDestroyFileTypeListsSystem;

        // EcsSystems
        TCorePrepareEcsSystemConfigSystem mCorePrepareEcsSystemConfigSystem;

        TSaveConfigFileSystem mSaveEcsSystemConfigSystem;
        TGenerateFilesByReflectionSystem mGenerateEcsSystemFilesSystem;
        TDestroyReflectionConfigSystem mDestroyEcsSystemConfigSystem;

        // Systems
        TCorePrepareSystemConfigSystem mCorePrepareSystemConfigSystem;

        TSaveConfigFileSystem mSaveSystemConfigSystem;
        TGenerateFilesByReflectionSystem mGenerateSystemFilesSystem;
        TDestroyReflectionConfigSystem mDestroySystemConfigSystem;

    public:
        void InitConveyor() override;
    };
}