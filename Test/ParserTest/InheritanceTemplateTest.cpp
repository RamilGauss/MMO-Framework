/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

TEST(Parser, InheritanceTemplate)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("InheritanceTemplate.h");

    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);
    auto hasParent = false;
    for (auto& type : res->mTypeList) {
        if (type->mName == "A") {
            ASSERT_TRUE(type->mInheritanceVec.size() == 1);

            if (type->mInheritanceVec[0].mShortTypeName == "B") {
                hasParent = true;
            }

            ASSERT_EQ(type->mInheritanceVec[0].mOriginalNameSpace, "ns");
        }
    }
    ASSERT_TRUE(hasParent);
}