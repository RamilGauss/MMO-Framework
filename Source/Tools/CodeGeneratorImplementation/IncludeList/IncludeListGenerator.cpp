/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "CodeGeneratorImplementation/GeneratorList.h"
#include "IncludeListGenerator.h"
#include "IncludeListFileGenerator.h"
#include <filesystem>

namespace fs = std::filesystem;
using namespace nsCodeGeneratorImplementation;

TIncludeListGenerator::TIncludeListGenerator() : 
    nsReflectionCodeGenerator::IIncludeListGenerator(TGeneratorList::INCLUDE_LIST) 
{

}
//-----------------------------------------------------------------------------------
void TIncludeListGenerator::Work()
{
    TIncludeListFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    pair.first = mResolvedConfig->includeAbsFilePath + ".h";

    fileGenerator.SetIncludes(&mHeaderSet);
    fileGenerator.Init(mResolvedConfig, mTypeManager, nullptr, pair, nullptr);
    fileGenerator.Work();
}
//-----------------------------------------------------------------------------------
void TIncludeListGenerator::AddInclude(const std::string& header)
{
    mHeaderSet.insert(header);
}
//-----------------------------------------------------------------------------------