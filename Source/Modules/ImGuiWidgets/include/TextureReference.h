/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    struct DllExport TTextureReference
    {
    public:
        virtual void SetTexture(unsigned int id);
        virtual unsigned int GetTexture() const;

    protected:
        unsigned int mTextureId = -1;
    };
}
