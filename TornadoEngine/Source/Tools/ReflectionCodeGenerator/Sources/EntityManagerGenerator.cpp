/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "EntityManagerGenerator.h"
#include "EntityManagerHeaderFileGenerator.h"
#include "EntityManagerSourceFileGenerator.h"

using namespace nsReflectionCodeGenerator;

void TEntityManagerGenerator::Work()
{
    GenerateHeader();
    GenerateSource();
}
//----------------------------------------------------------------------------------
void TEntityManagerGenerator::GenerateHeader()
{
    TEntityManagerHeaderFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    pair.first = GeneratedFileFullPath(mConfig->targetForCodeGeneration.implementation.entMngExt->fileName + ".h");

    fileGenerator.Init(pair);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TEntityManagerGenerator::GenerateSource()
{
    TEntityManagerSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    pair.first = GeneratedFileFullPath(mConfig->targetForCodeGeneration.implementation.entMngExt->fileName + ".cpp");

    fileGenerator.Init(pair);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------

