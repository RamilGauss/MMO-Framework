/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Identity.h"

using namespace nsImGuiWidgets;

ImGuiID TIdentity::mLastId = 0;

//------------------------------------------------------------------------
TIdentity::TIdentity()
{
    mLastId++;
    mId = mLastId;
}
//------------------------------------------------------------------------
ImGuiID TIdentity::GetId() const
{
    return mId;
}
//------------------------------------------------------------------------
