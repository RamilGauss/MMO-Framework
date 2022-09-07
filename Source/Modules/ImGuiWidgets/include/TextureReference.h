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
        virtual void SetMaxUV(const ImVec2& value);
        virtual void SetMinUV(const ImVec2& value);

        virtual void SetTexture(unsigned int id);
        virtual void SetTextureSize(unsigned int width, unsigned int height);

        virtual unsigned int GetTexture() const;
        virtual unsigned int GetTextureWidth() const;
        virtual unsigned int GetTextureHeight() const;

        virtual ImVec2 GetMinUV() const;
        virtual ImVec2 GetMaxUV() const;
    protected:
        unsigned int mTextureId = -1;
        unsigned int mTextureWidth = 0;
        unsigned int mTextureHeight = 0;

        ImVec2 mMinUV = { 0,0 };
        ImVec2 mMaxUV = { 1,1 };
    };
}
