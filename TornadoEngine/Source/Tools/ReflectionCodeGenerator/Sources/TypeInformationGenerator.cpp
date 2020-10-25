/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeInformationGenerator.h"
#include "TypeInformationHeaderFileGenerator.h"
#include "TypeInformationSourceFileGenerator.h"

using namespace nsReflectionCodeGenerator;

void TTypeInformationGenerator::Work()
{
    GenerateHeader();
    GenerateSource();
}
//----------------------------------------------------------------------------------
void TTypeInformationGenerator::GenerateHeader()
{
    TTypeInformationHeaderFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = mConfig->targetForCodeGeneration.implementation.typeInformation;
    pair.first = GeneratedFileFullPath(impl->fileName + ".h");

    fileGenerator.Init(pair, impl.get());
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TTypeInformationGenerator::GenerateSource()
{
    TTypeInformationSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = mConfig->targetForCodeGeneration.implementation.typeInformation;
    pair.first = GeneratedFileFullPath(impl->fileName + ".cpp");

    fileGenerator.Init(pair, impl.get());
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------

