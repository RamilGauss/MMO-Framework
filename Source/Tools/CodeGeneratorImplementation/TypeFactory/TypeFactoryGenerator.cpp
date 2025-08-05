/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeFactoryGenerator.h"
#include "TypeFactoryHeaderFileGenerator.h"
#include "TypeFactorySourceFileGenerator.h"

#include "CodeGeneratorImplementation/GeneratorList.h"

using namespace nsCodeGeneratorImplementation;

TTypeFactoryGenerator::TTypeFactoryGenerator() :
    nsReflectionCodeGenerator::ITargetCodeGenerator(TGeneratorList::TYPE_FACTORY) 
{
}
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
    pair.first = impl->absFilePath + ".h";

    fileGenerator.Init(mResolvedConfig, mTypeManager, &mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TTypeFactoryGenerator::GenerateSource()
{
    TTypeFactorySourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = impl->absFilePath + ".cpp";

    fileGenerator.Init(mResolvedConfig, mTypeManager, &mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TTypeFactoryGenerator::GetDependencies(const nsCppParser::TTypeInfo* typeName, std::set<std::string>& dependencyNames)
{
    // empty
}
//----------------------------------------------------------------------------------
