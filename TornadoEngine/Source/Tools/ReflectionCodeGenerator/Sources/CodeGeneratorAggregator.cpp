/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "fmt/color.h"
#include "SaveToFile.h"
#include "SingletonManager.h"

#include "CodeGeneratorAggregator.h"

using namespace nsReflectionCodeGenerator;

TCodeGeneratorAggregator::TGeneratorInfo::TGeneratorInfo(ITargetCodeGenerator* generator)
{
    this->generator = generator;
}
//---------------------------------------------------------------------------------------------
TCodeGeneratorAggregator::TCodeGeneratorAggregator()
{
    mGenerators.push_back(TGeneratorInfo(&mJsonGenerator));
    mGenerators.push_back(TGeneratorInfo(&mBinaryGenerator));
    mGenerators.push_back(TGeneratorInfo(&mReflectionGenerator));
    mGenerators.push_back(TGeneratorInfo(&mEntMngGenerator));
    mGenerators.push_back(TGeneratorInfo(&mTypeInfoGenerator));
}
//---------------------------------------------------------------------------------------------
TIncludeListGenerator* TCodeGeneratorAggregator::GetIncludeList()
{
    return &mIncludeGenerator;
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorAggregator::Work()
{
    Collect();
    Dump();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorAggregator::Collect()
{
    CollectFromIncludeList();
    CollectFromJson();
    CollectFromBinary();
    CollectFromTypeInformation();
    CollectFromReflection();
    CollectFromEntityManagerExtension();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorAggregator::Dump()
{
    TSaveToFile stf;
    for (auto& fileParts : mForDump) {
        if (stf.ReOpen(fileParts.first.data()) == false) {
            continue;
        }
        for (auto& part : fileParts.second) {
            stf.WriteF("%s\n", part.data());
        }
    }
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorAggregator::CollectFromIncludeList()
{
    TIncludeListGenerator generator;
    generator.Init(mForDump);
    generator.Work();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorAggregator::CollectFromJson()
{
    TJsonSerializerGenerator generator;
    generator.Init(mForDump);
    generator.Work();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorAggregator::CollectFromBinary()
{
    TBinaryMarshallerGenerator generator;
    generator.Init(mForDump);
    generator.Work();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorAggregator::CollectFromReflection()
{
    TReflectionGenerator generator;
    generator.Init(mForDump);
    generator.Work();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorAggregator::CollectFromEntityManagerExtension()
{
    TEntityManagerGenerator generator;
    generator.Init(mForDump);
    generator.Work();
}
//---------------------------------------------------------------------------------------------
void TCodeGeneratorAggregator::CollectFromTypeInformation()
{
    TTypeInformationGenerator generator;
    generator.Init(mForDump);
    generator.Work();
}
//---------------------------------------------------------------------------------------------