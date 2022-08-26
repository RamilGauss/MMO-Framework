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

        void UpdateChildGeometry();
        ImVec2 CalculateMinSize();

        TWidget::SubType GetSubType() const override;
    protected:

        ImVec2 GetChildMinSize() const override;
        ImVec2 GetChildMaxSize() const override;

        ImVec2 mCalculatedMinSize;

    private:
        bool mIsUsedGrid = false;

        ImVec2 CalculateCellPos(const TCell& cell);
        ImVec2 CalculateCellSize(const TCell& cell);

        ImVec2 CalculateOneCellSize();

        ImVec2 GridCalculateMinSize();
        ImVec2 FreeCalculateMinSize(bool callFromWindow = false);

        ImVec2 GridUnitCalculate(TUnit* pUnit);
        ImVec2 GridFrameCalculate(TFrame* pFrame);

        ImVec2 FreeUnitCalculate(TUnit* pUnit);
        ImVec2 FreeFrameCalculate(TFrame* pFrame);

        void GridUpdateChildGeometry();// Padding, Spacing, Anchor, Min, Max, VAlign, HAlign
        void FreeUpdateChildGeometry();// Anchor, Min, Max, VAlign, HAlign

        void GridUnitUpdate(TUnit* pUnit, const ImVec2& cellPos, const ImVec2& cellSize);
        void GridFrameUpdate(TFrame* pFrame, const ImVec2& cellPos, const ImVec2& cellSize);

        void FreeUnitUpdate(TUnit* pUnit);
        void FreeFrameUpdate(TFrame* pFrame);
    };
}
