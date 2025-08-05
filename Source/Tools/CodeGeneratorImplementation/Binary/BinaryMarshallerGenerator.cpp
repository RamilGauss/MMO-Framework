/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BinaryMarshallerGenerator.h"
#include "BinaryMarshallerHeaderFileGenerator.h"
#include "BinaryMarshallerSourceFileGenerator.h"

#include "CodeGeneratorImplementation/GeneratorList.h"

using namespace nsCodeGeneratorImplementation;

TBinaryMarshallerGenerator::TBinaryMarshallerGenerator() :
    nsReflectionCodeGenerator::ITargetCodeGenerator(TGeneratorList::BINARY)
{

}
//----------------------------------------------------------------------------------
void TBinaryMarshallerGenerator::Work()
{
    if (!HasSerializer()) {
        return;
    }

    GenerateHeader();
    GenerateSource();
}
//----------------------------------------------------------------------------------
void TBinaryMarshallerGenerator::GenerateHeader()
{
    TBinaryMarshallerHeaderFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();

    pair.first = impl->absFilePath + ".h";

    fileGenerator.Init(mResolvedConfig, mTypeManager, &mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TBinaryMarshallerGenerator::GenerateSource()
{
    TBinaryMarshallerSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();

    pair.first = impl->absFilePath + ".cpp";

    fileGenerator.Init(mResolvedConfig, mTypeManager, &mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TBinaryMarshallerGenerator::GetDependencies(const nsCppParser::TTypeInfo* typeName, std::set<std::string>& dependencies)
{

}
//----------------------------------------------------------------------------------
