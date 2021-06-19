/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "Simple.hpp"
#include "JsonSerializer.h"

TEST(Json, Simple)
{
    nsSimple::X x;
    x.Fill();

    std::string str;
    nsJson::TJsonSerializer::Serialize(&x, str);

    nsSimple::X other;
    std::string err;
    auto fillResult = nsJson::TJsonSerializer::Deserialize(&other, str, err);
    ASSERT_TRUE(fillResult);

    auto isEqual = other == x;

    ASSERT_TRUE(isEqual);
}

TEST(Json, IsEqual_Simple_Must_Not_Passed)
{
    nsSimple::X x;
    x.Fill();

    nsSimple::X other;
    other.Fill();

    other.i_strbm_m.clear();

    auto isEqual = other == x;

    ASSERT_FALSE(isEqual);
}