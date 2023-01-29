/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsECSFramework
{
    struct DllExport IComponent
    {
        virtual ~IComponent();

        virtual bool IsLess(const IComponent* pOther) const;
        virtual bool IsEqual(const IComponent* pOther) const;
        virtual size_t GetHash() const;
    };
}