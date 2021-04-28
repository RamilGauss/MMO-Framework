/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "JsonSerializerGenerator.h"
#include "JsonSerializerHeaderFileGenerator.h"
#include "JsonSerializerSourceFileGenerator.h"

using namespace nsReflectionCodeGenerator;

void TJsonSerializerGenerator::Work()
{
    if (!HasSerializer()) {
        return;
    }

    GenerateHeader();
    GenerateSource();
}
//----------------------------------------------------------------------------------
void TJsonSerializerGenerator::GenerateHeader()
{
    TJsonSerializerHeaderFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = GeneratedFileFullPath(impl->fileName + ".h");

    fileGenerator.Init(&mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TJsonSerializerGenerator::GenerateSource()
{
    TJsonSerializerSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = GeneratedFileFullPath(impl->fileName + ".cpp");

    fileGenerator.Init(&mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TJsonSerializerGenerator::GetDependencies(const nsCppParser::TTypeInfo* typeName, std::set<std::string>& dependencies)
{

}
//----------------------------------------------------------------------------------
