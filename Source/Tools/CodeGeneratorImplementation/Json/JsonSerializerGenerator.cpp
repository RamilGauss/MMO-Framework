/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "JsonSerializerGenerator.h"
#include "JsonSerializerHeaderFileGenerator.h"
#include "JsonSerializerSourceFileGenerator.h"

#include "GeneratorList.h"

using namespace nsCodeGeneratorImplementation;
using namespace nsCppParser;

TJsonSerializerGenerator::TJsonSerializerGenerator() :
    nsReflectionCodeGenerator::ITargetCodeGenerator(TGeneratorList::JSON) 
{
}
//----------------------------------------------------------------------------------
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
    auto& pubMem = typeName->mMembers[(int) AccessLevel::PUBLIC];
    for (auto& member : pubMem) {
        TMemberExtendedTypeInfo* pMemberExtendedInfo = nullptr;
        switch (member->mExtendedInfo.mCategory) {
            case TypeCategory::REFLECTION:
            {
                pMemberExtendedInfo = &(member->mExtendedInfo);

                auto lessIndex = pMemberExtendedInfo->mShortType.find("<");
                if (lessIndex != std::string::npos) {
                    pMemberExtendedInfo = nullptr;
                }
            }
                break;
            case TypeCategory::SMART_POINTER:
            case TypeCategory::VECTOR:
            case TypeCategory::LIST:
            case TypeCategory::SET:
            case TypeCategory::MAP:
                {
                    TMemberExtendedTypeInfo* pExt = &(member->mExtendedInfo);
                    while (true) {
                        auto* templArr = &(pExt->mTemplateChildArr);
                        if (!templArr->empty()) {
                            pExt = &(templArr->at(templArr->size() - 1));
                        } else {
                            if (pExt->mCategory == TypeCategory::REFLECTION) {
                                pMemberExtendedInfo = pExt;
                            }
                            break;
                        }
                    }
                }
                break;
            default:;
        }

        if (pMemberExtendedInfo == nullptr) {
            continue;
        }

        dependencies.insert(pMemberExtendedInfo->mLongType);
    }

    for (auto inheritance : typeName->mInheritanceVec) {
        auto lessIndex = inheritance.mShortTypeName.find("<");
        if (lessIndex != std::string::npos) {
            continue;
        }

        dependencies.insert(inheritance.mLongTypeName);
        dependencies.insert(inheritance.mOriginalTypeName);
    }
}
//----------------------------------------------------------------------------------
