/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DynamicCasterGenerator.h"
#include "DynamicCasterHeaderFileGenerator.h"
#include "DynamicCasterSourceFileGenerator.h"

using namespace nsCodeGeneratorImplementation;

//----------------------------------------------------------------------------------
void TDynamicCasterGenerator::Work()
{
    if (!HasSerializer()) {
        return;
    }

    GenerateHeader();
    GenerateSource();
}
//----------------------------------------------------------------------------------
void TDynamicCasterGenerator::GenerateHeader()
{
    TDynamicCasterHeaderFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = GeneratedFileFullPath(impl->fileName + ".h");

    fileGenerator.Init(&mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TDynamicCasterGenerator::GenerateSource()
{
    TDynamicCasterSourceFileGenerator fileGenerator;

    mPairList->push_back(TStrListPair());

    auto& pair = mPairList->back();

    auto impl = GetSerializer();
    pair.first = GeneratedFileFullPath(impl->fileName + ".cpp");

    fileGenerator.Init(&mTypeNameDB, pair, impl);
    fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TDynamicCasterGenerator::GetDependencies(const nsCppParser::TTypeInfo* pTypeName, std::set<std::string>& dependencyNames)
{
    for (auto& parent : pTypeName->mInheritanceVec) {

        auto parentType = mTypeManager->Get(parent.mOriginalTypeName);
        if (parentType == nullptr) {
            parentType = mTypeManager->Get(parent.mLongTypeName);
        }
        if (parentType == nullptr) {
            continue;
        }
        if (parentType->mTemplateArgs.size() == 0) {
            dependencyNames.insert(parentType->GetTypeNameWithNameSpace());
        }

        GetDependencies(parentType, dependencyNames);
    }
}
//----------------------------------------------------------------------------------
