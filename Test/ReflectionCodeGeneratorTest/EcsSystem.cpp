/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "EcsSystemExtension.h"
#include "RunTimeTypeInformationSerializer.h"

#include "EntityManager.h"

nsECSFramework::TEntityManager g_EntMng("");

TEST(EcsSystem, Init)
{
    int rtti;
    auto result = nsRunTimeTypeInformation::TRunTimeTypeInformationSerializer::ConvertNameToRtti("InitSystem", rtti);
    ASSERT_TRUE(result);

    InitSystem initSystem;
    initSystem.SetEntMng(&g_EntMng);
    void* pInitSystem = (void*)&initSystem;
    //auto pSystem = nsTest::TEcsSystemExtension::Cast(pInitSystem, rtti);
    //auto isInit = pSystem->IsInit();
    //ASSERT_TRUE(isInit);

    //ASSERT_TRUE(pSystem != pInitSystem);
}

TEST(EcsSystem, Execute)
{
    int rtti;
    auto result = nsRunTimeTypeInformation::TRunTimeTypeInformationSerializer::ConvertNameToRtti("ExecuteSystem", rtti);
    ASSERT_TRUE(result);

    ExecuteSystem executeSystem;
    executeSystem.SetEntMng(&g_EntMng);
    void* pExecuteSystem = (void*)&executeSystem;
    //auto pSystem = nsTest::TEcsSystemExtension::DynamicCast(pExecuteSystem, rtti);
    //auto isExecute = pSystem->IsExecute();
    //ASSERT_TRUE(isExecute);

    //ASSERT_TRUE(pSystem != pExecuteSystem);
}

TEST(EcsSystem, TearDown)
{
    int rtti;
    auto result = nsRunTimeTypeInformation::TRunTimeTypeInformationSerializer::ConvertNameToRtti("TearDownSystem", rtti);
    ASSERT_TRUE(result);

    TearDownSystem tearDownSystem;
    tearDownSystem.SetEntMng(&g_EntMng);
    void* pTearDownSystem = (void*)&tearDownSystem;
    //auto pSystem = nsTest::TEcsSystemExtension::DynamicCast(pTearDownSystem, rtti);
    //auto iTearDown = pSystem->IsTearDown();
    //ASSERT_TRUE(iTearDown);

    //ASSERT_TRUE(pSystem != pTearDownSystem);
}

TEST(EcsSystem, Feature)
{
    int rtti;
    auto result = nsRunTimeTypeInformation::TRunTimeTypeInformationSerializer::ConvertNameToRtti("Feature", rtti);
    ASSERT_TRUE(result);

    Feature feature;
    feature.SetEntMng(&g_EntMng);
    void* pFeature = (void*)&feature;
    //auto pSystem = nsTest::TEcsSystemExtension::DynamicCast(pFeature, rtti);
    //auto isFeature = pSystem->IsFeature();
    //ASSERT_TRUE(isFeature);

    //ASSERT_TRUE(pSystem != pFeature);
}

TEST(EcsSystem, OnAddCollect)
{
    int rtti;
    auto result = nsRunTimeTypeInformation::TRunTimeTypeInformationSerializer::ConvertNameToRtti("OnAddCollect", rtti);
    ASSERT_TRUE(result);

    OnAddCollect reactive;
    //reactive.SetEntMng(&g_EntMng);
    //void* pReactive = (void*)&reactive;
    //auto pSystem = nsTest::TEcsSystemExtension::DynamicCast(pReactive, rtti);

    //auto isExecute = pSystem->IsExecute();
    //ASSERT_TRUE(isExecute);

    //auto isTearDown = pSystem->IsTearDown();
    //ASSERT_TRUE(isTearDown);

    //ASSERT_TRUE(pSystem != pReactive);
}

TEST(EcsSystem, OnUpdateCollect)
{
    int rtti;
    auto result = nsRunTimeTypeInformation::TRunTimeTypeInformationSerializer::ConvertNameToRtti("OnUpdateCollect", rtti);
    ASSERT_TRUE(result);

    OnUpdateCollect reactive;
    //reactive.SetEntMng(&g_EntMng);
    //void* pReactive = (void*)&reactive;
    //auto pSystem = nsTest::TEcsSystemExtension::DynamicCast(pReactive, rtti);

    //auto isExecute = pSystem->IsExecute();
    //ASSERT_TRUE(isExecute);

    //auto isTearDown = pSystem->IsTearDown();
    //ASSERT_TRUE(isTearDown);

    //ASSERT_TRUE(pSystem != pReactive);
}

TEST(EcsSystem, OnAddInstant)
{
    int rtti;
    auto result = nsRunTimeTypeInformation::TRunTimeTypeInformationSerializer::ConvertNameToRtti("OnAddInstant", rtti);
    ASSERT_TRUE(result);

    OnAddInstant reactive;
    //reactive.SetEntMng(&g_EntMng);
    //void* pReactive = (void*)&reactive;
    //auto pSystem = nsTest::TEcsSystemExtension::DynamicCast(pReactive, rtti);

    //auto isTearDown = pSystem->IsTearDown();
    //ASSERT_TRUE(isTearDown);

    //ASSERT_TRUE(pSystem != pReactive);
}

TEST(EcsSystem, OnUpdateInstant)
{
    int rtti;
    auto result = nsRunTimeTypeInformation::TRunTimeTypeInformationSerializer::ConvertNameToRtti("OnUpdateInstant", rtti);
    ASSERT_TRUE(result);

    OnUpdateInstant reactive;
    //reactive.SetEntMng(&g_EntMng);
    //void* pReactive = (void*)&reactive;
    //auto pSystem = nsTest::TEcsSystemExtension::DynamicCast(pReactive, rtti);

    //auto isTearDown = pSystem->IsTearDown();
    //ASSERT_TRUE(isTearDown);

    //ASSERT_TRUE(pSystem != pReactive);
}

TEST(EcsSystem, OnRemoveInstant)
{
    int rtti;
    auto result = nsRunTimeTypeInformation::TRunTimeTypeInformationSerializer::ConvertNameToRtti("OnRemoveInstant", rtti);
    ASSERT_TRUE(result);

    OnRemoveInstant reactive;
    //reactive.SetEntMng(&g_EntMng);
    //void* pReactive = (void*)&reactive;
    //auto pSystem = nsTest::TEcsSystemExtension::DynamicCast(pReactive, rtti);

    //auto isTearDown = pSystem->IsTearDown();
    //ASSERT_TRUE(isTearDown);

    //ASSERT_TRUE(pSystem != pReactive);
}