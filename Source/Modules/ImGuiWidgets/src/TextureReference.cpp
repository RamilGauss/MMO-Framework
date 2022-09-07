/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TextureReference.h"

using namespace nsImGuiWidgets;

void TTextureReference::SetMaxUV(const ImVec2& value)
{
    mMinUV = value;
}
//---------------------------------------------------------
void TTextureReference::SetMinUV(const ImVec2& value)
{
    mMaxUV = value;
}
//---------------------------------------------------------
void TTextureReference::SetTexture(unsigned int id)
{
    mTextureId = id;
}
//---------------------------------------------------------
unsigned int TTextureReference::GetTexture() const
{
    return mTextureId;
}
//---------------------------------------------------------
void TTextureReference::SetTextureSize(unsigned int width, unsigned int height)
{
    mTextureWidth = width;
    mTextureHeight = height;
}
//---------------------------------------------------------
unsigned int TTextureReference::GetTextureWidth() const
{
    return mTextureWidth;
}
//---------------------------------------------------------
unsigned int TTextureReference::GetTextureHeight() const
{
    return mTextureHeight;
}
//---------------------------------------------------------
ImVec2 TTextureReference::GetMinUV() const
{
    return mMinUV;
}
//---------------------------------------------------------
ImVec2 TTextureReference::GetMaxUV() const
{
    return mMaxUV;
}
//---------------------------------------------------------


