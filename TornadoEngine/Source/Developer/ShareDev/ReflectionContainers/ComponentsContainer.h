/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IJsonSerializer.h"
#include "IBinaryMarshaller.h"
#include "IMyGuiSerializer.h"
#include "IEntityManagerExtension.h"
#include "ITypeInformation.h"

namespace nsShareDev
{
    // Get via SingletonManager()->Get<TComponentsContainer>();
    struct DllExport TComponentsContainer
    {
        IJsonSerializer* mJson = nullptr;
        IBinaryMarshaller* mBin = nullptr;
        IMyGuiSerializer* mMygui = nullptr;
        IEntityManagerExtension* mEntMng = nullptr;
        ITypeInformation* mTypeInfo = nullptr;
    };
}