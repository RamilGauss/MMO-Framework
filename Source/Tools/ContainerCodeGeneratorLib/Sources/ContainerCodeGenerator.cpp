/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ContainerCodeGenerator.h"

#include <fmt/core.h>

#include "LoadFromFile.h"

#include "Components/ArgumentComponent.h"
#include "Components/ConfigComponent.h"
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
        mMainFeature.Add(&mSetupConfigSystem);
        mMainFeature.Add(&mCoreGeneratorFeature);
        mMainFeature.Add(&mProjectGeneratorFeature);
        mMainFeature.Add(&mAggregatorDumperFeature);

        try {
            // Execute
            mMainFeature.Execute();
        } catch (...) {
            // Output result
            auto result = nsECSFramework::SingleComponent<TResultComponent>(&mEntMng);
            fmt::print("Error execution \"{}\".\n", result->value);

            return Result::INNER_ERROR;
        }

        return Result::OK;
    }
    //-------------------------------------------------------------------------------------------
}