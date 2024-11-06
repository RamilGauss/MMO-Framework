/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/ColanderVector.h"
#include "Base/Common/TypeDef.h"
#include "Base/Common/RunTimeTypeIndex.h"
#include "Base/Common/SingletonManager.h"

#include "Base/Zones/Types.h"

namespace nsBase::nsZones
{
    struct DllExport THopProcessContext
    {
        void SetActiveProcess(SharedPtrHopProcess process);
        void SetOwnerZone(SharedPtrZone zone);

        SharedPtrHopProcess GetActiveProcess() const;
        SharedPtrZone GetOwnerZone() const;

        template <typename Type>
        void SetData(Type* pType)
        {
            auto index = SingletonManager()->Get<TRunTimeTypeIndex<>>()->Type<Type>();
            mData[index] = (void*)pType;
        }

        template <typename Type>
        Type* GetData() const
        {
            auto index = SingletonManager()->Get<TRunTimeTypeIndex<>>()->Type<Type>();
            return (Type*)mData[index];
        }
    private:
        SharedPtrHopProcess mActiveProcess = nullptr;
        SharedPtrZone mOwnerZone = nullptr;

        TColanderVector<void*> mData;
    };
}
