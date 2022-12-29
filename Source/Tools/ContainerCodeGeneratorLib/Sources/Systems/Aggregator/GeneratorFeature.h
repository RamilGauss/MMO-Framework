/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/Feature.h>

#include "Systems/Common/AddGeneratedFilesComponentSystem.h"
#include "Systems/Common/SaveGeneratedFileSystem.h"
#include "Systems/Common/DestroyGeneratedFileSystem.h"

#include "Systems/Aggregator/GenerateAggregatorHeaderSystem.h"
#include "Systems/Aggregator/GenerateAggregatorCppSystem.h"
#include "Systems/Aggregator/DeleteGeneratedFilesSystem.h"
#include "Systems/Aggregator/GenerateDllCppFileSystem.h"

#include "Systems/Aggregator/Component/GenerateAggregatorHeaderSystem.h"
#include "Systems/Aggregator/Component/GenerateAggregatorCppSystem.h"
#include "Systems/Aggregator/Component/TypeInfo/GenerateAggregatorHeaderSystem.h"
#include "Systems/Aggregator/Component/TypeInfo/GenerateAggregatorCppSystem.h"
#include "Systems/Aggregator/Component/Json/GenerateAggregatorHeaderSystem.h"
#include "Systems/Aggregator/Component/Json/GenerateAggregatorCppSystem.h"
#include "Systems/Aggregator/Component/EntMng/GenerateAggregatorHeaderSystem.h"
#include "Systems/Aggregator/Component/EntMng/GenerateAggregatorCppSystem.h"

#include "Systems/Aggregator/Handler/GenerateAggregatorHeaderSystem.h"
#include "Systems/Aggregator/Handler/GenerateAggregatorCppSystem.h"
#include "Systems/Aggregator/Handler/TypeInfo/GenerateAggregatorHeaderSystem.h"
#include "Systems/Aggregator/Handler/TypeInfo/GenerateAggregatorCppSystem.h"
#include "Systems/Aggregator/Handler/TypeFactory/GenerateAggregatorHeaderSystem.h"
#include "Systems/Aggregator/Handler/TypeFactory/GenerateAggregatorCppSystem.h"

#include "Systems/Aggregator/System/GenerateAggregatorHeaderSystem.h"
#include "Systems/Aggregator/System/GenerateAggregatorCppSystem.h"
#include "Systems/Aggregator/System/TypeInfo/GenerateAggregatorHeaderSystem.h"
#include "Systems/Aggregator/System/TypeInfo/GenerateAggregatorCppSystem.h"
#include "Systems/Aggregator/System/TypeFactory/GenerateAggregatorHeaderSystem.h"
#include "Systems/Aggregator/System/TypeFactory/GenerateAggregatorCppSystem.h"
#include "Systems/Aggregator/System/DynamicCaster/GenerateAggregatorHeaderSystem.h"
#include "Systems/Aggregator/System/DynamicCaster/GenerateAggregatorCppSystem.h"

namespace nsContainerCodeGenerator::nsAggregator
{
    class DllExport TGeneratorFeature : public nsECSFramework::TFeature
    {
        // Think algorithmically!
        TDeleteGeneratedFilesSystem                                mDeleteGeneratedFilesSystem;

        nsCommon::TAddGeneratedFilesComponentSystem                mAddGeneratedFilesComponentSystem;

        // Generation
        TGenerateDllCppFileSystem                                  mGenerateDllCppFileSystem;
                                                                   
        TGenerateAggregatorHeaderSystem                            mGenerateAggregatorHeaderSystem;
        TGenerateAggregatorCppSystem                               mGenerateAggregatorCppSystem;

        // Component
        nsComponent::TGenerateAggregatorHeaderSystem               mGenerateComponentAggregatorHeaderSystem;
        nsComponent::TGenerateAggregatorCppSystem                  mGenerateComponentAggregatorCppSystem;
                                                           
        nsComponent::nsTypeInfo::TGenerateAggregatorHeaderSystem   mGenerateComponentTypeInfoAggregatorHeaderSystem;
        nsComponent::nsTypeInfo::TGenerateAggregatorCppSystem      mGenerateComponentTypeInfoAggregatorCppSystem;
                                                           
        nsComponent::nsJson::TGenerateAggregatorHeaderSystem       mGenerateComponentJsonAggregatorHeaderSystem;
        nsComponent::nsJson::TGenerateAggregatorCppSystem          mGenerateComponentJsonAggregatorCppSystem;
                                                           
        nsComponent::nsEntMng::TGenerateAggregatorHeaderSystem     mGenerateComponentEntMngAggregatorHeaderSystem;
        nsComponent::nsEntMng::TGenerateAggregatorCppSystem        mGenerateComponentEntMngAggregatorCppSystem;
                                                                     
        // Handler                                                   
        nsHandler::TGenerateAggregatorHeaderSystem                 mGenerateHandlerAggregatorHeaderSystem;
        nsHandler::TGenerateAggregatorCppSystem                    mGenerateHandlerAggregatorCppSystem;
                                                                     
        nsHandler::nsTypeInfo::TGenerateAggregatorHeaderSystem     mGenerateHandlerTypeInfoAggregatorHeaderSystem;
        nsHandler::nsTypeInfo::TGenerateAggregatorCppSystem        mGenerateHandlerTypeInfoAggregatorCppSystem;
                                                                    
        nsHandler::nsTypeFactory::TGenerateAggregatorHeaderSystem  mGenerateHandlerTypeFactoryAggregatorHeaderSystem;
        nsHandler::nsTypeFactory::TGenerateAggregatorCppSystem     mGenerateHandlerTypeFactoryAggregatorCppSystem;

        // System
        nsSystem::TGenerateAggregatorHeaderSystem                  mGenerateSystemAggregatorHeaderSystem;
        nsSystem::TGenerateAggregatorCppSystem                     mGenerateSystemAggregatorCppSystem;

        nsSystem::nsTypeInfo::TGenerateAggregatorHeaderSystem      mGenerateSystemTypeInfoAggregatorHeaderSystem;
        nsSystem::nsTypeInfo::TGenerateAggregatorCppSystem         mGenerateSystemTypeInfoAggregatorCppSystem;

        nsSystem::nsTypeFactory::TGenerateAggregatorHeaderSystem   mGenerateSystemTypeFactoryAggregatorHeaderSystem;
        nsSystem::nsTypeFactory::TGenerateAggregatorCppSystem      mGenerateSystemTypeFactoryAggregatorCppSystem;

        nsSystem::nsDynamicCaster::TGenerateAggregatorHeaderSystem mGenerateSystemDynamicCasterAggregatorHeaderSystem;
        nsSystem::nsDynamicCaster::TGenerateAggregatorCppSystem    mGenerateSystemDynamicCasterAggregatorCppSystem;

        // Finish
        nsCommon::TSaveGeneratedFileSystem                         mSaveGeneratedFileSystem;
        nsCommon::TDestroyGeneratedFileSystem                      mDestroyGeneratedFileSystem;

    public:
        void InitConveyor() override;
    };
}