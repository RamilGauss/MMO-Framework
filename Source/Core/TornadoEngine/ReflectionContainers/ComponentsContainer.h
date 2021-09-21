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
    // Get via SingletonManager()->Get<ComponentsContainer>();
    struct DllExport TComponentsContainer
    {
        IJsonSerializer* mJson = nullptr;
        IBinaryMarshaller* mBin = nullptr;
        IImGuiSerializer* mMygui = nullptr;
        IEntityManagerExtension* mEntMng = nullptr;
        ITypeFactory* mTypeFactory = nullptr;
        ITypeInformation* mTypeInfo = nullptr;
    };
}