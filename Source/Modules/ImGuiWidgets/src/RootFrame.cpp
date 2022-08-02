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
        if (GetUseGrid()) {
            GridUpdateChildGeometry();
            mCalculatedMinSize = GridCalculateMinSize();
        } else {
            UpdateChildGeometry();
            mCalculatedMinSize = CalculateMinSize();
        }

        ImGui::SetNextWindowSizeConstraints(GetChildMinSize(), GetChildMaxSize());
    }
    //---------------------------------------------------------------------------------------
    ImVec4 TRootFrame::GetContentPadding() const
    {
        return {1, 19, 8, 8};
    }
    //---------------------------------------------------------------------------------------
}