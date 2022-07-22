/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "RootFrame.h"
#include "Helper.h"

using namespace nsGraphicEngine;

namespace nsImGuiWidgets
{
    TRootFrame::TRootFrame()
    {

    }
    //---------------------------------------------------------------------------------------
    void TRootFrame::BeforeBeginRender()
    {
        ImGui::SetNextWindowSizeConstraints(GetChildMinSize(), GetChildMaxSize());
    }
    //---------------------------------------------------------------------------------------
}