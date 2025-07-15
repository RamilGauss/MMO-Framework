/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/DockTypeHelper.h"

using namespace nsImGuiWidgets;

ImGuiAxis TDockTypeHelper::ToImGui(TDockNode::Type type)
{
    switch (type) {
        case TDockNode::Type::TAB:
            return ImGuiAxis::ImGuiAxis_None;
        case TDockNode::Type::X_SPLIT:
            return ImGuiAxis::ImGuiAxis_X;
        case TDockNode::Type::Y_SPLIT:
            return ImGuiAxis::ImGuiAxis_Y;
    }
    return ImGuiAxis::ImGuiAxis_None;
}
//------------------------------------------------------------------------------
TDockNode::Type TDockTypeHelper::FromImGui(ImGuiAxis type)
{
    switch (type) {
        case ImGuiAxis::ImGuiAxis_None:
            return TDockNode::Type::TAB;
        case ImGuiAxis::ImGuiAxis_X:
            return TDockNode::Type::X_SPLIT;
        case ImGuiAxis::ImGuiAxis_Y:
            return TDockNode::Type::Y_SPLIT;
    }
    return TDockNode::Type::TAB;
}
//------------------------------------------------------------------------------
