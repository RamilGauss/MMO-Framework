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
        ImVec2 minSize = GetMinSize();
        return minSize;
    }
    //---------------------------------------------------------------------------------------
    ImVec2 TFrame::CalculateMinSize()
    {
        ImVec2 minSize = GetMinSize();
        for (auto& child : mWidgets) {
            if (child->GetSubType() == SubType::UNIT || child->GetSubType() == SubType::FRAME) {
                auto pUnit = dynamic_cast<TUnit*>(child);

                if (pUnit->IsAnyAnchor()) {
                    auto unitMinSize = pUnit->GetPos() + pUnit->GetSize();
                    minSize.x = std::max(minSize.x, unitMinSize.x);
                    minSize.y = std::max(minSize.y, unitMinSize.y);
                } else {

                }
            }
            if (child->GetSubType() == SubType::FRAME) {
                auto pFrame = dynamic_cast<TFrame*>(child);
                auto frameMinSize = pFrame->CalculateMinSize();
                minSize.x = std::max(minSize.x, frameMinSize.x);
                minSize.y = std::max(minSize.y, frameMinSize.y);
            }
        }

        return minSize;
    }
    //---------------------------------------------------------------------------------------
    void TFrame::UpdateChildGeometry()
    {
        for (auto& child : mWidgets) {
            if (child->GetSubType() == SubType::UNIT || child->GetSubType() == SubType::FRAME) {
                auto pUnit = dynamic_cast<TUnit*>(child);

                if (pUnit->IsAnyAnchor()) {
                    ImVec2 newPos;
                    ImVec2 newSize;

                    if (pUnit->GetLeft().isUsed && pUnit->GetRight().isUsed) {
                        // Менять размер
                        newSize.x = GetSize().x - pUnit->GetRight().offset - pUnit->GetLeft().offset;
                    } else if (pUnit->GetRight().isUsed) {
                        // менять позицию
                        newPos.x = pUnit->GetRight().offset;
                    }

                    if (pUnit->GetTop().isUsed && pUnit->GetBottom().isUsed) {
                        // Менять размер
                        newSize.y = GetSize().y - pUnit->GetTop().offset - pUnit->GetBottom().offset;
                    } else if (pUnit->GetBottom().isUsed) {
                        // менять позицию
                        newPos.y = pUnit->GetBottom().offset;
                    }

                    auto unitMinSize = pUnit->GetMinSize();
                    auto unitMaxSize = pUnit->GetMaxSize();

                    newSize.x = std::max(newSize.x, unitMinSize.x);
                    newSize.y = std::max(newSize.y, unitMinSize.y);

                    if (newSize.x > unitMaxSize.x) {
                        auto delta = newSize.x - unitMaxSize.x;
                        newSize.x = unitMaxSize.x;

                        switch (GetHorizontalAlign()) {
                        case THorizontalAlign::Type::LEFT:
                            break;
                        case THorizontalAlign::Type::CENTER:
                            newPos.x += delta / 2;
                            break;
                        case THorizontalAlign::Type::RIGHT:
                            newPos.x = delta;
                            break;
                        }
                    }

                    if (newSize.y > unitMaxSize.y) {
                        auto delta = newSize.y - unitMaxSize.y;
                        newSize.y = unitMaxSize.y;

                        switch (GetVerticalAlign()) {
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
    void TFrame::GridUpdateChildGeometry()
    {
        for (auto& child : mWidgets) {
            if (child->GetSubType() == SubType::UNIT || child->GetSubType() == SubType::FRAME) {
                auto pFrame = dynamic_cast<TFrame*>(child);


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

}