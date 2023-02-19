/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TextureUv.h"

using namespace nsImGuiWidgets;

void TTextureUv::SetTextureMaxUv(const ImVec2& value)
{
    mTextureMinUv = value;
}
//---------------------------------------------------------
void TTextureUv::SetTextureMinUv(const ImVec2& value)
{
    mTextureMaxUv = value;
}
//---------------------------------------------------------
ImVec2 TTextureUv::GetTextureMinUv() const
{
    return mTextureMinUv;
}
//---------------------------------------------------------
ImVec2 TTextureUv::GetTextureMaxUv() const
{
    return mTextureMaxUv;
}
//---------------------------------------------------------


