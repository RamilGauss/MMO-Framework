/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "Complex.hpp"
#include "Base/Common/JsonSerializer.h"

TEST(Json, Complex)
{
    nsComplex::Y y;
    y.Fill();

    std::string str;
    nsJson::TJsonSerializer::Serialize(&y, str);

    nsComplex::Y other;
    std::string err;
    auto fillResult = nsJson::TJsonSerializer::Deserialize(&other, str, err);
    ASSERT_TRUE(fillResult);

    auto isEqual = other == y;

    ASSERT_TRUE(isEqual);
}

TEST(Json, Complex_Null_Pointer)
{
    nsComplex::Y y;

    std::string str;
    nsJson::TJsonSerializer::Serialize(&y, str);

    nsComplex::Y other;
    std::string err;
    auto fillResult = nsJson::TJsonSerializer::Deserialize(&other, str, err);
    ASSERT_TRUE(fillResult);

    auto isEqual = other == y;

    ASSERT_TRUE(isEqual);
}

TEST(Json, Complex_Null_Pointer_Not_Passed)
{
    nsComplex::Y y;

    std::string str;
    nsJson::TJsonSerializer::Serialize(&y, str);

    nsComplex::Y other;
    std::string err;
    auto fillResult = nsJson::TJsonSerializer::Deserialize(&other, str, err);
    ASSERT_TRUE(fillResult);

    y.Fill();
    auto isEqual = other == y;

    ASSERT_FALSE(isEqual);
}