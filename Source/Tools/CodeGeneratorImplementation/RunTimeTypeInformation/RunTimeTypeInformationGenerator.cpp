/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "RunTimeTypeInformationGenerator.h"
#include "RunTimeTypeInformationHeaderFileGenerator.h"
#include "RunTimeTypeInformationSourceFileGenerator.h"

#include "CodeGeneratorImplementation/GeneratorList.h"

using namespace nsCodeGeneratorImplementation;

TRunTimeTypeInformationGenerator::TRunTimeTypeInformationGenerator() :
    nsReflectionCodeGenerator::ITargetCodeGenerator(TGeneratorList::RUN_TIME_TYPE_INFORMATION)
{
}
//----------------------------------------------------------------------------------
void TRunTimeTypeInformationGenerator::Work()
{
    if (!HasSerializer()) {
        return;
    }

    GenerateHeader();
    GenerateSource();
}
//----------------------------------------------------------------------------------
void TRunTimeTypeInformationGenerator::GenerateHeader()
{
    TRunTimeTypeInformationHeaderFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = impl->fileName + ".h";

    fileGenerator.Init(mResolvedConfig, mTypeManager, &mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TRunTimeTypeInformationGenerator::GenerateSource()
{
    TRunTimeTypeInformationSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = impl->fileName + ".cpp";

    fileGenerator.Init(mResolvedConfig, mTypeManager, &mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------