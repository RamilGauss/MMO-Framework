/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TextureUv.h"

using namespace nsImGuiWidgets;

void TTextureUv::SetMaxUV(const ImVec2& value)
{
    mMinUV = value;
}
//---------------------------------------------------------
void TTextureUv::SetMinUV(const ImVec2& value)
{
    mMaxUV = value;
}
//---------------------------------------------------------
ImVec2 TTextureUv::GetMinUV() const
{
    return mMinUV;
}
//---------------------------------------------------------
ImVec2 TTextureUv::GetMaxUV() const
{
    return mMaxUV;
}
//---------------------------------------------------------


