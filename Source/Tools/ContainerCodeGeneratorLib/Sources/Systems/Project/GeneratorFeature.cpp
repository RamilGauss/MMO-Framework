/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ContainerCodeGeneratorLib/Sources/Systems/Project/GeneratorFeature.h"

namespace nsContainerCodeGenerator::nsProject
{
    void TGeneratorFeature::InitConveyor()
    {
        // Think algorithmically!
        Add(&mDeleteGeneratedFilesSystem);

        // Components
        Add(&mPrepareComponentConfigSystem);

        Add(&mSaveComponentConfigSystem);
        Add(&mGenerateComponentFilesSystem);
        Add(&mDestroyComponentConfigSystem);

        // Handlers
        Add(&mMakeFileListSystem);
        Add(&mParseFileListSystem);
        Add(&mHandleTypeListToHandlerListSystem);

        Add(&mPrepareHandlerConfSystem);

        Add(&mSaveHandlerConfigSystem);
        Add(&mGenerateHandlerFilesSystem);

        Add(&mDestroyFileListSystem);
        Add(&mDestroyHandlerListSystem);
        Add(&mDestroyFileTypeListsSystem);

        // Systems
        Add(&mPrepareSystemConfigSystem);

        Add(&mSaveSystemConfigSystem);
        Add(&mGenerateSystemFilesSystem);
        Add(&mDestroySystemConfigSystem);

        // EcsSystems
        Add(&mPrepareEcsSystemConfigSystem);

        Add(&mSaveEcsSystemConfigSystem);
        Add(&mGenerateEcsSystemFilesSystem);
        Add(&mDestroyEcsSystemConfigSystem);
    }
}