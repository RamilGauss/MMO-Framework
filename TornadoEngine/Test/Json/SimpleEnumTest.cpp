/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "SimpleEnum.h"
#include "JsonSerializer.h"

TEST(Json, SimpleEnum)
{
    nsSimpleEnum::X x;
    x.Fill();

    std::string str;
    nsJson::TJsonSerializer::Serialize(&x, str);

    nsSimpleEnum::X other;
    std::string err;
    auto fillResult = nsJson::TJsonSerializer::Fill(&other, str, err);
    ASSERT_TRUE(fillResult);

    auto isEqual = other == x;

    ASSERT_TRUE(isEqual);
}