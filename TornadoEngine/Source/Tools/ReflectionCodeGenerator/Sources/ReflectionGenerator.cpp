/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ReflectionGenerator.h"
#include "ReflectionHeaderFileGenerator.h"
#include "ReflectionSourceFileGenerator.h"

using namespace nsReflectionCodeGenerator;

void TReflectionGenerator::Work()
{
    GenerateHeader();
    GenerateSource();
}
//----------------------------------------------------------------------------------
void TReflectionGenerator::GenerateHeader()
{
    TReflectionHeaderFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    pair.first = GeneratedFileFullPath(mConfig->targetForCodeGeneration.implementation.reflection->fileName + ".h");

    fileGenerator.Init(pair);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TReflectionGenerator::GenerateSource()
{
    TReflectionSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    pair.first = GeneratedFileFullPath(mConfig->targetForCodeGeneration.implementation.reflection->fileName + ".cpp");

    fileGenerator.Init(pair);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
