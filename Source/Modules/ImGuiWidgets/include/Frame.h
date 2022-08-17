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

        virtual ImVec4 GetContentPadding() const;

        ImVec2 mCalculatedMinSize;

    private:
        bool mIsUsedGrid = false;

        ImVec2 CalculateCellPos(const TCell& cell);
        ImVec2 CalculateCellSize(const TCell& cell);

        ImVec2 CalculateOneCellSize();

        
        void CalculateUnitGeometry(TUnit* pUnit, const ImVec2& contentOffset,
        const ImVec2& contentSize, const ImVec2& oldSize, ImVec2& newPos, ImVec2& newSize);

        ImVec2 GetUnitMinSize(TUnit* pUnit, bool inGrid);

        ImVec2 GridCalculateMinSize();
        ImVec2 FreeCalculateMinSize();

        ImVec2 GridAnchorUnitCalculate(TUnit* pUnit);
        ImVec2 GridAnchorFrameCalculate(TFrame* pFrame);
        ImVec2 GridFixedUnitCalculate(TUnit* pUnit);
        ImVec2 GridFixedFrameCalculate(TFrame* pFrame);

        ImVec2 FreeAnchorUnitCalculate(TUnit* pUnit);
        ImVec2 FreeAnchorFrameCalculate(TFrame* pFrame);
        ImVec2 FreeFixedUnitCalculate(TUnit* pUnit);
        ImVec2 FreeFixedFrameCalculate(TFrame* pFrame);

        void GridUpdateChildGeometry();// Padding, Spacing, Anchor, Min, Max, VAlign, HAlign
        void FreeUpdateChildGeometry();// Anchor, Min, Max, VAlign, HAlign

        void GridAnchorUnitUpdate(TUnit* pUnit);
        void GridAnchorFrameUpdate(TFrame* pFrame);
        void GridFixedUnitUpdate(TUnit* pUnit);
        void GridFixedFrameUpdate(TFrame* pFrame);

        void FreeAnchorUnitUpdate(TUnit* pUnit);
        void FreeAnchorFrameUpdate(TFrame* pFrame);
        void FreeFixedUnitUpdate(TUnit* pUnit);
        void FreeFixedFrameUpdate(TFrame* pFrame);
    };
}
