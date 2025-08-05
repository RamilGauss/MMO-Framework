/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "EcsComponentExtensionGenerator.h"
#include "EcsComponentExtensionHeaderFileGenerator.h"
#include "EcsComponentExtensionSourceFileGenerator.h"

#include "CodeGeneratorImplementation/GeneratorList.h"

using namespace nsCodeGeneratorImplementation;

TEcsComponentExtensionGenerator::TEcsComponentExtensionGenerator() : 
    ITargetCodeGenerator(TGeneratorList::ECS_COMPONENT_EXTENSION)
{
}
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
    pair.first = impl->absFilePath + ".h";

    fileGenerator.Init(mResolvedConfig, mTypeManager, &mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TEcsComponentExtensionGenerator::GenerateSource()
{
    TEcsComponentExtensionSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = impl->absFilePath + ".cpp";

    fileGenerator.Init(mResolvedConfig, mTypeManager, &mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
