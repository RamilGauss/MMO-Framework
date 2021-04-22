#include "gtest/gtest.h"

#include "TypeManager.h"

using namespace nsReflectionCodeGenerator;
using namespace nsCppParser;


TEST(TypeManager, _0)
{
    std::shared_ptr<TTypeInfo> tiA;
    tiA.reset(new TTypeInfo());
    std::shared_ptr<TTypeInfo> tiB;
    tiB.reset(new TTypeInfo());

    TTypeManager typeMng;
    tiA->mFullTypeName = "A";
    typeMng.Add(tiA.get());

    tiB->mFullTypeName = "B";
    typeMng.Add(tiB.get());

    ASSERT_NE(typeMng.Get("A"), nullptr);
    ASSERT_NE(typeMng.Get("B"), nullptr);
    ASSERT_EQ(typeMng.Get("C"), nullptr);
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

/*

class A{};

namespace X
{
    class B : A
    {
    };
}

*/


/*

class A{};

namespace X
{
    class B : A
    {
    };
}

*/
