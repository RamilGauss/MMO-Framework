/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IJsonSerializer.h"
#include "IBinaryMarshaller.h"
#include "IImGuiSerializer.h"
#include "IEcsComponentExtension.h"
#include "IRunTimeTypeInformation.h"
#include "ITypeFactory.h"
#include "IDynamicCaster.h"

namespace nsTornadoEngine
{
    struct DllExport TComponentReflectionAggregator
    {
        virtual ~TComponentReflectionAggregator() {}

        void Init()
        {
            mRunTimeTypeInfo->Init();
            mJson->Init();
            //mBin->Init();
            //mImGui->Init();
            mEntMng->Init();
            mDynamicCaster->Init();
            mTypeFactory->Init();
        }

        IRunTimeTypeInformation* mRunTimeTypeInfo = nullptr;
        IJsonSerializer* mJson = nullptr;
        IBinaryMarshaller* mBin = nullptr;
        IImGuiSerializer* mImGui = nullptr;
        IEcsComponentExtension* mEntMng = nullptr;
        IDynamicCaster* mDynamicCaster = nullptr;
        ITypeFactory* mTypeFactory = nullptr;
    };
}
