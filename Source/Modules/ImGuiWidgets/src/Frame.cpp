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
    ImVec2 TFrame::GridCalculateMinSize()
    {
        ImVec2 minCellSize = { 0,0 };
        for (auto& cell : mCells) {
            auto child = cell.second.p;

            if (child->GetSubType() == SubType::UNIT || child->GetSubType() == SubType::FRAME) {
                auto pUnit = dynamic_cast<TUnit*>(child);

                auto unitMinSize = GetUnitMinSize(pUnit, true);

                minCellSize.x = std::max(minCellSize.x, unitMinSize.x);
                minCellSize.y = std::max(minCellSize.y, unitMinSize.y);
            }
        }

        ImVec2 minSummaCellSize = { minCellSize.x * GetHorizontalCellCount(), minCellSize.y * GetVerticalCellCount() };

        minSummaCellSize.x += (GetHorizontalCellCount() - 1) * GetSpacing();
        minSummaCellSize.y += (GetVerticalCellCount() - 1) * GetSpacing();

        minSummaCellSize.x += GetLeftPadding() + GetRightPadding();
        minSummaCellSize.y += GetTopPadding() + GetBottomPadding();

        ImVec2 minSize =
        {
            std::max(minSummaCellSize.x, GetMinSize().x),
            std::max(minSummaCellSize.y, GetMinSize().y)
        };

        for (auto& child : mWidgets) {
            if (child->GetSubType() == SubType::FRAME) {

                auto pFrame = dynamic_cast<TFrame*>(child);
                ImVec2 frameMinSize;
                if (pFrame->GetUseGrid()) {
                    frameMinSize = pFrame->GridCalculateMinSize();
                } else {
                    frameMinSize = pFrame->CalculateMinSize();
                }
                minSize.x = std::max(minSize.x, frameMinSize.x);
                minSize.y = std::max(minSize.y, frameMinSize.y);
            }
        }

        auto contentPadding = GetContentPadding();

        minSize.x += contentPadding.x + contentPadding.z;
        minSize.y += contentPadding.y + contentPadding.w;

        return minSize;
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::CalculateMinSize()
    {
        ImVec2 minSize = GetMinSize();
        for (auto& child : mWidgets) {
            if (child->GetSubType() == SubType::UNIT || child->GetSubType() == SubType::FRAME) {
                auto pUnit = dynamic_cast<TUnit*>(child);

                auto unitMinSize = GetUnitMinSize(pUnit, false);

                minSize.x = std::max(minSize.x, unitMinSize.x);
                minSize.y = std::max(minSize.y, unitMinSize.y);
            }
            if (child->GetSubType() == SubType::FRAME) {

                auto pFrame = dynamic_cast<TFrame*>(child);
                ImVec2 frameMinSize;
                if (pFrame->GetUseGrid()) {
                    pFrame->GridCalculateMinSize();
                } else {
                    pFrame->CalculateMinSize();
                }
                minSize.x = std::max(minSize.x, frameMinSize.x);
                minSize.y = std::max(minSize.y, frameMinSize.y);
            }
        }

        auto contentPadding = GetContentPadding();

        minSize.x += contentPadding.z;
        minSize.y += contentPadding.w;

        return minSize;
    }
    //---------------------------------------------------------------------------------------
    void TFrame::UpdateChildGeometry()
    {
        auto contentPadding = GetContentPadding();

        auto selfSize = ImVec2(GetSize().x - contentPadding.x - contentPadding.z, GetSize().y - contentPadding.y - contentPadding.w);
        auto contentOffset = ImVec2(contentPadding.x, contentPadding.y);

        for (auto& child : mWidgets) {
            if (child->GetSubType() == SubType::UNIT || child->GetSubType() == SubType::FRAME) {
                auto pUnit = dynamic_cast<TUnit*>(child);

                if (pUnit->IsAnyAnchor()) {
                    ImVec2 newPos = pUnit->GetPos();
                    ImVec2 newSize = pUnit->GetSize();

                    CalculateUnitGeometry(pUnit, contentOffset, selfSize, pUnit->GetSize(), newPos, newSize);

                    pUnit->SetPos(newPos);
                    pUnit->SetSize(newSize);
                }
            }
            if (child->GetSubType() == SubType::FRAME) {
                auto pFrame = dynamic_cast<TFrame*>(child);
                if (pFrame->GetUseGrid()) {
                    pFrame->GridUpdateChildGeometry();
                } else {
                    pFrame->UpdateChildGeometry();
                }
            }
        }
    }
    //---------------------------------------------------------------------------------------
    void TFrame::GridUpdateChildGeometry()
    {
        if (mCells.size() == 0) {
            return;
        }

        auto contentPadding = GetContentPadding();

        auto selfSize = ImVec2(GetSize().x - contentPadding.x - contentPadding.z, GetSize().y - contentPadding.y - contentPadding.w);
        auto contentOffset = ImVec2();


        for (auto& it : mCells) {
            auto& cell = it.second;

            auto child = cell.p;
            if (child == nullptr) {
                continue;
            }

            auto cellPos = CalculateCellPos(cell);
            auto cellSize = CalculateCellSize(cell);

            if (child->GetSubType() == SubType::UNIT || child->GetSubType() == SubType::FRAME) {
                auto pUnit = dynamic_cast<TUnit*>(child);

                ImVec2 newPos = { contentPadding.x, contentPadding.y };
                ImVec2 newSize = cellSize;
                // Не должен выходить за границу ячейки.
                // Приоритет размером ячейки выше якорей, мин/макс размеров.
                if (pUnit->IsAnyAnchor()) {

                    ImVec2 oldSize = cellSize;
                    if (pUnit->GetLeft().isUsed) {
                        oldSize.x -= pUnit->GetLeft().offset;
                    }
                    if (pUnit->GetRight().isUsed) {
                        oldSize.x -= pUnit->GetRight().offset;
                    }
                    if (pUnit->GetTop().isUsed) {
                        oldSize.y -= pUnit->GetTop().offset;
                    }
                    if (pUnit->GetBottom().isUsed) {
                        oldSize.y -= pUnit->GetBottom().offset;
                    }

                    oldSize.x = std::min(oldSize.x, pUnit->GetMaxSize().x);
                    oldSize.y = std::min(oldSize.y, pUnit->GetMaxSize().y);

                    CalculateUnitGeometry(pUnit, contentOffset, cellSize, oldSize, newPos, newSize);

                    pUnit->SetPos(newPos + cellPos);
                    pUnit->SetSize(newSize);
                } else {
                    newPos = cellPos;

                    auto unitMinSize = pUnit->GetMinSize();
                    auto unitMaxSize = pUnit->GetMaxSize();

                    newSize.x = std::max(newSize.x, unitMinSize.x);
                    newSize.y = std::max(newSize.y, unitMinSize.y);

                    newSize.x = std::min(newSize.x, unitMaxSize.x);
                    newSize.y = std::min(newSize.y, unitMaxSize.y);

                    if (newSize.x < cellSize.x) {
                        auto delta = cellSize.x - newSize.x;

                        switch (pUnit->GetHorizontalAlign()) {
                        case THorizontalAlign::Type::LEFT:
                            break;
                        case THorizontalAlign::Type::CENTER:
                            newPos.x += delta / 2;
                            break;
                        case THorizontalAlign::Type::RIGHT:
                            newPos.x += delta;
                            break;
                        }
                    }
                    if (newSize.y < cellSize.y) {
                        auto delta = cellSize.y - newSize.y;

                        switch (pUnit->GetVerticalAlign()) {
                        case TVerticalAlign::Type::TOP:
                            break;
                        case TVerticalAlign::Type::CENTER:
                            newPos.y += delta / 2;
                            break;
                        case TVerticalAlign::Type::BOTTOM:
                            newPos.y += delta;
                            break;
                        }
                    }

                    pUnit->SetPos(newPos);
                    pUnit->SetSize(newSize);
                }
            }
            if (child->GetSubType() == SubType::FRAME) {
                auto pFrame = dynamic_cast<TFrame*>(child);
                if (pFrame->GetUseGrid()) {
                    pFrame->GridUpdateChildGeometry();
                } else {
                    pFrame->UpdateChildGeometry();
                }
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

        auto contentPadding = GetContentPadding();

        pos.x += contentPadding.x;
        pos.y += contentPadding.y;

        return pos;
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::CalculateCellSize(const TCell& cell)
    {
        auto size = CalculateOneCellSize();

        size.x *= cell.size.width;
        size.y *= cell.size.height;

        return size;
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::CalculateOneCellSize()
    {
        auto contentPadding = GetContentPadding();

        auto selfSize = ImVec2(GetSize().x - contentPadding.x - contentPadding.z, GetSize().y - contentPadding.y - contentPadding.w);

        ImVec2 size;

        auto cellsWidth = selfSize.x - GetLeftPadding() - GetRightPadding() - (GetHorizontalCellCount() - 1) * GetSpacing();
        auto cellsHeight = selfSize.y - GetTopPadding() - GetBottomPadding() - (GetVerticalCellCount() - 1) * GetSpacing();

        size.x = cellsWidth / GetHorizontalCellCount();
        size.y = cellsHeight / GetVerticalCellCount();

        return size;
    }
    //---------------------------------------------------------------------------------------
    void TFrame::CalculateUnitGeometry(TUnit* pUnit, const ImVec2& contentOffset,
        const ImVec2& contentSize, const ImVec2& oldSize, ImVec2& newPos, ImVec2& newSize)
    {
        if (pUnit->GetLeft().isUsed && pUnit->GetRight().isUsed) {
            newSize.x = contentSize.x - pUnit->GetRight().offset - pUnit->GetLeft().offset;
            newPos.x = pUnit->GetLeft().offset;
        } else if (pUnit->GetRight().isUsed) {
            newPos.x = contentSize.x - pUnit->GetRight().offset - oldSize.x;
        }

        if (pUnit->GetTop().isUsed && pUnit->GetBottom().isUsed) {
            newSize.y = contentSize.y - pUnit->GetTop().offset - pUnit->GetBottom().offset;
            newPos.y = pUnit->GetTop().offset;
        } else if (pUnit->GetBottom().isUsed) {
            newPos.y = contentSize.y - pUnit->GetBottom().offset - oldSize.y;
        }

        auto unitMinSize = pUnit->GetMinSize();
        auto unitMaxSize = pUnit->GetMaxSize();

        newSize.x = std::max(newSize.x, unitMinSize.x);
        newSize.y = std::max(newSize.y, unitMinSize.y);

        if (pUnit->GetLeft().isUsed && pUnit->GetRight().isUsed) {
            if (newSize.x > unitMaxSize.x) {
                auto delta = newSize.x - unitMaxSize.x;
                newSize.x = unitMaxSize.x;

                switch (pUnit->GetHorizontalAlign()) {
                case THorizontalAlign::Type::LEFT:
                    break;
                case THorizontalAlign::Type::CENTER:
                    newPos.x += delta / 2;
                    break;
                case THorizontalAlign::Type::RIGHT:
                    newPos.x += delta;
                    break;
                }
            }
            newPos.x += contentOffset.x;
        }

        if (pUnit->GetTop().isUsed && pUnit->GetBottom().isUsed) {
            if (newSize.y > unitMaxSize.y) {
                auto delta = newSize.y - unitMaxSize.y;
                newSize.y = unitMaxSize.y;

                switch (pUnit->GetVerticalAlign()) {
                case TVerticalAlign::Type::TOP:
                    break;
                case TVerticalAlign::Type::CENTER:
                    newPos.y += delta / 2;
                    break;
                case TVerticalAlign::Type::BOTTOM:
                    newPos.y += delta;
                    break;
                }
            }
            newPos.y += contentOffset.y;
        }
    }
    //---------------------------------------------------------------------------------------
    ImVec4 TFrame::GetContentPadding() const
    {
        return { 0, 0, 0, 0 };
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::GetUnitMinSize(TUnit* pUnit, bool inGrid)
    {
        ImVec2 unitMinSize = pUnit->GetMinSize();
        if (pUnit->IsAnyAnchor()) {
            if (pUnit->GetLeft().isUsed && pUnit->GetRight().isUsed) {
                unitMinSize.x = pUnit->GetMinSize().x + pUnit->GetLeft().offset + pUnit->GetRight().offset;
            } else if (pUnit->GetRight().isUsed) {
                unitMinSize.x = pUnit->GetMinSize().x + pUnit->GetRight().offset;
            }

            if (pUnit->GetTop().isUsed && pUnit->GetBottom().isUsed) {
                unitMinSize.y = pUnit->GetMinSize().y + pUnit->GetTop().offset + pUnit->GetBottom().offset;
            } else if (pUnit->GetBottom().isUsed) {
                unitMinSize.y = pUnit->GetMinSize().y + pUnit->GetBottom().offset;
            }
        } else {
            if (inGrid) {
                unitMinSize = pUnit->GetMinSize();
            } else {
                unitMinSize = pUnit->GetPos() + pUnit->GetSize();
            }
        }

        return unitMinSize;
    }
    //---------------------------------------------------------------------------------------
}