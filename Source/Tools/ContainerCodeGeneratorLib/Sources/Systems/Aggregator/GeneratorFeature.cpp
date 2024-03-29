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
        
        // Component
        Add(&mGenerateComponentAggregatorHeaderSystem);
        Add(&mGenerateComponentAggregatorCppSystem);

        Add(&mGenerateComponentRttiAggregatorHeaderSystem);
        Add(&mGenerateComponentRttiAggregatorCppSystem);

        Add(&mGenerateComponentJsonAggregatorHeaderSystem);
        Add(&mGenerateComponentJsonAggregatorCppSystem);

        Add(&mGenerateComponentEntMngAggregatorHeaderSystem);
        Add(&mGenerateComponentEntMngAggregatorCppSystem);

        Add(&mGenerateComponentDynamicCasterAggregatorHeaderSystem);
        Add(&mGenerateComponentDynamicCasterAggregatorCppSystem);

        Add(&mGenerateComponentTypeFactoryAggregatorHeaderSystem);
        Add(&mGenerateComponentTypeFactoryAggregatorCppSystem);

        // Handler
        Add(&mGenerateHandlerAggregatorHeaderSystem);
        Add(&mGenerateHandlerAggregatorCppSystem);

        Add(&mGenerateHandlerRttiAggregatorHeaderSystem);
        Add(&mGenerateHandlerRttiAggregatorCppSystem);

        Add(&mGenerateHandlerTypeInfoAggregatorHeaderSystem);
        Add(&mGenerateHandlerTypeInfoAggregatorCppSystem);

        Add(&mGenerateHandlerTypeFactoryAggregatorHeaderSystem);
        Add(&mGenerateHandlerTypeFactoryAggregatorCppSystem);

        // System
        Add(&mGenerateSystemAggregatorHeaderSystem);
        Add(&mGenerateSystemAggregatorCppSystem);

        Add(&mGenerateSystemRttiAggregatorHeaderSystem);
        Add(&mGenerateSystemRttiAggregatorCppSystem);

        Add(&mGenerateSystemTypeFactoryAggregatorHeaderSystem);
        Add(&mGenerateSystemTypeFactoryAggregatorCppSystem);

        Add(&mGenerateSystemDynamicCasterAggregatorHeaderSystem);
        Add(&mGenerateSystemDynamicCasterAggregatorCppSystem);

        // ImGuiWidgets                                                  
        Add(&mGenerateImGuiWidgetsAggregatorHeaderSystem);
        Add(&mGenerateImGuiWidgetsAggregatorCppSystem);

        Add(&mGenerateImGuiWidgetsRttiAggregatorHeaderSystem);
        Add(&mGenerateImGuiWidgetsRttiAggregatorCppSystem);

        Add(&mGenerateImGuiWidgetsDynamicCasterAggregatorHeaderSystem);
        Add(&mGenerateImGuiWidgetsDynamicCasterAggregatorCppSystem);
        
        Add(&mAddHeaderInGeneratedFilesSystem);
        Add(&mSaveGeneratedFileSystem);
        Add(&mDestroyGeneratedFileSystem);
    }
}