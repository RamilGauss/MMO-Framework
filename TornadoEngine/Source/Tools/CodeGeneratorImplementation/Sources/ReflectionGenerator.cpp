/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ReflectionGenerator.h"
#include "ReflectionHeaderFileGenerator.h"
#include "ReflectionSourceFileGenerator.h"

using namespace nsCodeGeneratorImplementation;

//----------------------------------------------------------------------------------
void TReflectionGenerator::Work()
{
    if (!HasSerializer()) {
        return;
    }

    GenerateHeader();
    GenerateSource();
}
//----------------------------------------------------------------------------------
void TReflectionGenerator::GenerateHeader()
{
    TReflectionHeaderFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = GeneratedFileFullPath(impl->fileName + ".h");

    fileGenerator.Init(&mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TReflectionGenerator::GenerateSource()
{
    TReflectionSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = GeneratedFileFullPath(impl->fileName + ".cpp");

    fileGenerator.Init(&mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TReflectionGenerator::GetDependencies(const nsCppParser::TTypeInfo* typeName, std::set<std::string>& dependencyNames)
{
    // empty
}
//----------------------------------------------------------------------------------
