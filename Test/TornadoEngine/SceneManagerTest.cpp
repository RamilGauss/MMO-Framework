/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

//#include "FileParser.h"
//
//TEST(Parser, InheritanceTemplate)
//{
//    //class A :
//    //    public ns::B<xx::X, yy::Y>
//    TFileParser fileParser;
//    auto res = fileParser.Parse("InheritanceTemplate.h");
//
//    ASSERT_NE(res, nullptr);
//
//    ASSERT_EQ(res->mTypeList.size(), 1);
//    auto hasParent = false;
//    for (auto& type : res->mTypeList) {
//        if (type->mName == "A") {
//            ASSERT_TRUE(type->mInheritanceVec.size() == 1);
//
//            if (type->mInheritanceVec[0].mShortTypeName == "B") {
//                hasParent = true;
//            }
//
//            ASSERT_EQ(type->mInheritanceVec[0].mLongTypeName, "ns::B");
//            ASSERT_EQ(type->mInheritanceVec[0].mNameSpace, "");
//            ASSERT_EQ(type->mInheritanceVec[0].mOriginalName, "ns::B<xx::X,yy::Y>");
//            ASSERT_EQ(type->mInheritanceVec[0].mOriginalNameSpace, "ns");
//            ASSERT_EQ(type->mInheritanceVec[0].mOriginalTypeName, "ns::B");
//            ASSERT_EQ(type->mInheritanceVec[0].mShortTypeName, "B");
//            ASSERT_EQ(type->mInheritanceVec[0].originalTemplates.size(), 2);
//        }
//    }
//    ASSERT_TRUE(hasParent);
//}
