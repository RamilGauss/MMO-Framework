/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "ProtoFrame.h"
#include "Events.h"
#include "CallbackPool.h"
#include "Padding.h"
#include "Spacing.h"
#include "Grid.h"

namespace nsImGuiWidgets
{
    class DllExport TFrame : public TProtoFrame, public TPadding, public TSpacing, public TGrid
    {
    public:
        TFrame();

        void SetUseGrid(bool value);
        bool GetUseGrid() const;

        void GridUpdateChildGeometry();// Padding, Spacing, Anchor, Min, Max, VAlign, HAlign
        void UpdateChildGeometry();    // Anchor, Min, Max, VAlign, HAlign

        ImVec2 GridCalculateMinSize();
        ImVec2 CalculateMinSize();

        TWidget::SubType GetSubType() const override;
    protected:

        ImVec2 GetChildMinSize() const override;
        ImVec2 GetChildMaxSize() const override;

        ImVec2 mCalculatedMinSize;

    private:
        bool mIsUsedGrid = false;

        ImVec2 CalculateCellPos(const TCell& cell);
        ImVec2 CalculateCellSize();

        
        void CalculateUnitGeometry(TUnit* pUnit, const ImVec2& contentSize, ImVec2& newPos, ImVec2& newSize);
    };
}
