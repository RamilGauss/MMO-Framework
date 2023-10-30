/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "RunTimeTypeInformationSerializer.h"
#include "TypeInformationSerializer.h"

TEST(TypeInfo, Get)
{
    int rtti;
    auto result = nsRunTimeTypeInformation::TRunTimeTypeInformationSerializer::ConvertNameToRtti("InitSystem", rtti);
    ASSERT_TRUE(result);

    auto pType = nsTypeInformation::TTypeInformationSerializer::Get(rtti);
    ASSERT_TRUE(pType);

    ASSERT_TRUE(pType->mInheritanceVec.size() == 1);


    //auto pA = ()nsReflection::TReflectionSerializer::New();

    //nsAllTypes::A a;
    //a.x = 0;

    //std::string strA;
    //nsJson_InOut_0::TJsonSerializer::Serialize(&a, strA);

    //ASSERT_FALSE(strA.empty());

    //nsInOut::B b;
    //std::string strB;
    //nsJson_InOut_1::TJsonSerializer::Serialize(&b, strB);

    //ASSERT_FALSE(strB.empty());
}