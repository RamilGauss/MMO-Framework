/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine/Texture.h"

using namespace nsGraphicEngine;

TTexture::~TTexture()
{
    delete mData;
}
//-----------------------------------------------------------------------------------------
unsigned int TTexture::GetSize() const
{
    return sizeof(unsigned int) * mWidth * mHeight;
}
//-----------------------------------------------------------------------------------------
