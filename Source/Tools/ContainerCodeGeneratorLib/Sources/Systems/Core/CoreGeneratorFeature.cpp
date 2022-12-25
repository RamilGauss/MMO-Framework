/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CoreGeneratorFeature.h"

namespace nsContainerCodeGenerator
{
    void TCoreGeneratorFeature::InitConveyor()
    {
        Add(&mCoreDeleteGeneratedFilesSystem);

        // Components
        Add(&mCorePrepareComponentConfigSystem);

        Add(&mSaveComponentConfigSystem);
        Add(&mGenerateComponentFilesSystem);
        Add(&mDestroyComponentConfigSystem);

        // EcsSystems
        Add(&mCorePrepareEcsSystemConfigSystem);

        Add(&mSaveEcsSystemConfigSystem);
        Add(&mGenerateEcsSystemFilesSystem);
        Add(&mDestroyEcsSystemConfigSystem);

        // Systems
        Add(&mCorePrepareSystemConfigSystem);

        Add(&mSaveSystemConfigSystem);
        Add(&mGenerateSystemFilesSystem);
        Add(&mDestroySystemConfigSystem);
    }
}