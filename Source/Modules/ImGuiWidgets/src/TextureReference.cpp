/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TextureReference.h"

using namespace nsImGuiWidgets;

void TTextureReference::SetTextureId(void* id)
{
    mTextureId = id;
}
//---------------------------------------------------------
void* TTextureReference::GetTextureId() const
{
    return mTextureId;
}
//---------------------------------------------------------
