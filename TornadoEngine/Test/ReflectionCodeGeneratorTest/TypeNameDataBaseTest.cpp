#include "gtest/gtest.h"

#include "ReflectionCodeGeneratorLib/Sources/TypeNameDataBase.h"

using namespace nsReflectionCodeGenerator;

TEST(TypeNameDataBase, GenerateList)
{
    TTypeNameDataBase tdb;
    TTypeNameDataBase::TTypeInfo ta, tb, tc;

    ta.typeName = "A";
    tdb.AddForGenerate(ta);
    tb.typeName = "B";
    tdb.AddForGenerate(tb);
    tc.typeName = "C";
    tdb.AddForGenerate(tc);

    auto& genList = tdb.GetForGenerate();

    std::set<TTypeNameDataBase::TTypeInfo> ethalon = {ta, tb, tc};

    ASSERT_EQ(genList, ethalon);
}

/*
namespace X
{
    class A{};

    class B : A
    {
    };
}
*/
TEST(TypeNameDataBase, Reference_0)
{
    TTypeNameDataBase tdb;

    TTypeNameDataBase::TReferenceInfo ta, tb;
    ta.typeInfo.typeName = "A";
    ta.typeInfo.nameSpace = "X";
    tdb.AddReference(ta);

    tb.typeInfo.typeName = "B";
    tb.typeInfo.nameSpace = "X";
    tdb.AddReference(tb);

    TTypeNameDataBase::TRequestParams requestParams;
    requestParams.typeInfo.typeName = "A";
    requestParams.preferredNameSpace = "X";
    auto reference = tdb.GetReferenceFullTypeName(requestParams);
    ASSERT_NE(reference, nullptr);

    ASSERT_EQ(reference->typeInfo.GetFullType(), "X::A");
}

/*

class A{};

namespace X
{
    class B : A
    {
    };
}

*/

TEST(TypeNameDataBase, Reference_1)
{
    TTypeNameDataBase tdb;

    TTypeNameDataBase::TReferenceInfo ta, tb;
    ta.typeInfo.typeName = "A";
    tdb.AddReference(ta);

    tb.typeInfo.typeName = "B";
    tb.typeInfo.nameSpace = "X";
    tdb.AddReference(tb);

    TTypeNameDataBase::TRequestParams requestParams;
    requestParams.typeInfo.typeName = "A";
    requestParams.preferredNameSpace = "X";
    auto reference = tdb.GetReferenceFullTypeName(requestParams);
    ASSERT_NE(reference, nullptr);

    ASSERT_EQ(reference->typeInfo.GetFullType(), "A");
}

/*

class A{};

class B : A
{
};

*/

TEST(TypeNameDataBase, Reference_2)
{
    TTypeNameDataBase tdb;

    TTypeNameDataBase::TReferenceInfo ta, tb;
    ta.typeInfo.typeName = "A";
    tdb.AddReference(ta);

    tb.typeInfo.typeName = "B";
    tdb.AddReference(tb);

    TTypeNameDataBase::TRequestParams requestParams;
    requestParams.typeInfo.typeName = "A";
    auto reference = tdb.GetReferenceFullTypeName(requestParams);
    ASSERT_NE(reference, nullptr);

    ASSERT_EQ(reference->typeInfo.GetFullType(), "A");
}