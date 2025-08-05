/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Common/SaveConfigFileSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Common/GenerateFilesByReflectionSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Common/DestroyReflectionConfigSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Common/DestroyFileListSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Common/DestroyTypeListSystem.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Project/DeleteGeneratedFilesSystem.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Project/Component/PrepareConfigSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Project/EcsSystem/PrepareConfigSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Project/Handler/MakeFileListSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Project/Handler/TypeListToHandlerListSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Project/Handler/PrepareConfigSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Project/Handler/ParseFileListSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Project/System/PrepareConfigSystem.h"

namespace nsContainerCodeGenerator::nsProject
{
    class DllExport TGeneratorFeature : public nsECSFramework::TFeature
    {
        // Think algorithmically!
        TDeleteGeneratedFilesSystem mDeleteGeneratedFilesSystem;

        // Components
        nsComponent::TPrepareConfigSystem mPrepareComponentConfigSystem;

        nsCommon::TSaveConfigFileSystem mSaveComponentConfigSystem;
        nsCommon::TGenerateFilesByReflectionSystem mGenerateComponentFilesSystem;
        nsCommon::TDestroyReflectionConfigSystem mDestroyComponentConfigSystem;

        // Handlers
        nsHandler::TMakeFileListSystem mMakeFileListSystem;
        nsHandler::TParseFileListSystem mParseFileListSystem;
        nsHandler::TTypeListToHandlerListSystem mHandleTypeListToHandlerListSystem;

        nsHandler::TPrepareConfigSystem mPrepareHandlerConfSystem;

        nsCommon::TSaveConfigFileSystem mSaveHandlerConfigSystem;
        nsCommon::TGenerateFilesByReflectionSystem mGenerateHandlerFilesSystem;

        nsCommon::TDestroyFileListSystem mDestroyFileListSystem;
        nsCommon::TDestroyTypeListSystem mDestroyHandlerListSystem;
        nsCommon::TDestroyReflectionConfigSystem mDestroyFileTypeListsSystem;

        // Systems
        nsSystem::TPrepareConfigSystem mPrepareSystemConfigSystem;

        nsCommon::TSaveConfigFileSystem mSaveSystemConfigSystem;
        nsCommon::TGenerateFilesByReflectionSystem mGenerateSystemFilesSystem;
        nsCommon::TDestroyReflectionConfigSystem mDestroySystemConfigSystem;

        // EcsSystems
        nsEcsSystem::TPrepareConfigSystem mPrepareEcsSystemConfigSystem;

        nsCommon::TSaveConfigFileSystem mSaveEcsSystemConfigSystem;
        nsCommon::TGenerateFilesByReflectionSystem mGenerateEcsSystemFilesSystem;
        nsCommon::TDestroyReflectionConfigSystem mDestroyEcsSystemConfigSystem;

    public:
        void InitConveyor() override;
    };
}