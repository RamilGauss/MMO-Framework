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

//----------------------------------------------------------------------------------
void TEntityManagerGenerator::Work()
{
    if (!IsWork()) {
        return;
    }

    GenerateHeader();
    GenerateSource();
}
//----------------------------------------------------------------------------------
void TEntityManagerGenerator::GenerateHeader()
{
    TEntityManagerHeaderFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = mConfig->targetForCodeGeneration.implementation.entMngExt;
    pair.first = GeneratedFileFullPath(impl->fileName + ".h");

    fileGenerator.Init(pair, impl.get());
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TEntityManagerGenerator::GenerateSource()
{
    TEntityManagerSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = mConfig->targetForCodeGeneration.implementation.entMngExt;
    pair.first = GeneratedFileFullPath(impl->fileName + ".cpp");

    fileGenerator.Init(pair, impl.get());
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
TSerializer* TEntityManagerGenerator::GetSerializer()
{
    return mConfig->targetForCodeGeneration.implementation.entMngExt.get();
}
//----------------------------------------------------------------------------------