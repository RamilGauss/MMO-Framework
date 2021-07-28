/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#pragma warning(disable:4355)

#include "BL_Debug.h"
#include "TypeDef.h"

namespace nsStoreObject
{
    enum { ePush = 0, ePop = 1, };
}

// Thread Safe
template<typename Type>
class DllExport TOnly_N_Object
{
public:
    TOnly_N_Object(int maxCntObject)
    {
        std::string nameClass = typeid(Type).name();
        StoreObject(nsStoreObject::ePush, maxCntObject, nameClass, this);
    }
    virtual ~TOnly_N_Object()
    {
        StoreObject(nsStoreObject::ePop, 0, "", this);
    }
};

extern DllExport void StoreObject(int i, int maxCntObject, std::string nameClass, void* pThis);
