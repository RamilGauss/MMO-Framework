/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GeneratorFeature.h"

namespace nsContainerCodeGenerator::nsAggregator
{
    void TGeneratorFeature::InitConveyor()
    {
        Add(&mDeleteGeneratedFilesSystem);
        Add(&mAddGeneratedFilesComponentSystem);
        Add(&mGenerateDllCppFileSystem);

        Add(&mGenerateAggregatorHeaderSystem);
        Add(&mGenerateAggregatorCppSystem);
        
        Add(&mGenerateComponentAggregatorHeaderSystem);
        Add(&mGenerateComponentAggregatorCppSystem);

        Add(&mGenerateComponentTypeInfoAggregatorHeaderSystem);
        Add(&mGenerateComponentTypeInfoAggregatorCppSystem);

        Add(&mGenerateComponentJsonAggregatorHeaderSystem);
        Add(&mGenerateComponentJsonAggregatorCppSystem);

        Add(&mGenerateComponentEntMngAggregatorHeaderSystem);
        Add(&mGenerateComponentEntMngAggregatorCppSystem);

        Add(&mGenerateHandlerAggregatorHeaderSystem);
        Add(&mGenerateHandlerAggregatorCppSystem);

        Add(&mGenerateHandlerTypeInfoAggregatorHeaderSystem);
        Add(&mGenerateHandlerTypeInfoAggregatorCppSystem);

        Add(&mGenerateHandlerTypeFactoryAggregatorHeaderSystem);
        Add(&mGenerateHandlerTypeFactoryAggregatorCppSystem);

        Add(&mGenerateSystemAggregatorHeaderSystem);
        Add(&mGenerateSystemAggregatorCppSystem);

        Add(&mGenerateSystemTypeInfoAggregatorHeaderSystem);
        Add(&mGenerateSystemTypeInfoAggregatorCppSystem);

        Add(&mGenerateSystemTypeFactoryAggregatorHeaderSystem);
        Add(&mGenerateSystemTypeFactoryAggregatorCppSystem);

        Add(&mGenerateSystemDynamicCasterAggregatorHeaderSystem);
        Add(&mGenerateSystemDynamicCasterAggregatorCppSystem);
        
        Add(&mSaveGeneratedFileSystem);
        Add(&mDestroyGeneratedFileSystem);
    }
}