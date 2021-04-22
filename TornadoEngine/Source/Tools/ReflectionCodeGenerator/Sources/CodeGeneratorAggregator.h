/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "ICodeGenerator.h"

#include "IncludeListGenerator.h"

#include "JsonSerializerGenerator.h"
#include "BinaryMarshallerGenerator.h"
#include "TypeInformationGenerator.h"
#include "ConfigContainer.h"
#include "ReflectionGenerator.h"
#include "EntityManagerGenerator.h"

namespace nsReflectionCodeGenerator
{
    class TCodeGeneratorAggregator
    {
        ICodeGenerator::TPairList mForDump;

        TIncludeListGenerator mIncludeGenerator;
        //TMyGuiSerializerGenerator mMyGuiGenerator;
        TJsonSerializerGenerator mJsonGenerator;
        TBinaryMarshallerGenerator mBinaryGenerator;
        TReflectionGenerator mReflectionGenerator;
        TEntityManagerGenerator mEntMngGenerator;
        TTypeInformationGenerator mTypeInfoGenerator;
    public:
        struct TGeneratorInfo
        {
            ITargetCodeGenerator* generator = nullptr;
            std::list<nsCppParser::TTypeInfo*> temp;

            TGeneratorInfo(ITargetCodeGenerator* generator);
        };

        std::list<TGeneratorInfo> mGenerators;

        TIncludeListGenerator* GetIncludeList();

        TCodeGeneratorAggregator();

        void Work();
    private:
        void Collect();
        void Dump();

        void CollectFromIncludeList();
        void CollectFromJson();
        void CollectFromBinary();
        void CollectFromTypeInformation();
        void CollectFromReflection();
        void CollectFromEntityManagerExtension();
    };
}