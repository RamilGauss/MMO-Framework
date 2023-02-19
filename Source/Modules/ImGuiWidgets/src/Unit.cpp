/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Unit.h"

#include <imgui_internal.h>

#include "Helper.h"

using namespace nsImGuiWidgets;
using namespace nsGraphicEngine;

//------------------------------------------------------------------------
void TUnit::Render()
{
    if (!mIsShown) {
        return;
    }

    BeginRender();
    RenderInheritance();
    EndRender();
}
//------------------------------------------------------------------------
void TUnit::BeginRender()
{
    ImGui::SetCursorPos(GetPosition());

    if (GetSubType() == SubType::UNIT) {
        ImGui::PushID(GetId());
    }
}
//------------------------------------------------------------------------
void TUnit::EndRender()
{
    if (GetSubType() != SubType::UNIT) {
        return;
    }

    mIdFromWindow = ImGui::GetCurrentWindow()->GetID(GetTitle().c_str());

    ImGui::PopID();

    auto activeId = ImGui::GetActiveID();
    auto focusId = ImGui::GetFocusID();
    auto IsfreshFocused = (activeId == mIdFromWindow);
    
    SetFocused(IsfreshFocused);
}
//------------------------------------------------------------------------
TWidget::SubType TUnit::GetSubType() const
{
    return SubType::UNIT;
}
//------------------------------------------------------------------------
ImVec2 TUnit::CalculateMinSizeInGrid() const
{
    ImVec2 unitMinSize = GetMinSize();

    if (GetLeftAnchor().isUsed) {
        unitMinSize.x += GetLeftAnchor().offset;
    } else {
        unitMinSize.x += GetLeftMinDistance();
    }

    if (GetRightAnchor().isUsed) {
        unitMinSize.x += GetRightAnchor().offset;
    } else {
        unitMinSize.x += GetRightMinDistance();
    }

    if (GetTopAnchor().isUsed) {
        unitMinSize.y += GetTopAnchor().offset;
    } else {
        unitMinSize.y += GetTopMinDistance();
    }

    if (GetBottomAnchor().isUsed) {
        unitMinSize.y += GetBottomAnchor().offset;
    } else {
        unitMinSize.y += GetBottomMinDistance();
    }

    return unitMinSize;
}
//------------------------------------------------------------------------
ImVec2 TUnit::CalculateMinSizeInFree() const
{
    ImVec2 unitMinSize = GetMinSize();
    // Полной покрытие
    if (GetLeftAnchor().isUsed && GetRightAnchor().isUsed) {
        unitMinSize.x += GetLeftAnchor().offset + GetRightAnchor().offset;
    }

    if (GetTopAnchor().isUsed && GetBottomAnchor().isUsed) {
        unitMinSize.y += GetTopAnchor().offset + GetBottomAnchor().offset;
    }

    // Частичное покрытие
    if (GetLeftAnchor().isUsed && !GetRightAnchor().isUsed) {
        unitMinSize.x = GetLeftAnchor().offset + GetSize().x + GetRightMinDistance();
    }
    if (!GetLeftAnchor().isUsed && GetRightAnchor().isUsed) {
        unitMinSize.x = GetLeftMinDistance() + GetSize().x + GetRightAnchor().offset;
    }

    if (GetTopAnchor().isUsed && !GetBottomAnchor().isUsed) {
        unitMinSize.y = GetTopAnchor().offset + GetSize().y + GetBottomMinDistance();
    }
    if (!GetTopAnchor().isUsed && GetBottomAnchor().isUsed) {
        unitMinSize.y = GetTopMinDistance() + GetSize().y + GetBottomAnchor().offset;
    }

    // !IsAnyAnchor по каждой из осей
    if (!GetLeftAnchor().isUsed && !GetRightAnchor().isUsed) {
        unitMinSize.x = GetPosition().x + GetSize().x + GetRightMinDistance();
    }

    if (!GetTopAnchor().isUsed && !GetBottomAnchor().isUsed) {
        unitMinSize.y = GetPosition().y + GetSize().y + GetBottomMinDistance();
    }

    return unitMinSize;
}
//------------------------------------------------------------------------
void TUnit::UpdateGeometryInGrid(const ImVec2& offset, const ImVec2& contentSize)
{
    ImVec2 newPos = { 0,0 };
    ImVec2 newSize = contentSize;

    // X
    if (GetLeftAnchor().isUsed && GetRightAnchor().isUsed) {
        newPos.x = GetLeftAnchor().offset;
        newSize.x -= GetLeftAnchor().offset + GetRightAnchor().offset;

        if (newSize.x > GetMaxSize().x) {
            auto delta = newSize.x - GetMaxSize().x;
            newSize.x = GetMaxSize().x;
            switch (GetHorizontalAlign()) {
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
    }
    if (GetLeftAnchor().isUsed && !GetRightAnchor().isUsed) {
        newPos.x = GetLeftAnchor().offset;
        newSize.x -= GetLeftAnchor().offset + GetRightMinDistance();

        newSize.x = std::max(newSize.x, GetMinSize().x);
    }
    if (!GetLeftAnchor().isUsed && GetRightAnchor().isUsed) {
        newSize.x -= GetLeftMinDistance() + GetRightAnchor().offset;
        
        newSize.x = std::max(newSize.x, GetMinSize().x);
        newPos.x = contentSize.x - newSize.x;
    }
    if (!GetLeftAnchor().isUsed && !GetRightAnchor().isUsed) {
        newPos.x = GetLeftMinDistance();
        newSize.x -= GetLeftMinDistance() + GetRightMinDistance();

        if (newSize.x > GetMaxSize().x) {
            auto delta = newSize.x - GetMaxSize().x;
            newSize.x = GetMaxSize().x;
            switch (GetHorizontalAlign()) {
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
    }    
    // Y
    if (GetTopAnchor().isUsed && GetBottomAnchor().isUsed) {
        newPos.y = GetTopAnchor().offset;
        newSize.y -= GetTopAnchor().offset + GetBottomAnchor().offset;

        if (newSize.y > GetMaxSize().y) {
            auto delta = newSize.y - GetMaxSize().y;
            newSize.y = GetMaxSize().y;
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
    }
    if (GetTopAnchor().isUsed && !GetBottomAnchor().isUsed) {
        newPos.y = GetTopAnchor().offset;
        newSize.y -= GetTopAnchor().offset + GetBottomMinDistance();

        newSize.y = std::max(newSize.y, GetMinSize().y);
    }
    if (!GetTopAnchor().isUsed && GetBottomAnchor().isUsed) {
        newSize.y -= GetTopMinDistance() + GetBottomAnchor().offset;

        newSize.y = std::max(newSize.y, GetMinSize().y);
        newPos.y = contentSize.y - newSize.y;
    }
    if (!GetTopAnchor().isUsed && !GetBottomAnchor().isUsed) {
        newPos.y = GetBottomMinDistance();
        newSize.y -= GetTopMinDistance() + GetBottomMinDistance();

        if (newSize.y > GetMaxSize().y) {
            auto delta = newSize.y - GetMaxSize().y;
            newSize.y = GetMaxSize().y;
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
    }
    // Set up
    newPos += offset;

    SetPosition(newPos);
    SetSize(newSize);
}
//------------------------------------------------------------------------
void TUnit::UpdateGeometryInFree(const ImVec2& contentSize)
{
    ImVec2 newPos = { 0,0 };
    ImVec2 newSize = GetSize();

    // X
    if (GetLeftAnchor().isUsed && GetRightAnchor().isUsed) {
        newPos.x = GetLeftAnchor().offset;
        newSize.x = contentSize.x - GetLeftAnchor().offset - GetRightAnchor().offset;

        if (newSize.x > GetMaxSize().x) {
            auto delta = newSize.x - GetMaxSize().x;
            newSize.x = GetMaxSize().x;
            switch (GetHorizontalAlign()) {
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
    }
    if (GetLeftAnchor().isUsed && !GetRightAnchor().isUsed) {
        newPos.x = GetLeftAnchor().offset;
    }
    if (!GetLeftAnchor().isUsed && GetRightAnchor().isUsed) {
        newPos.x = contentSize.x - newSize.x - GetRightAnchor().offset;
    }
    // Y
    if (GetTopAnchor().isUsed && GetBottomAnchor().isUsed) {
        newPos.y = GetTopAnchor().offset;
        newSize.y = contentSize.y - GetTopAnchor().offset - GetBottomAnchor().offset;

        if (newSize.y > GetMaxSize().y) {
            auto delta = newSize.y - GetMaxSize().y;
            newSize.y = GetMaxSize().y;
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
    }
    if (GetTopAnchor().isUsed && !GetBottomAnchor().isUsed) {
        newPos.y = GetTopAnchor().offset;
    }
    if (!GetTopAnchor().isUsed && GetBottomAnchor().isUsed) {
        newPos.y = contentSize.y - newSize.y - GetBottomAnchor().offset;
    }

    // Set up
    if (!IsAnyAnchor()) {
        newPos = GetPosition();
    }

    SetPosition(newPos);
    SetSize(newSize);
}
//------------------------------------------------------------------------
