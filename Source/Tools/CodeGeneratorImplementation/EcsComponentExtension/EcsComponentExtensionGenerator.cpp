/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "EcsComponentExtensionGenerator.h"
#include "EcsComponentExtensionHeaderFileGenerator.h"
#include "EcsComponentExtensionSourceFileGenerator.h"

using namespace nsCodeGeneratorImplementation;

//----------------------------------------------------------------------------------
void TEcsComponentExtensionGenerator::Work()
{
    if (!HasSerializer()) {
        return;
    }

    GenerateHeader();
    GenerateSource();
}
//----------------------------------------------------------------------------------
void TEcsComponentExtensionGenerator::GenerateHeader()
{
    TEcsComponentExtensionHeaderFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = GeneratedFileFullPath(impl->fileName + ".h");

    fileGenerator.Init(&mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TEcsComponentExtensionGenerator::GenerateSource()
{
    TEcsComponentExtensionSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = GeneratedFileFullPath(impl->fileName + ".cpp");

    fileGenerator.Init(&mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
