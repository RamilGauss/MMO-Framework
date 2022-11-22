/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "DynamicCaster_0.h"
#include "TypeInformation_0.h"

#include "DynamicCaster_1.h"
#include "TypeInformation_1.h"


TEST(DynamicCaster, first)
{
    auto rttiCombinations = nsDynamicCasterTest::TDynamicCaster_0::GetRttiCombinations();

    ASSERT_TRUE(rttiCombinations.size() == 2);

    int aRtti;
    bool aRttiResult = nsDynamicCasterTest::TTypeInformation_0::ConvertNameToRtti("nsFirst::A", aRtti);

    int bRtti;
    bool bRttiResult = nsDynamicCasterTest::TTypeInformation_0::ConvertNameToRtti("nsFirst::B", bRtti);

    auto aSet = rttiCombinations[aRtti];

    ASSERT_TRUE(aSet.find(bRtti) != aSet.end());

    auto bSet = rttiCombinations[bRtti];

    ASSERT_TRUE(bSet.find(aRtti) != bSet.end());
}

TEST(DynamicCaster, second)
{
    auto rttiCombinations = nsDynamicCasterTest::TDynamicCaster_1::GetRttiCombinations();

    ASSERT_TRUE(rttiCombinations.size() == 4);

    int aRtti;
    bool aRttiResult = nsDynamicCasterTest::TTypeInformation_0::ConvertNameToRtti("nsFirst::A", aRtti);

    int bRtti;
    bool bRttiResult = nsDynamicCasterTest::TTypeInformation_0::ConvertNameToRtti("nsFirst::B", bRtti);

    int cRtti;
    bool cRttiResult = nsDynamicCasterTest::TTypeInformation_1::ConvertNameToRtti("nsSecond::C", cRtti);

    int dRtti;
    bool dRttiResult = nsDynamicCasterTest::TTypeInformation_1::ConvertNameToRtti("nsSecond::D", dRtti);

    auto aSet = rttiCombinations[aRtti];

    ASSERT_TRUE(aSet.find(cRtti) != aSet.end());
    ASSERT_TRUE(aSet.find(dRtti) != aSet.end());

    auto bSet = rttiCombinations[bRtti];

    ASSERT_TRUE(bSet.find(cRtti) != bSet.end());
    ASSERT_TRUE(bSet.find(dRtti) != bSet.end());

    auto cSet = rttiCombinations[cRtti];

    ASSERT_TRUE(cSet.find(aRtti) != cSet.end());
    ASSERT_TRUE(cSet.find(bRtti) != cSet.end());
    ASSERT_TRUE(cSet.find(dRtti) != cSet.end());

    auto dSet = rttiCombinations[dRtti];

    ASSERT_TRUE(dSet.find(aRtti) != dSet.end());
    ASSERT_TRUE(dSet.find(bRtti) != dSet.end());
    ASSERT_TRUE(dSet.find(cRtti) != dSet.end());
}