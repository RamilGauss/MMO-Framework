/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/Feature.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/AddHeaderInGeneratedFilesSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/AddGeneratedFilesComponentSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/SaveGeneratedFileSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/DestroyGeneratedFileSystem.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/DeleteGeneratedFilesSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/GenerateDllCppFileSystem.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Component/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Component/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Component/Rtti/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Component/Rtti/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Component/TypeFactory/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Component/TypeFactory/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Component/Json/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Component/Json/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Component/EntMng/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Component/EntMng/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Component/DynamicCaster/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Component/DynamicCaster/GenerateAggregatorCppSystem.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Handler/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Handler/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Handler/Rtti/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Handler/Rtti/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Handler/TypeInfo/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Handler/TypeInfo/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Handler/TypeFactory/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/Handler/TypeFactory/GenerateAggregatorCppSystem.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/System/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/System/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/System/Rtti/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/System/Rtti/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/System/TypeFactory/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/System/TypeFactory/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/System/DynamicCaster/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/System/DynamicCaster/GenerateAggregatorCppSystem.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/ImGuiWidgets/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/ImGuiWidgets/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/ImGuiWidgets/Rtti/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/ImGuiWidgets/Rtti/GenerateAggregatorCppSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/ImGuiWidgets/DynamicCaster/GenerateAggregatorHeaderSystem.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/ImGuiWidgets/DynamicCaster/GenerateAggregatorCppSystem.h"

namespace nsContainerCodeGenerator::nsAggregator
{
    class DllExport TGeneratorFeature : public nsECSFramework::TFeature
    {
        // Think algorithmically!
        TDeleteGeneratedFilesSystem                                      mDeleteGeneratedFilesSystem;

        TAddGeneratedFilesComponentSystem                                mAddGeneratedFilesComponentSystem;

        // Generation                                                    
        TGenerateDllCppFileSystem                                        mGenerateDllCppFileSystem;

        TGenerateAggregatorHeaderSystem                                  mGenerateAggregatorHeaderSystem;
        TGenerateAggregatorCppSystem                                     mGenerateAggregatorCppSystem;

        // Component                                                     
        nsComponent::TGenerateAggregatorHeaderSystem                     mGenerateComponentAggregatorHeaderSystem;
        nsComponent::TGenerateAggregatorCppSystem                        mGenerateComponentAggregatorCppSystem;

        nsComponent::nsRtti::TGenerateAggregatorHeaderSystem             mGenerateComponentRttiAggregatorHeaderSystem;
        nsComponent::nsRtti::TGenerateAggregatorCppSystem                mGenerateComponentRttiAggregatorCppSystem;

        nsComponent::nsJson::TGenerateAggregatorHeaderSystem             mGenerateComponentJsonAggregatorHeaderSystem;
        nsComponent::nsJson::TGenerateAggregatorCppSystem                mGenerateComponentJsonAggregatorCppSystem;

        nsComponent::nsEntMng::TGenerateAggregatorHeaderSystem           mGenerateComponentEntMngAggregatorHeaderSystem;
        nsComponent::nsEntMng::TGenerateAggregatorCppSystem              mGenerateComponentEntMngAggregatorCppSystem;

        nsComponent::nsDynamicCaster::TGenerateAggregatorHeaderSystem    mGenerateComponentDynamicCasterAggregatorHeaderSystem;
        nsComponent::nsDynamicCaster::TGenerateAggregatorCppSystem       mGenerateComponentDynamicCasterAggregatorCppSystem;

        nsComponent::nsTypeFactory::TGenerateAggregatorHeaderSystem      mGenerateComponentTypeFactoryAggregatorHeaderSystem;
        nsComponent::nsTypeFactory::TGenerateAggregatorCppSystem         mGenerateComponentTypeFactoryAggregatorCppSystem;

        // Handler                                                       
        nsHandler::TGenerateAggregatorHeaderSystem                       mGenerateHandlerAggregatorHeaderSystem;
        nsHandler::TGenerateAggregatorCppSystem                          mGenerateHandlerAggregatorCppSystem;

        nsHandler::nsRtti::TGenerateAggregatorHeaderSystem               mGenerateHandlerRttiAggregatorHeaderSystem;
        nsHandler::nsRtti::TGenerateAggregatorCppSystem                  mGenerateHandlerRttiAggregatorCppSystem;

        nsHandler::nsTypeInfo::TGenerateAggregatorHeaderSystem           mGenerateHandlerTypeInfoAggregatorHeaderSystem;
        nsHandler::nsTypeInfo::TGenerateAggregatorCppSystem              mGenerateHandlerTypeInfoAggregatorCppSystem;

        nsHandler::nsTypeFactory::TGenerateAggregatorHeaderSystem        mGenerateHandlerTypeFactoryAggregatorHeaderSystem;
        nsHandler::nsTypeFactory::TGenerateAggregatorCppSystem           mGenerateHandlerTypeFactoryAggregatorCppSystem;

        // System                                                        
        nsSystem::TGenerateAggregatorHeaderSystem                        mGenerateSystemAggregatorHeaderSystem;
        nsSystem::TGenerateAggregatorCppSystem                           mGenerateSystemAggregatorCppSystem;

        nsSystem::nsRtti::TGenerateAggregatorHeaderSystem                mGenerateSystemRttiAggregatorHeaderSystem;
        nsSystem::nsRtti::TGenerateAggregatorCppSystem                   mGenerateSystemRttiAggregatorCppSystem;

        nsSystem::nsTypeFactory::TGenerateAggregatorHeaderSystem         mGenerateSystemTypeFactoryAggregatorHeaderSystem;
        nsSystem::nsTypeFactory::TGenerateAggregatorCppSystem            mGenerateSystemTypeFactoryAggregatorCppSystem;

        nsSystem::nsDynamicCaster::TGenerateAggregatorHeaderSystem       mGenerateSystemDynamicCasterAggregatorHeaderSystem;
        nsSystem::nsDynamicCaster::TGenerateAggregatorCppSystem          mGenerateSystemDynamicCasterAggregatorCppSystem;

        // ImGuiWidgets                                                  
        nsImGuiWidgets::TGenerateAggregatorHeaderSystem                  mGenerateImGuiWidgetsAggregatorHeaderSystem;
        nsImGuiWidgets::TGenerateAggregatorCppSystem                     mGenerateImGuiWidgetsAggregatorCppSystem;

        nsImGuiWidgets::nsRtti::TGenerateAggregatorHeaderSystem          mGenerateImGuiWidgetsRttiAggregatorHeaderSystem;
        nsImGuiWidgets::nsRtti::TGenerateAggregatorCppSystem             mGenerateImGuiWidgetsRttiAggregatorCppSystem;

        nsImGuiWidgets::nsDynamicCaster::TGenerateAggregatorHeaderSystem mGenerateImGuiWidgetsDynamicCasterAggregatorHeaderSystem;
        nsImGuiWidgets::nsDynamicCaster::TGenerateAggregatorCppSystem    mGenerateImGuiWidgetsDynamicCasterAggregatorCppSystem;

        // Finish                                                     
        TAddHeaderInGeneratedFilesSystem                                 mAddHeaderInGeneratedFilesSystem;
        TSaveGeneratedFileSystem                                         mSaveGeneratedFileSystem;
        TDestroyGeneratedFileSystem                                      mDestroyGeneratedFileSystem;

    public:
        void InitConveyor() override;
    };
}