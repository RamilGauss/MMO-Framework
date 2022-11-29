/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ContainerCodeGenerator.h"

#include "LoadFromFile.h"

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
    bool TContainerCodeGenerator::Init(int argc, char** argv)
    {
        mSetupConfig.Init(argc, argv);
        auto setupResult =  mSetupConfig.Work();
        if (!setupResult) {
            return false;
        }

        // Input
        auto eid = mEntMng.CreateEntity();

        TConfigComponent configComponent;
        configComponent.value = SingletonManager()->Get<TConfigContainer>()->mConfig;
        mEntMng.SetComponent(eid, configComponent);


        return true;
    }
    //-------------------------------------------------------------------------------------------
    TContainerCodeGenerator::Result TContainerCodeGenerator::Generate()
    {
        mMainFeature.SetEntMng(&mEntMng);

        // Form the logic conveyor.
        mMainFeature.Add(&mConfigLoaderSystem);
        mMainFeature.Add(&mCoreGeneratorFeature);
        mMainFeature.Add(&mProjectGeneratorFeature);
        mMainFeature.Add(&mAggregatorDumperFeature);

        // Execute
        mMainFeature.Execute();


        // Output result
        auto result = nsECSFramework::SingleComponent<TResultComponent>(&mEntMng);

        return Result::OK;
    }
    //-------------------------------------------------------------------------------------------
}