/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/ImGuiCustom.h"

#include "ImGuiWidgets/Include/Helper.h"

using namespace ImGui;

namespace nsImGuiWidgets
{
    bool TImGuiCustom::TreeNodeExV(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt, 
        ImTextureID user_texture_id, const ImVec2& size)
    {
        ImGuiWindow* window = GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const char* label_end = g.TempBuffer.begin() + ImFormatString(g.TempBuffer.begin(), g.TempBuffer.size(), fmt);
        return TreeNodeBehavior(window->GetID(str_id), flags, g.TempBuffer.begin(), label_end, user_texture_id, size);
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    bool TImGuiCustom::MenuItem(const char* label, const char* shortcut, bool selected, bool enabled,
        ImTextureID user_texture_id, const ImVec2& size)
    {
        return MenuItemEx(label, NULL, shortcut, selected, enabled, user_texture_id, size);
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    bool TImGuiCustom::MenuItem(const char* label, const char* shortcut, bool* p_selected, bool enabled,
        ImTextureID user_texture_id, const ImVec2& size)
    {
        if (MenuItemEx(label, NULL, shortcut, p_selected ? *p_selected : false, enabled, user_texture_id, size)) {
            if (p_selected)
                *p_selected = !*p_selected;
            return true;
        }
        return false;
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    bool TImGuiCustom::MenuItemEx(const char* label, const char* icon, const char* shortcut, bool selected, bool enabled,
        ImTextureID user_texture_id, const ImVec2& size)
    {
        ImGuiWindow* window = GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        ImGuiStyle& style = g.Style;
        ImVec2 pos = window->DC.CursorPos;
        ImVec2 label_size = CalcTextSize(label, NULL, true);

        // We've been using the equivalent of ImGuiSelectableFlags_SetNavIdOnHover on all Selectable() since early Nav system days (commit 43ee5d73),
        // but I am unsure whether this should be kept at all. For now moved it to be an opt-in feature used by menus only.
        bool pressed;
        PushID(label);
        if (!enabled)
            BeginDisabled();
        const ImGuiSelectableFlags flags = ImGuiSelectableFlags_SelectOnRelease | ImGuiSelectableFlags_SetNavIdOnHover;
        const ImGuiMenuColumns* offsets = &window->DC.MenuColumns;
        if (window->DC.LayoutType == ImGuiLayoutType_Horizontal) {
            // Mimic the exact layout spacing of BeginMenu() to allow MenuItem() inside a menu bar, which is a little misleading but may be useful
            // Note that in this situation: we don't render the shortcut, we render a highlight instead of the selected tick mark.
            float w = label_size.x;
            window->DC.CursorPos.x += IM_FLOOR(style.ItemSpacing.x * 0.5f);
            ImVec2 text_pos(window->DC.CursorPos.x + offsets->OffsetLabel, window->DC.CursorPos.y + window->DC.CurrLineTextBaseOffset);
            PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(style.ItemSpacing.x * 2.0f, style.ItemSpacing.y));
            pressed = Selectable("", selected, flags, ImVec2(w, 0.0f));
            PopStyleVar();

            // Customized
            if (user_texture_id != nullptr) {
                RenderImage(window, user_texture_id, {text_pos.x, text_pos.y}, {text_pos.x + size.x, text_pos.y + size.y});
                text_pos.x += size.x + 1;
            }
            // Customized

            RenderText(text_pos, label);
            window->DC.CursorPos.x += IM_FLOOR(style.ItemSpacing.x * (-1.0f + 0.5f)); // -1 spacing to compensate the spacing added when Selectable() did a SameLine(). It would also work to call SameLine() ourselves after the PopStyleVar().
        } else {
            // Menu item inside a vertical menu
            // (In a typical menu window where all items are BeginMenu() or MenuItem() calls, extra_w will always be 0.0f.
            //  Only when they are other items sticking out we're going to add spacing, yet only register minimum width into the layout system.
            float icon_w = (icon && icon[0]) ? CalcTextSize(icon, NULL).x : 0.0f;
            float shortcut_w = (shortcut && shortcut[0]) ? CalcTextSize(shortcut, NULL).x : 0.0f;
            float checkmark_w = IM_FLOOR(g.FontSize * 1.20f);
            float min_w = window->DC.MenuColumns.DeclColumns(icon_w, label_size.x, shortcut_w, checkmark_w); // Feedback for next frame
            float stretch_w = ImMax(0.0f, GetContentRegionAvail().x - min_w);
            pressed = Selectable("", false, flags | ImGuiSelectableFlags_SpanAvailWidth, ImVec2(min_w, 0.0f));

            // Customized
            if (user_texture_id != nullptr) {
                RenderImage(window, user_texture_id, {pos.x, pos.y}, {pos.x + size.x, pos.y + size.y});
                pos.x += size.x + 1;
            }
            // Customized

            RenderText(pos + ImVec2(offsets->OffsetLabel, 0.0f), label);
            if (icon_w > 0.0f)
                RenderText(pos + ImVec2(offsets->OffsetIcon, 0.0f), icon);
            if (shortcut_w > 0.0f) {
                PushStyleColor(ImGuiCol_Text, style.Colors[ImGuiCol_TextDisabled]);
                RenderText(pos + ImVec2(offsets->OffsetShortcut + stretch_w, 0.0f), shortcut, NULL, false);
                PopStyleColor();
            }
            if (selected)
                RenderCheckMark(window->DrawList, pos + ImVec2(offsets->OffsetMark + stretch_w + g.FontSize * 0.40f, g.FontSize * 0.134f * 0.5f), GetColorU32(ImGuiCol_Text), g.FontSize * 0.866f);
        }
        IMGUI_TEST_ENGINE_ITEM_INFO(g.LastItemData.ID, label, g.LastItemData.StatusFlags | ImGuiItemStatusFlags_Checkable | (selected ? ImGuiItemStatusFlags_Checked : 0));
        if (!enabled)
            EndDisabled();
        PopID();

        return pressed;
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    void TImGuiCustom::RenderImage(ImGuiWindow* window, ImTextureID user_texture_id, const ImVec2& minPoint, const ImVec2& maxPoint)
    {
        ImRect bb(minPoint, maxPoint);
        window->DrawList->AddImage(user_texture_id, bb.Min, bb.Max);
    }
    //------------------------------------------------------------------------------------------------------------------------------------
    bool TImGuiCustom::TreeNodeBehavior(ImGuiID id, ImGuiTreeNodeFlags flags, const char* label, const char* label_end,
        ImTextureID user_texture_id, const ImVec2& size)
    {
        ImGuiWindow* window = GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const bool display_frame = (flags & ImGuiTreeNodeFlags_Framed) != 0;
        const ImVec2 padding = (display_frame || (flags & ImGuiTreeNodeFlags_FramePadding)) ? style.FramePadding : ImVec2(style.FramePadding.x, ImMin(window->DC.CurrLineTextBaseOffset, style.FramePadding.y));

        if (!label_end)
            label_end = FindRenderedTextEnd(label);
        const ImVec2 label_size = CalcTextSize(label, label_end, false);

        // We vertically grow up to current line height up the typical widget height.
        const float frame_height = ImMax(ImMin(window->DC.CurrLineSize.y, g.FontSize + style.FramePadding.y * 2), label_size.y + padding.y * 2);
        ImRect frame_bb;
        frame_bb.Min.x = (flags & ImGuiTreeNodeFlags_SpanFullWidth) ? window->WorkRect.Min.x : window->DC.CursorPos.x;
        frame_bb.Min.y = window->DC.CursorPos.y;
        frame_bb.Max.x = window->WorkRect.Max.x;
        frame_bb.Max.y = window->DC.CursorPos.y + frame_height;
        if (display_frame) {
            // Framed header expand a little outside the default padding, to the edge of InnerClipRect
            // (FIXME: May remove this at some point and make InnerClipRect align with WindowPadding.x instead of WindowPadding.x*0.5f)
            frame_bb.Min.x -= IM_FLOOR(window->WindowPadding.x * 0.5f - 1.0f);
            frame_bb.Max.x += IM_FLOOR(window->WindowPadding.x * 0.5f);
        }

        const float text_offset_x = g.FontSize + (display_frame ? padding.x * 3 : padding.x * 2);           // Collapser arrow width + Spacing
        const float text_offset_y = ImMax(padding.y, window->DC.CurrLineTextBaseOffset);                    // Latch before ItemSize changes it
        const float text_width = g.FontSize + (label_size.x > 0.0f ? label_size.x + padding.x * 2 : 0.0f);  // Include collapser
        ImVec2 text_pos(window->DC.CursorPos.x + text_offset_x, window->DC.CursorPos.y + text_offset_y);
        ItemSize(ImVec2(text_width, frame_height), padding.y);

        // For regular tree nodes, we arbitrary allow to click past 2 worth of ItemSpacing
        ImRect interact_bb = frame_bb;
        if (!display_frame && (flags & (ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_SpanFullWidth)) == 0)
            interact_bb.Max.x = frame_bb.Min.x + text_width + style.ItemSpacing.x * 2.0f;

        // Store a flag for the current depth to tell if we will allow closing this node when navigating one of its child.
        // For this purpose we essentially compare if g.NavIdIsAlive went from 0 to 1 between TreeNode() and TreePop().
        // This is currently only support 32 level deep and we are fine with (1 << Depth) overflowing into a zero.
        const bool is_leaf = (flags & ImGuiTreeNodeFlags_Leaf) != 0;
        bool is_open = TreeNodeBehaviorIsOpen(id, flags);
        if (is_open && !g.NavIdIsAlive && (flags & ImGuiTreeNodeFlags_NavLeftJumpsBackHere) && !(flags & ImGuiTreeNodeFlags_NoTreePushOnOpen))
            window->DC.TreeJumpToParentOnPopMask |= (1 << window->DC.TreeDepth);

        bool item_add = ItemAdd(interact_bb, id);
        g.LastItemData.StatusFlags |= ImGuiItemStatusFlags_HasDisplayRect;
        g.LastItemData.DisplayRect = frame_bb;

        if (!item_add) {
            if (is_open && !(flags & ImGuiTreeNodeFlags_NoTreePushOnOpen))
                TreePushOverrideID(id);
            IMGUI_TEST_ENGINE_ITEM_INFO(g.LastItemData.ID, label, g.LastItemData.StatusFlags | (is_leaf ? 0 : ImGuiItemStatusFlags_Openable) | (is_open ? ImGuiItemStatusFlags_Opened : 0));
            return is_open;
        }

        ImGuiButtonFlags button_flags = ImGuiTreeNodeFlags_None;
        if (flags & ImGuiTreeNodeFlags_AllowItemOverlap)
            button_flags |= ImGuiButtonFlags_AllowItemOverlap;
        if (!is_leaf)
            button_flags |= ImGuiButtonFlags_PressedOnDragDropHold;

        // We allow clicking on the arrow section with keyboard modifiers held, in order to easily
        // allow browsing a tree while preserving selection with code implementing multi-selection patterns.
        // When clicking on the rest of the tree node we always disallow keyboard modifiers.
        const float arrow_hit_x1 = (text_pos.x - text_offset_x) - style.TouchExtraPadding.x;
        const float arrow_hit_x2 = (text_pos.x - text_offset_x) + (g.FontSize + padding.x * 2.0f) + style.TouchExtraPadding.x;
        const bool is_mouse_x_over_arrow = (g.IO.MousePos.x >= arrow_hit_x1 && g.IO.MousePos.x < arrow_hit_x2);
        if (window != g.HoveredWindow || !is_mouse_x_over_arrow)
            button_flags |= ImGuiButtonFlags_NoKeyModifiers;

        // Open behaviors can be altered with the _OpenOnArrow and _OnOnDoubleClick flags.
        // Some alteration have subtle effects (e.g. toggle on MouseUp vs MouseDown events) due to requirements for multi-selection and drag and drop support.
        // - Single-click on label = Toggle on MouseUp (default, when _OpenOnArrow=0)
        // - Single-click on arrow = Toggle on MouseDown (when _OpenOnArrow=0)
        // - Single-click on arrow = Toggle on MouseDown (when _OpenOnArrow=1)
        // - Double-click on label = Toggle on MouseDoubleClick (when _OpenOnDoubleClick=1)
        // - Double-click on arrow = Toggle on MouseDoubleClick (when _OpenOnDoubleClick=1 and _OpenOnArrow=0)
        // It is rather standard that arrow click react on Down rather than Up.
        // We set ImGuiButtonFlags_PressedOnClickRelease on OpenOnDoubleClick because we want the item to be active on the initial MouseDown in order for drag and drop to work.
        if (is_mouse_x_over_arrow)
            button_flags |= ImGuiButtonFlags_PressedOnClick;
        else if (flags & ImGuiTreeNodeFlags_OpenOnDoubleClick)
            button_flags |= ImGuiButtonFlags_PressedOnClickRelease | ImGuiButtonFlags_PressedOnDoubleClick;
        else
            button_flags |= ImGuiButtonFlags_PressedOnClickRelease;

        bool selected = (flags & ImGuiTreeNodeFlags_Selected) != 0;
        const bool was_selected = selected;

        bool hovered, held;
        bool pressed = ButtonBehavior(interact_bb, id, &hovered, &held, button_flags);
        bool toggled = false;
        if (!is_leaf) {
            if (pressed && g.DragDropHoldJustPressedId != id) {
                if ((flags & (ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick)) == 0 || (g.NavActivateId == id))
                    toggled = true;
                if (flags & ImGuiTreeNodeFlags_OpenOnArrow)
                    toggled |= is_mouse_x_over_arrow && !g.NavDisableMouseHover; // Lightweight equivalent of IsMouseHoveringRect() since ButtonBehavior() already did the job
                if ((flags & ImGuiTreeNodeFlags_OpenOnDoubleClick) && g.IO.MouseDoubleClicked[0])
                    toggled = true;
            } else if (pressed && g.DragDropHoldJustPressedId == id) {
                IM_ASSERT(button_flags & ImGuiButtonFlags_PressedOnDragDropHold);
                if (!is_open) // When using Drag and Drop "hold to open" we keep the node highlighted after opening, but never close it again.
                    toggled = true;
            }

            if (g.NavId == id && g.NavMoveDir == ImGuiDir_Left && is_open) {
                toggled = true;
                NavMoveRequestCancel();
            }
            if (g.NavId == id && g.NavMoveDir == ImGuiDir_Right && !is_open) // If there's something upcoming on the line we may want to give it the priority?
            {
                toggled = true;
                NavMoveRequestCancel();
            }

            if (toggled) {
                is_open = !is_open;
                window->DC.StateStorage->SetInt(id, is_open);
                g.LastItemData.StatusFlags |= ImGuiItemStatusFlags_ToggledOpen;
            }
        }
        if (flags & ImGuiTreeNodeFlags_AllowItemOverlap)
            SetItemAllowOverlap();

        // In this branch, TreeNodeBehavior() cannot toggle the selection so this will never trigger.
        if (selected != was_selected) //-V547
            g.LastItemData.StatusFlags |= ImGuiItemStatusFlags_ToggledSelection;

        // Render
        const ImU32 text_col = GetColorU32(ImGuiCol_Text);
        ImGuiNavHighlightFlags nav_highlight_flags = ImGuiNavHighlightFlags_TypeThin;
        if (display_frame) {
            // Framed type
            const ImU32 bg_col = GetColorU32((held && hovered) ? ImGuiCol_HeaderActive : hovered ? ImGuiCol_HeaderHovered : ImGuiCol_Header);
            RenderFrame(frame_bb.Min, frame_bb.Max, bg_col, true, style.FrameRounding);
            RenderNavHighlight(frame_bb, id, nav_highlight_flags);
            if (flags & ImGuiTreeNodeFlags_Bullet)
                RenderBullet(window->DrawList, ImVec2(text_pos.x - text_offset_x * 0.60f, text_pos.y + g.FontSize * 0.5f), text_col);
            else if (!is_leaf)
                RenderArrow(window->DrawList, ImVec2(text_pos.x - text_offset_x + padding.x, text_pos.y), text_col, is_open ? ImGuiDir_Down : ImGuiDir_Right, 1.0f);
            else // Leaf without bullet, left-adjusted text
                text_pos.x -= text_offset_x;
            if (flags & ImGuiTreeNodeFlags_ClipLabelForTrailingButton)
                frame_bb.Max.x -= g.FontSize + style.FramePadding.x;

            if (g.LogEnabled)
                LogSetNextTextDecoration("###", "###");

            // Customized
            if (user_texture_id != nullptr) {
                RenderImage(window, user_texture_id, {text_pos.x, text_pos.y}, {text_pos.x + size.x, text_pos.y + size.y});
                text_pos.x += size.x + 1;
            }
            // Customized

            RenderTextClipped(text_pos, frame_bb.Max, label, label_end, &label_size);
        } else {
            // Unframed typed for tree nodes
            if (hovered || selected) {
                const ImU32 bg_col = GetColorU32((held && hovered) ? ImGuiCol_HeaderActive : hovered ? ImGuiCol_HeaderHovered : ImGuiCol_Header);
                RenderFrame(frame_bb.Min, frame_bb.Max, bg_col, false);
            }
            RenderNavHighlight(frame_bb, id, nav_highlight_flags);
            if (flags & ImGuiTreeNodeFlags_Bullet)
                RenderBullet(window->DrawList, ImVec2(text_pos.x - text_offset_x * 0.5f, text_pos.y + g.FontSize * 0.5f), text_col);
            else if (!is_leaf)
                RenderArrow(window->DrawList, ImVec2(text_pos.x - text_offset_x + padding.x, text_pos.y + g.FontSize * 0.15f), text_col, is_open ? ImGuiDir_Down : ImGuiDir_Right, 0.70f);
            if (g.LogEnabled)
                LogSetNextTextDecoration(">", NULL);

            // Customized
            if (user_texture_id != nullptr) {
                RenderImage(window, user_texture_id, {text_pos.x, text_pos.y}, {text_pos.x + size.x, text_pos.y + size.y});
                text_pos.x += size.x + 1;
            }
            // Customized

            RenderText(text_pos, label, label_end, false);
        }

        if (is_open && !(flags & ImGuiTreeNodeFlags_NoTreePushOnOpen))
            TreePushOverrideID(id);
        IMGUI_TEST_ENGINE_ITEM_INFO(id, label, g.LastItemData.StatusFlags | (is_leaf ? 0 : ImGuiItemStatusFlags_Openable) | (is_open ? ImGuiItemStatusFlags_Opened : 0));
        return is_open;
    }
    //------------------------------------------------------------------------------------------------------------------------------------
}
