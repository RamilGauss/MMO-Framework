/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

TEST(Parser, PassMustBeFails)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("this file is not existed.h");

    ASSERT_EQ(res, nullptr);
}