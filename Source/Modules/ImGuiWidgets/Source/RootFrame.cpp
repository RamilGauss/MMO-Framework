/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/RootFrame.h"
#include "ImGuiWidgets/Include/Helper.h"

using namespace nsGraphicEngine;

namespace nsImGuiWidgets
{
    TRootFrame::TRootFrame()
    {

    }
    //---------------------------------------------------------------------------------------
    void TRootFrame::BeforeBeginRender()
    {
        UpdateChildGeometry();

        mCalculatedMinSize = CalculateMinSize();

        ImGui::SetNextWindowSizeConstraints(GetChildMinSize(), GetChildMaxSize());
    }
    //---------------------------------------------------------------------------------------
}