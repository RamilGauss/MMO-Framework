/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsGraphicEngine
{
    class DllExport TTexture
    {
    public:
        int mWidth = 0;
        int mHeight = 0;
        int mBpp = 0;

        unsigned int mId = 0;

        unsigned char* mData = nullptr;

        unsigned int GetSize() const;

        virtual ~TTexture();
    };
}
