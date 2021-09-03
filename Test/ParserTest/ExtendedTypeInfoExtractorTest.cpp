/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

#include "Parser/Sources/ExtendedInfoTypeExtractor.h"

using namespace nsCppParser;

static TExtendedInfoTypeExtractor extendedInfoMaker;
static TMemberExtendedTypeInfo meti;

TEST(ExtendedTypeInfoExtractorTest, Simple)
{
    std::string str = "A::B::C::D";

    extendedInfoMaker.Convert(str, &meti);

    ASSERT_EQ(meti.mLongType, str);
    ASSERT_EQ(meti.mNameSpace, "A::B::C");
    ASSERT_EQ(meti.mShortType, "D");
    ASSERT_EQ(meti.mCategory, TypeCategory::REFLECTION);
    ASSERT_EQ(meti.mAccessMethod, AccessMethod::OBJECT);
    ASSERT_EQ(meti.mTemplateChildArr.size(), 0);
    ASSERT_EQ(meti.mSmartPtrType, "");
}

TEST(ExtendedTypeInfoExtractorTest, String)
{
    std::string str = "std::string";

    extendedInfoMaker.Convert(str, &meti);

    ASSERT_EQ(meti.mLongType, str);
    ASSERT_EQ(meti.mNameSpace, "std");
    ASSERT_EQ(meti.mShortType, "string");
    ASSERT_EQ(meti.mCategory, TypeCategory::STRING);
    ASSERT_EQ(meti.mAccessMethod, AccessMethod::OBJECT);
    ASSERT_EQ(meti.mTemplateChildArr.size(), 0);
    ASSERT_EQ(meti.mSmartPtrType, "");
}

TEST(ExtendedTypeInfoExtractorTest, SmartPointers)
{
    std::string str = "std::auto_ptr<X>";
    extendedInfoMaker.Convert(str, &meti);

    ASSERT_EQ(meti.mLongType, "X");
    ASSERT_EQ(meti.mNameSpace, "");
    ASSERT_EQ(meti.mShortType, "X");
    ASSERT_EQ(meti.mCategory, TypeCategory::REFLECTION);
    ASSERT_EQ(meti.mAccessMethod, AccessMethod::SMART_POINTER);
    ASSERT_EQ(meti.mTemplateChildArr.size(), 0);
    ASSERT_EQ(meti.mSmartPtrType, "std::auto_ptr");

    str = "std::shared_ptr<X>";
    extendedInfoMaker.Convert(str, &meti);

    ASSERT_EQ(meti.mLongType, "X");
    ASSERT_EQ(meti.mNameSpace, "");
    ASSERT_EQ(meti.mShortType, "X");
    ASSERT_EQ(meti.mCategory, TypeCategory::REFLECTION);
    ASSERT_EQ(meti.mAccessMethod, AccessMethod::SMART_POINTER);
    ASSERT_EQ(meti.mTemplateChildArr.size(), 0);
    ASSERT_EQ(meti.mSmartPtrType, "std::shared_ptr");

    str = "std::weak_ptr<X>";
    extendedInfoMaker.Convert(str, &meti);

    ASSERT_EQ(meti.mLongType, "X");
    ASSERT_EQ(meti.mNameSpace, "");
    ASSERT_EQ(meti.mShortType, "X");
    ASSERT_EQ(meti.mCategory, TypeCategory::REFLECTION);
    ASSERT_EQ(meti.mAccessMethod, AccessMethod::SMART_POINTER);
    ASSERT_EQ(meti.mTemplateChildArr.size(), 0);
    ASSERT_EQ(meti.mSmartPtrType, "std::weak_ptr");
    
    str = "std::unique_ptr<X>";
    extendedInfoMaker.Convert(str, &meti);

    ASSERT_EQ(meti.mLongType, "X");
    ASSERT_EQ(meti.mNameSpace, "");
    ASSERT_EQ(meti.mShortType, "X");
    ASSERT_EQ(meti.mCategory, TypeCategory::REFLECTION);
    ASSERT_EQ(meti.mAccessMethod, AccessMethod::SMART_POINTER);
    ASSERT_EQ(meti.mTemplateChildArr.size(), 0);
    ASSERT_EQ(meti.mSmartPtrType, "std::unique_ptr");
}

TEST(ExtendedTypeInfoExtractorTest, Int)
{
    std::string str = "std::map<int, int>  ";

    extendedInfoMaker.Convert(str, &meti);

    ASSERT_EQ(meti.mLongType, "std::map");
    ASSERT_EQ(meti.mNameSpace, "std");
    ASSERT_EQ(meti.mShortType, "map");
    ASSERT_EQ(meti.mCategory, TypeCategory::MAP);
    ASSERT_EQ(meti.mAccessMethod, AccessMethod::OBJECT);
    ASSERT_EQ(meti.mTemplateChildArr.size(), 2);
    ASSERT_EQ(meti.mSmartPtrType, "");

    for (auto& child : meti.mTemplateChildArr)         {
        ASSERT_EQ(child.mLongType, "int");
        ASSERT_EQ(child.mNameSpace, "");
        ASSERT_EQ(child.mShortType, "int");
        ASSERT_EQ(child.mCategory, TypeCategory::CEIL_NUMBER);
        ASSERT_EQ(child.mAccessMethod, AccessMethod::OBJECT);
        ASSERT_EQ(child.mTemplateChildArr.size(), 0);
        ASSERT_EQ(child.mSmartPtrType, "");
    }
}

TEST(ExtendedTypeInfoExtractorTest, Double)
{
    std::string str = " std::map<double, double>  ";

    extendedInfoMaker.Convert(str, &meti);

    ASSERT_EQ(meti.mLongType, "std::map");
    ASSERT_EQ(meti.mNameSpace, "std");
    ASSERT_EQ(meti.mShortType, "map");
    ASSERT_EQ(meti.mCategory, TypeCategory::MAP);
    ASSERT_EQ(meti.mAccessMethod, AccessMethod::OBJECT);
    ASSERT_EQ(meti.mTemplateChildArr.size(), 2);
    ASSERT_EQ(meti.mSmartPtrType, "");

    for (auto& child : meti.mTemplateChildArr) {
        ASSERT_EQ(child.mLongType, "double");
        ASSERT_EQ(child.mNameSpace, "");
        ASSERT_EQ(child.mShortType, "double");
        ASSERT_EQ(child.mCategory, TypeCategory::NUMBER);
        ASSERT_EQ(child.mAccessMethod, AccessMethod::OBJECT);
        ASSERT_EQ(child.mTemplateChildArr.size(), 0);
        ASSERT_EQ(child.mSmartPtrType, "");
    }
}

TEST(ExtendedTypeInfoExtractorTest, Pointer)
{
    std::string str = "int*";

    extendedInfoMaker.Convert(str, &meti);

    ASSERT_EQ(meti.mLongType, "int");
    ASSERT_EQ(meti.mNameSpace, "");
    ASSERT_EQ(meti.mShortType, "int");
    ASSERT_EQ(meti.mCategory, TypeCategory::CEIL_NUMBER);
    ASSERT_EQ(meti.mAccessMethod, AccessMethod::POINTER);
    ASSERT_EQ(meti.mTemplateChildArr.size(), 0);
    ASSERT_EQ(meti.mSmartPtrType, "");
}

TEST(ExtendedTypeInfoExtractorTest, EmptyTemplate)
{
    std::string str = "T<>";

    extendedInfoMaker.Convert(str, &meti);

    ASSERT_EQ(meti.mLongType, "T");
    ASSERT_EQ(meti.mNameSpace, "");
    ASSERT_EQ(meti.mShortType, "T");
    ASSERT_EQ(meti.mCategory, TypeCategory::REFLECTION);
    ASSERT_EQ(meti.mAccessMethod, AccessMethod::OBJECT);
    ASSERT_EQ(meti.mTemplateChildArr.size(), 0);
    ASSERT_EQ(meti.mSmartPtrType, "");
}