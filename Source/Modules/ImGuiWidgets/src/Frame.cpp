/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Frame.h"
#include "Helper.h"

using namespace nsGraphicEngine;

namespace nsImGuiWidgets
{
    TFrame::TFrame()
    {

    }
    //---------------------------------------------------------------------------------------
    void TFrame::BeforeBeginRender()
    {

    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::GetChildMinSize() const
    {
        return GetMinSize();
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::GetChildMaxSize() const
    {
        return GetMaxSize();
    }
    //---------------------------------------------------------------------------------------
}