/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include <string>
#include "Base/Common/TypeDef.h"

namespace nsTornadoEngine
{
    class DllExport IContext
    {
        int mReferenceCount = 0;
    public:
        virtual ~IContext();

        void IncrementReference();
        void DecrementReference();
        int GetReferenceCount() const;
    };
}