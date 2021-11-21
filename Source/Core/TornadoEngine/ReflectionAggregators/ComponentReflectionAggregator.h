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
#include "IEntityManagerExtension.h"
#include "ITypeInformation.h"
#include "ITypeFactory.h"

namespace nsTornadoEngine
{
    struct DllExport TComponentReflectionAggregator
    {
        virtual ~TComponentReflectionAggregator() {}

        ITypeInformation* mTypeInfo = nullptr;

        IJsonSerializer* mJson = nullptr;
        IBinaryMarshaller* mBin = nullptr;
        IImGuiSerializer* mImGui = nullptr;
        IEntityManagerExtension* mEntMng = nullptr;
    };
}