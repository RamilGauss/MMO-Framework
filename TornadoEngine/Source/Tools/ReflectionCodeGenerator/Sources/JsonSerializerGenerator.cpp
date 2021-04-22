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
    if (!IsWork()) {
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

    auto impl = mConfig->targetForCodeGeneration.implementation.jsonSerializer;
    pair.first = GeneratedFileFullPath(impl->fileName + ".h");

    fileGenerator.Init(pair, impl.get());
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TJsonSerializerGenerator::GenerateSource()
{
    TJsonSerializerSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = mConfig->targetForCodeGeneration.implementation.jsonSerializer;
    pair.first = GeneratedFileFullPath(impl->fileName + ".cpp");

    fileGenerator.Init(pair, impl.get());
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TJsonSerializerGenerator::GetDependencies(const nsCppParser::TTypeInfo* typeName, std::list<std::string>& dependencyNames)
{

}
//----------------------------------------------------------------------------------
TSerializer* TJsonSerializerGenerator::GetSerializer()
{
    return mConfig->targetForCodeGeneration.implementation.jsonSerializer.get();
}
//----------------------------------------------------------------------------------