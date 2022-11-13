/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BinaryMarshallerGenerator.h"
#include "BinaryMarshallerHeaderFileGenerator.h"
#include "BinaryMarshallerSourceFileGenerator.h"

using namespace nsCodeGeneratorImplementation;

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

    pair.first = GeneratedFileFullPath(impl->fileName + ".h");

    fileGenerator.Init(&mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TBinaryMarshallerGenerator::GenerateSource()
{
    TBinaryMarshallerSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();

    pair.first = GeneratedFileFullPath(impl->fileName + ".cpp");

    fileGenerator.Init(&mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TBinaryMarshallerGenerator::GetDependencies(const nsCppParser::TTypeInfo* typeName, std::set<std::string>& dependencies)
{

}
//----------------------------------------------------------------------------------
