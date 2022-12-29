/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GeneratorFeature.h"

namespace nsContainerCodeGenerator::nsCore
{
    void TGeneratorFeature::InitConveyor()
    {
        Add(&mDeleteGeneratedFilesSystem);

        // Components
        Add(&mPrepareComponentConfigSystem);

        Add(&mSaveComponentConfigSystem);
        Add(&mGenerateComponentFilesSystem);
        Add(&mDestroyComponentConfigSystem);
    }
}