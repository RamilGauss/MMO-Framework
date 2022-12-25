/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ProjectGeneratorFeature.h"

namespace nsContainerCodeGenerator
{
    void TProjectGeneratorFeature::InitConveyor()
    {
        Add(&mProjectDeleteGeneratedFilesSystem);

        // Components
        Add(&mProjectPrepareComponentConfigSystem);

        Add(&mSaveComponentConfigSystem);
        Add(&mGenerateComponentFilesSystem);
        Add(&mDestroyComponentConfigSystem);

        // Handlers
        Add(&mProjectMakeFileListSystem);
        Add(&mParseFileListSystem);
        Add(&mProjectHandleTypeListToHandlerListSystem);

        Add(&mProjectPrepareHandlerConfSystem);

        Add(&mSaveHandlerConfigSystem);
        Add(&mGenerateHandlerFilesSystem);

        Add(&mDestroyFileListSystem);
        Add(&mDestroyHandlerListSystem);
        Add(&mDestroyFileTypeListsSystem);

        // Systems
        Add(&mProjectPrepareSystemConfigSystem);

        Add(&mSaveSystemConfigSystem);
        Add(&mGenerateSystemFilesSystem);
        Add(&mDestroySystemConfigSystem);
    }
}