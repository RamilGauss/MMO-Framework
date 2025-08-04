/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "Base/Common/PathOperations.h"

#include "FileParser.h"

std::string fileContent = R"(
#pragma once

class ClassDeclaration;
struct StructDeclaration;
)";

TEST(Parser, ClassDeclaration)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(fileContent), "ClassDeclaration.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 0);
}
