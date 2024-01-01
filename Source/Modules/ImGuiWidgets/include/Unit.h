/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

#include "Widget.h"
#include "Focus.h"
#include "Anchors.h"
#include "MinSize.h"
#include "MaxSize.h"
#include "VerticalAlign.h"
#include "HorizontalAlign.h"
#include "MinDistanceToParent.h"

namespace nsImGuiWidgets
{
    class DllExport TUnit : 
        public TWidget, public TFocus, public TAnchors, public TMinSize, public TMaxSize,
        public TVerticalAlign, public THorizontalAlign, public TMinDistanceToParent
    {
    public:
        void Render() override final;

        SubType GetSubType() const override;

        // Maths
        ImVec2 CalculateMinSizeInGrid() const;
        ImVec2 CalculateMinSizeInFree() const;

        void UpdateGeometryInGrid(const ImVec2& offset, const ImVec2& contentSize);
        void UpdateGeometryInFree(const ImVec2& contentSize);
    protected:
        virtual void BeginRender();
        virtual void RenderInheritance() = 0;
        virtual void EndRender();

        ImGuiID mIdFromWindow = 0;
    };
}
