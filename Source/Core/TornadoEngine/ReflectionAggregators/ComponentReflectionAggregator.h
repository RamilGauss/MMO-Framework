/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TornadoEngine/ReflectionAggregators/IJsonSerializer.h"
#include "TornadoEngine/ReflectionAggregators/IBinaryMarshaller.h"
#include "TornadoEngine/ReflectionAggregators/IImGuiSerializer.h"
#include "TornadoEngine/ReflectionAggregators/IEcsComponentExtension.h"
#include "TornadoEngine/ReflectionAggregators/IRunTimeTypeInformation.h"
#include "TornadoEngine/ReflectionAggregators/ITypeFactory.h"
#include "TornadoEngine/ReflectionAggregators/IDynamicCaster.h"

namespace nsTornadoEngine
{
    struct DllExport TComponentReflectionAggregator
    {
        virtual ~TComponentReflectionAggregator() {}

        void Init()
        {
            mRtti->Init();
            mJson->Init();
            //mBin->Init();
            //mImGui->Init();
            mEntMng->Init();
            mDynamicCaster->Init();
            mTypeFactory->Init();
        }

        std::shared_ptr<IRunTimeTypeInformation> mRtti;
        std::shared_ptr<IJsonSerializer> mJson;
        std::shared_ptr<IBinaryMarshaller> mBin;
        std::shared_ptr<IImGuiSerializer> mImGui;
        std::shared_ptr<IEcsComponentExtension> mEntMng;
        std::shared_ptr<IDynamicCaster> mDynamicCaster;
        std::shared_ptr<ITypeFactory> mTypeFactory;
    };
}
