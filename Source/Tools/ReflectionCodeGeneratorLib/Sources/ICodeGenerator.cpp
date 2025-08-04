/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <filesystem>
#include "fmt/core.h"

#include "Base/Common/SingletonManager.h"
#include "Base/Common/PathOperations.h"

#include "ReflectionCodeGeneratorLib/Sources/ICodeGenerator.h"

namespace fs = std::filesystem;
using namespace nsReflectionCodeGenerator;

ICodeGenerator::ICodeGenerator(const std::string& name)
{
    mName = name;
}
//----------------------------------------------------------------------------------
void ICodeGenerator::Init(TPairList& result)
{
    mPairList = &result;

    fmt::print("Begin code generator {}\n", mName);
}
//----------------------------------------------------------------------------------

