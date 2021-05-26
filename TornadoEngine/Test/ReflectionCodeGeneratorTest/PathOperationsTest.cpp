/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include <filesystem>

#include "ReflectionCodeGeneratorLib/Sources/PathOperations.h"

using namespace nsReflectionCodeGenerator;

TEST(PathOperation, AbsByRel)
{
    auto currentPath = std::filesystem::canonical(".");
    auto currentPathStr = currentPath.string();

    std::string rel = "\\..\\";

    auto abs = TPathOperations::CalculatePathBy(currentPathStr, rel);
    ASSERT_EQ(abs.empty(), false);

    auto parentPath = currentPath.parent_path().string() + "\\";

    ASSERT_EQ(abs, parentPath);
}

TEST(PathOperation, AbsByAbs)
{
    auto currentPath = std::filesystem::canonical(".");
    auto currentPathStr = currentPath.string();

    std::string abs = currentPathStr;

    auto absByAbs = TPathOperations::CalculatePathBy(currentPathStr, abs);
    ASSERT_EQ(abs.empty(), false);
    ASSERT_EQ(abs, absByAbs);
}
