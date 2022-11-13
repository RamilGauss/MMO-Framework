/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeFactoryGenerator.h"
#include "TypeFactoryHeaderFileGenerator.h"
#include "TypeFactorySourceFileGenerator.h"

using namespace nsCodeGeneratorImplementation;

//----------------------------------------------------------------------------------
void TTypeFactoryGenerator::Work()
{
    if (!HasSerializer()) {
        return;
    }

    GenerateHeader();
    GenerateSource();
}
//----------------------------------------------------------------------------------
void TTypeFactoryGenerator::GenerateHeader()
{
    TTypeFactoryHeaderFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = GeneratedFileFullPath(impl->fileName + ".h");

    fileGenerator.Init(&mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TTypeFactoryGenerator::GenerateSource()
{
    TTypeFactorySourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = GeneratedFileFullPath(impl->fileName + ".cpp");

    fileGenerator.Init(&mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TTypeFactoryGenerator::GetDependencies(const nsCppParser::TTypeInfo* typeName, std::set<std::string>& dependencyNames)
{
    // empty
}
//----------------------------------------------------------------------------------
