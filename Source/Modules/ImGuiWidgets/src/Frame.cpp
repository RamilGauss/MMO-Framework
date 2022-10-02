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
    ImVec2 TFrame::GetChildMinSize() const
    {
        return mCalculatedMinSize;
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::GetChildMaxSize() const
    {
        return GetMaxSize();
    }
    //---------------------------------------------------------------------------------------
    void TFrame::SetUseGrid(bool value)
    {
        mIsUsedGrid = value;
    }
    //---------------------------------------------------------------------------------------
    bool TFrame::GetUseGrid() const
    {
        return mIsUsedGrid;
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::CalculateMinSize()
    {
        if (GetUseGrid()) {
            return GridCalculateMinSize();
        }
        return FreeCalculateMinSize(true);
    }
    //---------------------------------------------------------------------------------------
    void TFrame::UpdateChildGeometry()
    {
        if (GetUseGrid()) {
            GridUpdateChildGeometry();
        } else {
            FreeUpdateChildGeometry();
        }
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::GridCalculateMinSize()
    {
        int spacing = GetSpacing();
        ImVec2 minCellSize = { 0,0 };
        // Поиск максимума среди ячеек.
        for (auto& cell : mCells) {
            ImVec2 currentMinCellSize = { 0,0 };

            auto child = cell.second.p;

            auto childSubType = child->GetSubType();

            if (childSubType == SubType::UNIT ||
                childSubType == SubType::PROTO_FRAME) {
                auto pUnit = dynamic_cast<TUnit*>(child);
                currentMinCellSize = GridUnitCalculate(pUnit);
            }

            if (childSubType == SubType::FRAME) {
                auto pFrame = dynamic_cast<TFrame*>(child);
                currentMinCellSize = GridFrameCalculate(pFrame);
                currentMinCellSize = Max(pFrame->CalculateMinSizeInGrid(), currentMinCellSize);
            }
            // Учет размера ячейки.
            auto cellSize = cell.second.size;
            currentMinCellSize.x -= (cellSize.width - 1) * spacing;
            currentMinCellSize.y -= (cellSize.height - 1) * spacing;

            currentMinCellSize.x /= cellSize.width;
            currentMinCellSize.y /= cellSize.height;

            minCellSize.x = std::max(minCellSize.x, currentMinCellSize.x);
            minCellSize.y = std::max(minCellSize.y, currentMinCellSize.y);
        }
        // Сумма ячеек по максимуму размера = полный размер grid'а.
        ImVec2 minSummaCellSize = { minCellSize.x * GetHorizontalCellCount(), minCellSize.y * GetVerticalCellCount() };

        minSummaCellSize.x += (GetHorizontalCellCount() - 1) * spacing;
        minSummaCellSize.y += (GetVerticalCellCount() - 1) * spacing;

        minSummaCellSize.x += GetLeftPadding() + GetRightPadding();
        minSummaCellSize.y += GetTopPadding() + GetBottomPadding();

        // Взять максимальный между мин. размером фрейма и его внутренним содержимым.
        auto selfSize = GetMinSize();
        minSummaCellSize =
        {
            std::max(minSummaCellSize.x, selfSize.x),
            std::max(minSummaCellSize.y, selfSize.y)
        };

        return minSummaCellSize;
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::FreeCalculateMinSize(bool callFromWindow)
    {
        ImVec2 minSize = GetMinSize();

        for (auto& child : mWidgets) {
            ImVec2 unitMinSize = { 0,0 };

            auto childSubType = child->GetSubType();

            if (childSubType == SubType::UNIT ||
                childSubType == SubType::PROTO_FRAME) {
                auto pUnit = dynamic_cast<TUnit*>(child);
                unitMinSize = FreeUnitCalculate(pUnit);
            }
            if (childSubType == SubType::FRAME) {
                auto pFrame = dynamic_cast<TFrame*>(child);
                unitMinSize = FreeFrameCalculate(pFrame);
                unitMinSize = Max(pFrame->CalculateMinSizeInFree(), unitMinSize);
            }

            minSize.x = std::max(minSize.x, unitMinSize.x);
            minSize.y = std::max(minSize.y, unitMinSize.y);
        }

        return minSize;
    }
    //---------------------------------------------------------------------------------------
    void TFrame::FreeUpdateChildGeometry()
    {
        for (auto& child : mWidgets) {
            auto childSubType = child->GetSubType();

            if (childSubType == SubType::UNIT ||
                childSubType == SubType::PROTO_FRAME) {
                auto pUnit = dynamic_cast<TUnit*>(child);
                FreeUnitUpdate(pUnit);
            }
            if (childSubType == SubType::FRAME) {
                auto pFrame = dynamic_cast<TFrame*>(child);
                FreeFrameUpdate(pFrame);
            }
        }
    }
    //---------------------------------------------------------------------------------------
    void TFrame::GridUpdateChildGeometry()
    {
        for (auto& it : mCells) {
            auto& cell = it.second;

            auto child = cell.p;
            if (child == nullptr) {
                continue;
            }

            auto cellPos = CalculateCellPos(cell);
            auto cellSize = CalculateCellSize(cell);

            auto childSubType = child->GetSubType();

            if (childSubType == SubType::UNIT ||
                childSubType == SubType::PROTO_FRAME) {
                auto pUnit = dynamic_cast<TUnit*>(child);
                GridUnitUpdate(pUnit, cellPos, cellSize);
            }
            if (childSubType == SubType::FRAME) {
                auto pFrame = dynamic_cast<TFrame*>(child);
                GridFrameUpdate(pFrame, cellPos, cellSize);
            }
        }
    }
    //---------------------------------------------------------------------------------------
    TWidget::SubType TFrame::GetSubType() const
    {
        return SubType::FRAME;
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::CalculateCellPos(const TCell& cell)
    {
        auto cellSize = CalculateOneCellSize();

        ImVec2 pos;

        pos.x = GetLeftPadding() + (cellSize.x + GetSpacing()) * cell.pos.x;
        pos.y = GetTopPadding() + (cellSize.y + GetSpacing()) * cell.pos.y;

        return pos;
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::CalculateCellSize(const TCell& cell)
    {
        auto size = CalculateOneCellSize();

        size.x *= cell.size.width;
        size.y *= cell.size.height;

        size.x += (cell.size.width - 1) * GetSpacing();
        size.y += (cell.size.height - 1) * GetSpacing();

        return size;
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::CalculateOneCellSize()
    {
        auto selfSize = GetSize();

        ImVec2 size;

        auto cellsWidth = selfSize.x - GetLeftPadding() - GetRightPadding() - (GetHorizontalCellCount() - 1) * GetSpacing();
        auto cellsHeight = selfSize.y - GetTopPadding() - GetBottomPadding() - (GetVerticalCellCount() - 1) * GetSpacing();

        size.x = cellsWidth / GetHorizontalCellCount();
        size.y = cellsHeight / GetVerticalCellCount();

        return size;
    }
    //---------------------------------------------------------------------------------------
    // Calculate
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::GridUnitCalculate(TUnit* pUnit)
    {
        return pUnit->CalculateMinSizeInGrid();
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::GridFrameCalculate(TFrame* pFrame)
    {
        if (pFrame->GetUseGrid()) {
            return pFrame->GridCalculateMinSize();
        }

        return pFrame->FreeCalculateMinSize();
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::FreeUnitCalculate(TUnit* pUnit)
    {
        return pUnit->CalculateMinSizeInFree();
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::FreeFrameCalculate(TFrame* pFrame)
    {
        if (pFrame->GetUseGrid()) {
            return pFrame->GridCalculateMinSize();
        }

        return pFrame->FreeCalculateMinSize();
    }
    //---------------------------------------------------------------------------------------
    // Update
    //---------------------------------------------------------------------------------------
    void TFrame::GridUnitUpdate(TUnit* pUnit, const ImVec2& cellPos, const ImVec2& cellSize)
    {
        pUnit->UpdateGeometryInGrid(cellPos, cellSize);
    }
    //---------------------------------------------------------------------------------------
    void TFrame::GridFrameUpdate(TFrame* pFrame, const ImVec2& cellPos, const ImVec2& cellSize)
    {
        pFrame->UpdateGeometryInGrid(cellPos, cellSize);

        if (pFrame->GetUseGrid()) {
            pFrame->GridUpdateChildGeometry();
        } else {
            pFrame->FreeUpdateChildGeometry();
        }
    }
    //---------------------------------------------------------------------------------------
    void TFrame::FreeUnitUpdate(TUnit* pUnit)
    {
        auto contentSize = GetSize();
        pUnit->UpdateGeometryInFree(contentSize);
    }
    //---------------------------------------------------------------------------------------
    void TFrame::FreeFrameUpdate(TFrame* pFrame)
    {
        auto contentSize = GetSize();
        pFrame->UpdateGeometryInFree(contentSize);

        if (pFrame->GetUseGrid()) {
            pFrame->GridUpdateChildGeometry();
        } else {
            pFrame->FreeUpdateChildGeometry();
        }
    }
    //---------------------------------------------------------------------------------------
}