/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PropertyManagerConfigs.h"

namespace nsTornadoEngine
{
    static const std::list<TArchetype> g_Archetypes =
    {
        {
            .typeName = "nsImGuiWidgets::TWidget",
            .parentNames = {},
            .properties =
            {
                "nsGuiWrapper::TTitleComponent",
                "nsGuiWrapper::TSizeComponent",
                "nsGuiWrapper::TPositionComponent",
                "nsGuiWrapper::TVisibilityComponent",
            },
        },
        {
            .typeName = "nsImGuiWidgets::TNode",
            .parentNames = {"nsImGuiWidgets::TWidget"},
            .properties =
            {
                "nsImGuiWidgets::TTextureReference",
                "nsImGuiWidgets::TTextureSize",
                "nsImGuiWidgets::TTextureUv"
            }
        },
        {
            .typeName = "nsImGuiWidgets::TMenuNode",
            .parentNames = {"nsImGuiWidgets::TNode"},
            .properties = {}
        },
        {
            .typeName = "nsImGuiWidgets::TSeparator",
            .parentNames = {"nsImGuiWidgets::TWidget"},
            .properties = {}
        },
        {
            .typeName = "nsImGuiWidgets::TTreeNode",
            .parentNames = {"nsImGuiWidgets::TNode"},
            .properties = {}
        },
        {
            .typeName = "nsImGuiWidgets::TPopupNode",
            .parentNames = {"nsImGuiWidgets::TNode"},
            .properties = {}
        },
        {
            .typeName = "nsImGuiWidgets::TUnit",
            .parentNames = {"nsImGuiWidgets::TWidget"},
            .properties =
            {
                "nsGuiWrapper::TAnchorComponent",
                "nsGuiWrapper::THorizontalAlignComponent",
                "nsGuiWrapper::TFocusComponent",
                "nsGuiWrapper::TMaxSizeComponent",
                "nsGuiWrapper::TMinSizeComponent",
                "nsGuiWrapper::TMinDistanceToParentComponent",
                "nsGuiWrapper::TVerticalAlignComponent"
            }
        },
        {
            .typeName = "nsImGuiWidgets::TProtoFrame",
            .parentNames = {"nsImGuiWidgets::TUnit"},
            .properties = {}
        },
        {
            .typeName = "nsImGuiWidgets::TFrame",
            .parentNames = {"nsImGuiWidgets::TProtoFrame"},
            .properties =
            {
                "nsGuiWrapper::TPaddingComponent",
                "nsGuiWrapper::TGridComponent",
                "nsGuiWrapper::TSpacingComponent"
            }
        },
        {
            .typeName = "nsImGuiWidgets::TWindow",
            .parentNames = {"nsImGuiWidgets::TFrame"},
            .properties = {}
        }
    };

    static const TRelativeProperties g_RelativeProperties =
    {
        .value = 
        {
            { "nsGuiWrapper::TTitleComponent",               "nsImGuiWidgets::TTitle" },
            { "nsGuiWrapper::TSizeComponent",                "nsImGuiWidgets::TSize" },
            { "nsGuiWrapper::TPositionComponent",            "nsImGuiWidgets::TPosition"},
            { "nsGuiWrapper::TVisibilityComponent",          "nsImGuiWidgets::TVisibility" },
            { "nsGuiWrapper::TAnchorComponent",              "nsImGuiWidgets::TAnchor" },
            { "nsGuiWrapper::THorizontalAlignComponent",     "nsImGuiWidgets::THorizontalAlign" },
            { "nsGuiWrapper::TFocusComponent",               "nsImGuiWidgets::TFocus" },
            { "nsGuiWrapper::TMaxSizeComponent",             "nsImGuiWidgets::TMaxSize" },
            { "nsGuiWrapper::TMinSizeComponent",             "nsImGuiWidgets::TMinSize" },
            { "nsGuiWrapper::TMinDistanceToParentComponent", "nsImGuiWidgets::TMinDistanceToParent" },
            { "nsGuiWrapper::TVerticalAlignComponent",       "nsImGuiWidgets::TVerticalAlign" },
            { "nsGuiWrapper::TTextureReferenceComponent",    "nsImGuiWidgets::TTextureReference" },
            { "nsGuiWrapper::TTextureSizeComponent",         "nsImGuiWidgets::TTextureSize" },
            { "nsGuiWrapper::TTextureUvComponent",           "nsImGuiWidgets::TTextureUv" },
        }
    };

    const std::list<TArchetype>& TPropertyManagerConfigs::GetArchetypes()
    {
        return g_Archetypes;
    }

    const TRelativeProperties& TPropertyManagerConfigs::GetRelativeProperties()
    {
        return g_RelativeProperties;
    }
}