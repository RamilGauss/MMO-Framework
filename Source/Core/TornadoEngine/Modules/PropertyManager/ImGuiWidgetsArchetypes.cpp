/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Modules/PropertyManager/ImGuiWidgetsArchetypes.h"

namespace nsTornadoEngine
{
    static const std::list<TArchetype> g_Archetypes =
    {
        {
            .typeName = "nsGuiWrapper::TWidgetComponent",
            .parentNames = {},
            .properties =
            {
                "nsGuiWrapper::TTitleComponent",
                "nsGuiWrapper::TSizeComponent",
                "nsGuiWrapper::TPositionComponent",
                "nsGuiWrapper::TVisibilityComponent",
                "nsGuiWrapper::TColorComponent",
            },
        },
        {
            .typeName = "nsGuiWrapper::TNodeComponent",
            .parentNames = {"nsGuiWrapper::TWidgetComponent"},
            .properties =
            {
                "nsGuiWrapper::TTextureReferenceComponent",
                "nsGuiWrapper::TTextureUvComponent",
            }
        },
        {
            .typeName = "nsGuiWrapper::TMenuNodeComponent",
            .parentNames = {"nsGuiWrapper::TNodeComponent"},
            .properties = {}
        },
        {
            .typeName = "nsGuiWrapper::TSeparatorComponent",
            .parentNames = {"nsGuiWrapper::TWidgetComponent"},
            .properties = {}
        },
        {
            .typeName = "nsGuiWrapper::TTreeNodeComponent",
            .parentNames = {"nsGuiWrapper::TNodeComponent"},
            .properties = {}
        },
        {
            .typeName = "nsGuiWrapper::TPopupNodeComponent",
            .parentNames = {"nsGuiWrapper::TNodeComponent"},
            .properties = {}
        },
        {
            .typeName = "nsGuiWrapper::TUnitComponent",
            .parentNames = {"nsGuiWrapper::TWidgetComponent"},
            .properties =
            {
                "nsGuiWrapper::TAnchorsComponent",
                "nsGuiWrapper::THorizontalAlignComponent",
                "nsGuiWrapper::TFocusComponent",
                "nsGuiWrapper::TMaxSizeComponent",
                "nsGuiWrapper::TMinDistanceToParentComponent",
                "nsGuiWrapper::TMinSizeComponent",
                "nsGuiWrapper::TVerticalAlignComponent",
            }
        },
        {
            .typeName = "nsGuiWrapper::TProtoFrameComponent",
            .parentNames = {"nsGuiWrapper::TUnitComponent"},
            .properties = {}
        },
        {
            .typeName = "nsGuiWrapper::TFrameComponent",
            .parentNames = {"nsGuiWrapper::TProtoFrameComponent"},
            .properties =
            {
                "nsGuiWrapper::TPaddingComponent",
                "nsGuiWrapper::TGridComponent",
                "nsGuiWrapper::TSpacingComponent"
            }
        },
        {
            .typeName = "nsGuiWrapper::TMainWindowComponent",
            .parentNames = {"nsGuiWrapper::TProtoFrameComponent"},
            .properties =
            {
            }
        },
        {
            .typeName = "nsGuiWrapper::TWindowComponent",
            .parentNames = {"nsGuiWrapper::TFrameComponent"},
            .properties = {}
        }
    };

    static const TRelativeProperties g_RelativeProperties =
    {
        .componentType =
        {
            {"nsGuiWrapper::TWidgetComponent",               "nsImGuiWidgets::TWidget"},
            {"nsGuiWrapper::TUnitComponent",                 "nsImGuiWidgets::TUnit"},
            {"nsGuiWrapper::TProtoFrameComponent",           "nsImGuiWidgets::TTProtoFrame"},
            {"nsGuiWrapper::TFrameComponent",                "nsImGuiWidgets::TFrame"},
            {"nsGuiWrapper::TWindowComponent",               "nsImGuiWidgets::TWindow"},
            {"nsGuiWrapper::TDialogComponent",               "nsImGuiWidgets::TDialog"},
            {"nsGuiWrapper::TMainWindowComponent",           "nsImGuiWidgets::TMainWindow"},
                                                             
            {"nsGuiWrapper::TPopupNodeComponent",            "nsImGuiWidgets::TPopupNode"},
            {"nsGuiWrapper::TMenuNodeComponent",             "nsImGuiWidgets::TMenuNode"},
            {"nsGuiWrapper::TTreeViewComponent",             "nsImGuiWidgets::TTreeView"},
            {"nsGuiWrapper::TTreeNodeComponent",             "nsImGuiWidgets::TTreeNode"},
            {"nsGuiWrapper::TToolTipComponent",             "nsImGuiWidgets::TToolTip"},
        
            {"nsGuiWrapper::TSpacingComponent",              "nsImGuiWidgets::TSpacing"},
            //{"nsGuiWrapper::T",                              "nsImGuiWidgets::T"},
            //{"nsGuiWrapper::T",                              "nsImGuiWidgets::T"},
            //{"nsGuiWrapper::T",                              "nsImGuiWidgets::T"},

            { "nsGuiWrapper::TAnchorsComponent",             "nsImGuiWidgets::TAnchors" },
            { "nsGuiWrapper::TColorComponent",               "nsImGuiWidgets::TColor" },
            { "nsGuiWrapper::TFocusComponent",               "nsImGuiWidgets::TFocus" },
            { "nsGuiWrapper::TGridComponent",                "nsImGuiWidgets::TGrid"},
            { "nsGuiWrapper::THorizontalAlignComponent",     "nsImGuiWidgets::THorizontalAlign" },
            { "nsGuiWrapper::TMaxSizeComponent",             "nsImGuiWidgets::TMaxSize" },
            { "nsGuiWrapper::TMinDistanceToParentComponent", "nsImGuiWidgets::TMinDistanceToParent" },
            { "nsGuiWrapper::TMinSizeComponent",             "nsImGuiWidgets::TMinSize" },
            { "nsGuiWrapper::TPaddingComponent",             "nsImGuiWidgets::TPadding"},
            { "nsGuiWrapper::TPositionComponent",            "nsImGuiWidgets::TPosition"},

            { "nsGuiWrapper::TSizeComponent",                "nsImGuiWidgets::TSize" },
            { "nsGuiWrapper::TTitleComponent",               "nsImGuiWidgets::TTitle" },
            { "nsGuiWrapper::TVisibilityComponent",          "nsImGuiWidgets::TVisibility" },
            { "nsGuiWrapper::TVerticalAlignComponent",       "nsImGuiWidgets::TVerticalAlign" },
            { "nsGuiWrapper::TTextureReferenceComponent",    "nsImGuiWidgets::TTextureReference" },
            { "nsGuiWrapper::TTextureSizeComponent",         "nsImGuiWidgets::TTextureSize" },
            { "nsGuiWrapper::TTextureUvComponent",           "nsImGuiWidgets::TTextureUv" },
        }
    };

    void TImGuiWidgetsArchetypes::GetArchetypes(std::list<TArchetype>& archetypes)
    {
        archetypes.insert(archetypes.begin(), g_Archetypes.begin(), g_Archetypes.end());
    }

    void TImGuiWidgetsArchetypes::GetRelativeProperties(TRelativeProperties& relativeProperties)
    {
        relativeProperties.componentType.insert(g_RelativeProperties.componentType);
    }
}