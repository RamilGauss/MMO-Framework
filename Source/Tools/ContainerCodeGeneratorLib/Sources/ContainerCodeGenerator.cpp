/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ContainerCodeGenerator.h"

#include <fmt/core.h>
#include <magic_enum.hpp>

#include "LoadFromFile.h"

#include "Components/ArgumentComponent.h"
#include "Components/ConfigComponent.h"
#include "Components/PathsComponent.h"
#include "Components/ResultComponent.h"

#include "Generated files/JsonSerializer.h"

namespace nsContainerCodeGenerator
{
    TContainerCodeGenerator::TContainerCodeGenerator() : 
        mEntMng("ContainerCodeGenerator", 100)
    {
        mEntMng.Setup();
    }
    //-------------------------------------------------------------------------------------------
    void TContainerCodeGenerator::Init(int argc, char** argv)
    {
        auto singleEid = mEntMng.CreateEntity();

        // Input
        TArgumentComponent argumentComponent;
        argumentComponent.argc = argc;
        argumentComponent.argv = argv;
        mEntMng.SetComponent(singleEid, argumentComponent);

        TConfigComponent configComponent;
        mEntMng.SetComponent(singleEid, configComponent);

        TPathsComponent pathsComponent;
        mEntMng.SetComponent(singleEid, pathsComponent);

        //Output
        TResultComponent resultComponent;
        mEntMng.SetComponent(singleEid, resultComponent);
    }
    //-------------------------------------------------------------------------------------------
    TContainerCodeGenerator::Result TContainerCodeGenerator::Generate(int argc, char** argv)
    {
        Init(argc, argv);

        mMainFeature.SetEntMng(&mEntMng);

        // Form the logic conveyor.
        mMainFeature.Add(&mSetupConfigFeature);

        mMainFeature.Add(&mCoreGeneratorFeature);
        mMainFeature.Add(&mProjectGeneratorFeature);
        mMainFeature.Add(&mAggregatorDumperFeature);

        TContainerCodeGenerator::Result result = Result::OK;

        try {
            // Execute
            mMainFeature.Execute();
        } catch (...) {
            result = Result::INNER_ERROR;
        }

        // Output result
        auto resultComponent = nsECSFramework::SingleComponent<TResultComponent>(&mEntMng);
        fmt::print("ContainerCodeGenerator returns {}, \"{}\".\n", 
            magic_enum::enum_name(result), resultComponent->value);

        return result;
    }
    //-------------------------------------------------------------------------------------------
}