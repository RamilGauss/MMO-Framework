/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <imgui.h>

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    struct DllExport TTextureReference
    {
    public:
        virtual void SetTextureId(void* id);
        virtual void* GetTextureId() const;
    private:
        void* mTextureId = nullptr;
    };
}
