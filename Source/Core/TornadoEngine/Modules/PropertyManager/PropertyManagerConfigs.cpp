/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PropertyManagerConfigs.h"

namespace nsTornadoEngine
{
    static std::list<TTypeDependency> g_Configs =
    {
        {
            .typeName = "nsImGuiWidgets::TWidget",
            .parentComponentNames = {},
            .properties = 
            {
                "nsGuiWrapper::TTitleComponent",
                "nsGuiWrapper::TSizeComponent",
                "nsGuiWrapper::TPositionComponent",
                "nsGuiWrapper::TVisibilityComponent"
            },
        },
        {
            .typeName = "nsImGuiWidgets::TNode",
            .parentComponentNames = {"nsImGuiWidgets::TWidget"},
            .properties =
            {
                "nsGuiWrapper::TTextureReference",
                "nsGuiWrapper::TTextureSize",
                "nsGuiWrapper::TTextureUv"
            }
        },
        {
            .typeName = "nsImGuiWidgets::TMenuNode",
            .parentComponentNames = {"nsImGuiWidgets::TNode"},
            .properties = {}
        },
        {
            .typeName = "nsImGuiWidgets::TSeparator",
            .parentComponentNames = {"nsImGuiWidgets::TWidget"},
            .properties = {}
        },
        {
            .typeName = "nsImGuiWidgets::TTreeNode",
            .parentComponentNames = {"nsImGuiWidgets::TNode"},
            .properties = {}
        },
        {
            .typeName = "nsImGuiWidgets::TPopupNode",
            .parentComponentNames = {"nsImGuiWidgets::TNode"},
            .properties = {}
        },
        {
            .typeName = "nsImGuiWidgets::TUnit",
            .parentComponentNames = {"nsImGuiWidgets::TWidget"},
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
            .parentComponentNames = {"nsImGuiWidgets::TUnit"},
            .properties = {}
        },
        {
            .typeName = "nsImGuiWidgets::TFrame",
            .parentComponentNames = {"nsImGuiWidgets::TProtoFrame"},
            .properties = 
            {
                "nsGuiWrapper::TPadding",
                "nsGuiWrapper::TGrid",
                "nsGuiWrapper::TSpacing"
            }
        },
        {
            .typeName = "nsImGuiWidgets::TWindow",
            .parentComponentNames = {"nsImGuiWidgets::TFrame"},
            .properties = {}
        }
    };

    const std::list<TTypeDependency>& TPropertyManagerConfigs::GetConfig()
    {
        return g_Configs;
    }
}