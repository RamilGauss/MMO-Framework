/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TextureSize.h"

using namespace nsImGuiWidgets;

void TTextureSize::SetTextureSize(unsigned int width, unsigned int height)
{
    mTextureWidth = width;
    mTextureHeight = height;
}
//---------------------------------------------------------
unsigned int TTextureSize::GetTextureWidth() const
{
    return mTextureWidth;
}
//---------------------------------------------------------
unsigned int TTextureSize::GetTextureHeight() const
{
    return mTextureHeight;
}
//---------------------------------------------------------
