/*
Core Component
*/
// ReflectionCodeGenerator version 2.4.2, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_09_17 10:25:20.623
	
#include "ImGuiWidgetsDynamicCaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

std::vector<std::vector<TImGuiWidgetsDynamicCaster::Data>> TImGuiWidgetsDynamicCaster::mDataVector;
std::map<int, std::set<int>> TImGuiWidgetsDynamicCaster::mRttiCombinations;

template <typename FromType, typename ToType>
ToType* SmartCast(void* p)
{
    if constexpr (std::is_base_of<ToType, FromType>::value) {
        return dynamic_cast<ToType*>(static_cast<FromType*>(p));
    }
    if constexpr (std::is_polymorphic<FromType>() && std::is_polymorphic<ToType>()) {
        return dynamic_cast<ToType*>(static_cast<FromType*>(p));
    }
    return reinterpret_cast<ToType*>(static_cast<FromType*>(p));
}

void TImGuiWidgetsDynamicCaster::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, std::map<int, Data>> m;
    
    std::map<int, Data> nsImGuiWidgets_TAnchors_Map;
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TAnchors_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TAnchors_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TAnchors>(p); };
    auto nsImGuiWidgets_TAnchors_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TAnchors_Map.insert({ nsImGuiWidgets_TAnchors_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TAnchors_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    m.insert({ nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TAnchors_Map });
    
    std::map<int, Data> nsImGuiWidgets_TButton_Map;
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TButton_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TButton_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TButton>(p); };
    auto nsImGuiWidgets_TButton_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TButton_Map.insert({ nsImGuiWidgets_TButton_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TButton_nsImGuiWidgets_TWidget_Data });
    
    auto nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    m.insert({ nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TButton_Map });
    
    std::map<int, Data> nsImGuiWidgets_TCheckBox_Map;
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TCheckBoxValue_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TCheckBoxValue_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBoxValue, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TCheckBoxValue_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBoxValue>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TCheckBoxValue_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TCheckBoxValue_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TCheckBox>(p); };
    auto nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TCheckBox_Map.insert({ nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TCheckBox_nsImGuiWidgets_TWidget_Data });
    
    auto nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    m.insert({ nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TCheckBox_Map });
    
    std::map<int, Data> nsImGuiWidgets_TCheckBoxValue_Map;
    
    Data nsImGuiWidgets_TCheckBoxValue_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TCheckBoxValue_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TCheckBoxValue>(p); };
    auto nsImGuiWidgets_TCheckBoxValue_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TCheckBoxValue_Map.insert({ nsImGuiWidgets_TCheckBoxValue_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TCheckBoxValue_nsImGuiWidgets_TCheckBox_Data });
    
    auto nsImGuiWidgets_TCheckBoxValue_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBoxValue>();
    
    m.insert({ nsImGuiWidgets_TCheckBoxValue_rtti, nsImGuiWidgets_TCheckBoxValue_Map });
    
    std::map<int, Data> nsImGuiWidgets_TColor_Map;
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TMenuNode_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TMenuNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMenuNode, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TMenuNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TMenuNode_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TMenuNode_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TPopupNode_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TPopupNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPopupNode, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TPopupNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TPopupNode_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TPopupNode_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TSeparator_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TSeparator_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSeparator, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TSeparator_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSeparator>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TSeparator_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TSeparator_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TTreeNode_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TTreeNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeNode, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TTreeNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TTreeNode_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TTreeNode_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TColor_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TColor_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TColor>(p); };
    auto nsImGuiWidgets_TColor_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TColor_Map.insert({ nsImGuiWidgets_TColor_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TColor_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    m.insert({ nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TColor_Map });
    
    std::map<int, Data> nsImGuiWidgets_TComboBox_Map;
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TComboBoxCurrentIndex_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TComboBoxCurrentIndex_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBoxCurrentIndex, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TComboBoxCurrentIndex_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBoxCurrentIndex>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TComboBoxCurrentIndex_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TComboBoxCurrentIndex_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TComboBoxItems_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TComboBoxItems_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBoxItems, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TComboBoxItems_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBoxItems>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TComboBoxItems_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TComboBoxItems_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TComboBox_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TComboBox_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TComboBox>(p); };
    auto nsImGuiWidgets_TComboBox_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TComboBox_Map.insert({ nsImGuiWidgets_TComboBox_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TComboBox_nsImGuiWidgets_TWidget_Data });
    
    auto nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    m.insert({ nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TComboBox_Map });
    
    std::map<int, Data> nsImGuiWidgets_TComboBoxCurrentIndex_Map;
    
    Data nsImGuiWidgets_TComboBoxCurrentIndex_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TComboBoxCurrentIndex_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TComboBoxCurrentIndex>(p); };
    auto nsImGuiWidgets_TComboBoxCurrentIndex_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TComboBoxCurrentIndex_Map.insert({ nsImGuiWidgets_TComboBoxCurrentIndex_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TComboBoxCurrentIndex_nsImGuiWidgets_TComboBox_Data });
    
    auto nsImGuiWidgets_TComboBoxCurrentIndex_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBoxCurrentIndex>();
    
    m.insert({ nsImGuiWidgets_TComboBoxCurrentIndex_rtti, nsImGuiWidgets_TComboBoxCurrentIndex_Map });
    
    std::map<int, Data> nsImGuiWidgets_TComboBoxItems_Map;
    
    Data nsImGuiWidgets_TComboBoxItems_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TComboBoxItems_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TComboBoxItems>(p); };
    auto nsImGuiWidgets_TComboBoxItems_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TComboBoxItems_Map.insert({ nsImGuiWidgets_TComboBoxItems_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TComboBoxItems_nsImGuiWidgets_TComboBox_Data });
    
    auto nsImGuiWidgets_TComboBoxItems_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBoxItems>();
    
    m.insert({ nsImGuiWidgets_TComboBoxItems_rtti, nsImGuiWidgets_TComboBoxItems_Map });
    
    std::map<int, Data> nsImGuiWidgets_TDialog_Map;
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TGrid_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TGrid_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TGrid, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TGrid_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TGrid>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TGrid_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TGrid_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TPadding_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TPadding_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPadding, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TPadding_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPadding>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TPadding_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TPadding_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TSpacing_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TSpacing_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSpacing, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TSpacing_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSpacing>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TSpacing_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TSpacing_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TDialog_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TDialog_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TDialog>(p); };
    auto nsImGuiWidgets_TDialog_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TDialog_Map.insert({ nsImGuiWidgets_TDialog_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TDialog_nsImGuiWidgets_TWidgetContainer_Data });
    
    auto nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    m.insert({ nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TDialog_Map });
    
    std::map<int, Data> nsImGuiWidgets_TDockNode_Map;
    
    Data nsImGuiWidgets_TDockNode_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TDockNode_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TDockNode>(p); };
    auto nsImGuiWidgets_TDockNode_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TDockNode_Map.insert({ nsImGuiWidgets_TDockNode_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TDockNode_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TDockNode_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TDockNode_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TDockNode>(p); };
    auto nsImGuiWidgets_TDockNode_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TDockNode_Map.insert({ nsImGuiWidgets_TDockNode_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TDockNode_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TDockNode_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TDockNode_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TDockNode>(p); };
    auto nsImGuiWidgets_TDockNode_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TDockNode_Map.insert({ nsImGuiWidgets_TDockNode_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TDockNode_nsImGuiWidgets_TSize_Data });
    
    auto nsImGuiWidgets_TDockNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDockNode>();
    
    m.insert({ nsImGuiWidgets_TDockNode_rtti, nsImGuiWidgets_TDockNode_Map });
    
    std::map<int, Data> nsImGuiWidgets_TFocus_Map;
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TFocus_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TFocus_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TFocus>(p); };
    auto nsImGuiWidgets_TFocus_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TFocus_Map.insert({ nsImGuiWidgets_TFocus_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TFocus_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    m.insert({ nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TFocus_Map });
    
    std::map<int, Data> nsImGuiWidgets_TFrame_Map;
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TGrid_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TGrid_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TGrid, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TGrid_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TGrid>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TGrid_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TGrid_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TPadding_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TPadding_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPadding, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TPadding_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPadding>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TPadding_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TPadding_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TSpacing_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TSpacing_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSpacing, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TSpacing_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSpacing>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TSpacing_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TSpacing_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TWidgetContainer_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TFrame_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TFrame_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TFrame>(p); };
    auto nsImGuiWidgets_TFrame_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TFrame_Map.insert({ nsImGuiWidgets_TFrame_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TFrame_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    m.insert({ nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TFrame_Map });
    
    std::map<int, Data> nsImGuiWidgets_TGrid_Map;
    
    Data nsImGuiWidgets_TGrid_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TGrid_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TGrid>(p); };
    auto nsImGuiWidgets_TGrid_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TGrid_Map.insert({ nsImGuiWidgets_TGrid_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TGrid_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TGrid_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TGrid_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TGrid>(p); };
    auto nsImGuiWidgets_TGrid_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TGrid_Map.insert({ nsImGuiWidgets_TGrid_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TGrid_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TGrid_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TGrid_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TGrid>(p); };
    auto nsImGuiWidgets_TGrid_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TGrid_Map.insert({ nsImGuiWidgets_TGrid_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TGrid_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TGrid_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TGrid_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TGrid>(p); };
    auto nsImGuiWidgets_TGrid_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TGrid_Map.insert({ nsImGuiWidgets_TGrid_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TGrid_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TGrid_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TGrid_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TGrid>(p); };
    auto nsImGuiWidgets_TGrid_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TGrid_Map.insert({ nsImGuiWidgets_TGrid_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TGrid_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TGrid_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TGrid>();
    
    m.insert({ nsImGuiWidgets_TGrid_rtti, nsImGuiWidgets_TGrid_Map });
    
    std::map<int, Data> nsImGuiWidgets_THorizontalAlign_Map;
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::THorizontalAlign>(p); };
    auto nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_THorizontalAlign_Map.insert({ nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_THorizontalAlign_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    m.insert({ nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_THorizontalAlign_Map });
    
    std::map<int, Data> nsImGuiWidgets_TIdentity_Map;
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TDockNode_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TDockNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDockNode, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TDockNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDockNode>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TDockNode_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TDockNode_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TMenuNode_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TMenuNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMenuNode, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TMenuNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TMenuNode_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TMenuNode_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TPopupNode_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TPopupNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPopupNode, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TPopupNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TPopupNode_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TPopupNode_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TSeparator_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TSeparator_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSeparator, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TSeparator_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSeparator>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TSeparator_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TSeparator_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTreeNode_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTreeNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeNode, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTreeNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTreeNode_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTreeNode_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TIdentity_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TIdentity_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TIdentity>(p); };
    auto nsImGuiWidgets_TIdentity_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TIdentity_Map.insert({ nsImGuiWidgets_TIdentity_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TIdentity_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    m.insert({ nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TIdentity_Map });
    
    std::map<int, Data> nsImGuiWidgets_TInputDouble_Map;
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TInputDoubleValue_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TInputDoubleValue_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDoubleValue, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TInputDoubleValue_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDoubleValue>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TInputDoubleValue_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TInputDoubleValue_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TInputDouble>(p); };
    auto nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TInputDouble_Map.insert({ nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TInputDouble_nsImGuiWidgets_TWidget_Data });
    
    auto nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    m.insert({ nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TInputDouble_Map });
    
    std::map<int, Data> nsImGuiWidgets_TInputDoubleValue_Map;
    
    Data nsImGuiWidgets_TInputDoubleValue_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TInputDoubleValue_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TInputDoubleValue>(p); };
    auto nsImGuiWidgets_TInputDoubleValue_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TInputDoubleValue_Map.insert({ nsImGuiWidgets_TInputDoubleValue_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TInputDoubleValue_nsImGuiWidgets_TInputDouble_Data });
    
    auto nsImGuiWidgets_TInputDoubleValue_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDoubleValue>();
    
    m.insert({ nsImGuiWidgets_TInputDoubleValue_rtti, nsImGuiWidgets_TInputDoubleValue_Map });
    
    std::map<int, Data> nsImGuiWidgets_TInputInt_Map;
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TInputIntValue_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TInputIntValue_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputIntValue, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TInputIntValue_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputIntValue>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TInputIntValue_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TInputIntValue_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TInputInt_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TInputInt_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TInputInt>(p); };
    auto nsImGuiWidgets_TInputInt_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TInputInt_Map.insert({ nsImGuiWidgets_TInputInt_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TInputInt_nsImGuiWidgets_TWidget_Data });
    
    auto nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    m.insert({ nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TInputInt_Map });
    
    std::map<int, Data> nsImGuiWidgets_TInputIntValue_Map;
    
    Data nsImGuiWidgets_TInputIntValue_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TInputIntValue_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TInputIntValue>(p); };
    auto nsImGuiWidgets_TInputIntValue_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TInputIntValue_Map.insert({ nsImGuiWidgets_TInputIntValue_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TInputIntValue_nsImGuiWidgets_TInputInt_Data });
    
    auto nsImGuiWidgets_TInputIntValue_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputIntValue>();
    
    m.insert({ nsImGuiWidgets_TInputIntValue_rtti, nsImGuiWidgets_TInputIntValue_Map });
    
    std::map<int, Data> nsImGuiWidgets_TInputMultiText_Map;
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TInputTextValue_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TInputTextValue_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputTextValue, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TInputTextValue_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputTextValue>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TInputTextValue_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TInputTextValue_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TInputMultiText>(p); };
    auto nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TInputMultiText_Map.insert({ nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TInputMultiText_nsImGuiWidgets_TWidget_Data });
    
    auto nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    m.insert({ nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TInputMultiText_Map });
    
    std::map<int, Data> nsImGuiWidgets_TInputText_Map;
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TInputTextValue_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TInputTextValue_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputTextValue, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TInputTextValue_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputTextValue>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TInputTextValue_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TInputTextValue_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TInputText_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TInputText_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TInputText>(p); };
    auto nsImGuiWidgets_TInputText_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TInputText_Map.insert({ nsImGuiWidgets_TInputText_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TInputText_nsImGuiWidgets_TWidget_Data });
    
    auto nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    m.insert({ nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TInputText_Map });
    
    std::map<int, Data> nsImGuiWidgets_TInputTextValue_Map;
    
    Data nsImGuiWidgets_TInputTextValue_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TInputTextValue_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TInputTextValue>(p); };
    auto nsImGuiWidgets_TInputTextValue_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TInputTextValue_Map.insert({ nsImGuiWidgets_TInputTextValue_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TInputTextValue_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TInputTextValue_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TInputTextValue_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TInputTextValue>(p); };
    auto nsImGuiWidgets_TInputTextValue_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TInputTextValue_Map.insert({ nsImGuiWidgets_TInputTextValue_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TInputTextValue_nsImGuiWidgets_TInputText_Data });
    
    auto nsImGuiWidgets_TInputTextValue_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputTextValue>();
    
    m.insert({ nsImGuiWidgets_TInputTextValue_rtti, nsImGuiWidgets_TInputTextValue_Map });
    
    std::map<int, Data> nsImGuiWidgets_TLabel_Map;
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TLabel_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TLabel_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TLabel>(p); };
    auto nsImGuiWidgets_TLabel_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TLabel_Map.insert({ nsImGuiWidgets_TLabel_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TLabel_nsImGuiWidgets_TWidget_Data });
    
    auto nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    m.insert({ nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TLabel_Map });
    
    std::map<int, Data> nsImGuiWidgets_TMainWindow_Map;
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TMainWindow>(p); };
    auto nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TMainWindow_Map.insert({ nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TMainWindow_nsImGuiWidgets_TWidgetContainer_Data });
    
    auto nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    m.insert({ nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TMainWindow_Map });
    
    std::map<int, Data> nsImGuiWidgets_TMaxSize_Map;
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TMaxSize>(p); };
    auto nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TMaxSize_Map.insert({ nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TMaxSize_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    m.insert({ nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TMaxSize_Map });
    
    std::map<int, Data> nsImGuiWidgets_TMenuNode_Map;
    
    Data nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TMenuNode>(p); };
    auto nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TMenuNode_Map.insert({ nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TMenuNode>(p); };
    auto nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TMenuNode_Map.insert({ nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TMenuNode>(p); };
    auto nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TMenuNode_Map.insert({ nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TMenuNode>(p); };
    auto nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TMenuNode_Map.insert({ nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TMenuNode>(p); };
    auto nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TMenuNode_Map.insert({ nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTextureReference_Data;
    nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTextureReference_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTextureReference, nsImGuiWidgets::TMenuNode>(p); };
    auto nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTextureReference_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureReference>();
    
    nsImGuiWidgets_TMenuNode_Map.insert({ nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTextureReference_rtti, nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTextureReference_Data });
    
    Data nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTextureSize_Data;
    nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTextureSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTextureSize, nsImGuiWidgets::TMenuNode>(p); };
    auto nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTextureSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureSize>();
    
    nsImGuiWidgets_TMenuNode_Map.insert({ nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTextureSize_rtti, nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTextureSize_Data });
    
    Data nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TMenuNode>(p); };
    auto nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TMenuNode_Map.insert({ nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TMenuNode>(p); };
    auto nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TMenuNode_Map.insert({ nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TMenuNode>(p); };
    auto nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TMenuNode_Map.insert({ nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TMenuNode>(p); };
    auto nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TMenuNode_Map.insert({ nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TMenuNode_nsImGuiWidgets_TWidgetContainer_Data });
    
    auto nsImGuiWidgets_TMenuNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    
    m.insert({ nsImGuiWidgets_TMenuNode_rtti, nsImGuiWidgets_TMenuNode_Map });
    
    std::map<int, Data> nsImGuiWidgets_TMinDistanceToParent_Map;
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TMinDistanceToParent>(p); };
    auto nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TMinDistanceToParent_Map.insert({ nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TMinDistanceToParent_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    m.insert({ nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TMinDistanceToParent_Map });
    
    std::map<int, Data> nsImGuiWidgets_TMinSize_Map;
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TMinSize_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TMinSize_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TMinSize>(p); };
    auto nsImGuiWidgets_TMinSize_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TMinSize_Map.insert({ nsImGuiWidgets_TMinSize_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TMinSize_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    m.insert({ nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TMinSize_Map });
    
    std::map<int, Data> nsImGuiWidgets_TNode_Map;
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TMenuNode_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TMenuNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMenuNode, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TMenuNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TMenuNode_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TMenuNode_Data });
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TTextureReference_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TTextureReference_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTextureReference, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TTextureReference_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureReference>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TTextureReference_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TTextureReference_Data });
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TTextureSize_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TTextureSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTextureSize, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TTextureSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureSize>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TTextureSize_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TTextureSize_Data });
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TWidgetContainer_Data });
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TPopupNode_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TPopupNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPopupNode, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TPopupNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TPopupNode_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TPopupNode_Data });
    
    Data nsImGuiWidgets_TNode_nsImGuiWidgets_TTreeNode_Data;
    nsImGuiWidgets_TNode_nsImGuiWidgets_TTreeNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeNode, nsImGuiWidgets::TNode>(p); };
    auto nsImGuiWidgets_TNode_nsImGuiWidgets_TTreeNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    
    nsImGuiWidgets_TNode_Map.insert({ nsImGuiWidgets_TNode_nsImGuiWidgets_TTreeNode_rtti, nsImGuiWidgets_TNode_nsImGuiWidgets_TTreeNode_Data });
    
    auto nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    m.insert({ nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TNode_Map });
    
    std::map<int, Data> nsImGuiWidgets_TPadding_Map;
    
    Data nsImGuiWidgets_TPadding_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TPadding_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TPadding>(p); };
    auto nsImGuiWidgets_TPadding_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TPadding_Map.insert({ nsImGuiWidgets_TPadding_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TPadding_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TPadding_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TPadding_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TPadding>(p); };
    auto nsImGuiWidgets_TPadding_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TPadding_Map.insert({ nsImGuiWidgets_TPadding_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TPadding_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TPadding_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TPadding_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TPadding>(p); };
    auto nsImGuiWidgets_TPadding_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TPadding_Map.insert({ nsImGuiWidgets_TPadding_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TPadding_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TPadding_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TPadding_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TPadding>(p); };
    auto nsImGuiWidgets_TPadding_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TPadding_Map.insert({ nsImGuiWidgets_TPadding_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TPadding_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TPadding_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TPadding_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TPadding>(p); };
    auto nsImGuiWidgets_TPadding_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TPadding_Map.insert({ nsImGuiWidgets_TPadding_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TPadding_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TPadding_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPadding>();
    
    m.insert({ nsImGuiWidgets_TPadding_rtti, nsImGuiWidgets_TPadding_Map });
    
    std::map<int, Data> nsImGuiWidgets_TPopupMenu_Map;
    
    Data nsImGuiWidgets_TPopupMenu_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TPopupMenu_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TPopupMenu>(p); };
    auto nsImGuiWidgets_TPopupMenu_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TPopupMenu_Map.insert({ nsImGuiWidgets_TPopupMenu_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TPopupMenu_nsImGuiWidgets_TWidgetContainer_Data });
    
    auto nsImGuiWidgets_TPopupMenu_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupMenu>();
    
    m.insert({ nsImGuiWidgets_TPopupMenu_rtti, nsImGuiWidgets_TPopupMenu_Map });
    
    std::map<int, Data> nsImGuiWidgets_TPopupNode_Map;
    
    Data nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TPopupNode>(p); };
    auto nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TPopupNode_Map.insert({ nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TPopupNode>(p); };
    auto nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TPopupNode_Map.insert({ nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TPopupNode>(p); };
    auto nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TPopupNode_Map.insert({ nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TPopupNode>(p); };
    auto nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TPopupNode_Map.insert({ nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TPopupNode>(p); };
    auto nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TPopupNode_Map.insert({ nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTextureReference_Data;
    nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTextureReference_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTextureReference, nsImGuiWidgets::TPopupNode>(p); };
    auto nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTextureReference_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureReference>();
    
    nsImGuiWidgets_TPopupNode_Map.insert({ nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTextureReference_rtti, nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTextureReference_Data });
    
    Data nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTextureSize_Data;
    nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTextureSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTextureSize, nsImGuiWidgets::TPopupNode>(p); };
    auto nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTextureSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureSize>();
    
    nsImGuiWidgets_TPopupNode_Map.insert({ nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTextureSize_rtti, nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTextureSize_Data });
    
    Data nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TPopupNode>(p); };
    auto nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TPopupNode_Map.insert({ nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TPopupNode>(p); };
    auto nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TPopupNode_Map.insert({ nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TPopupNode>(p); };
    auto nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TPopupNode_Map.insert({ nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TPopupNode>(p); };
    auto nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TPopupNode_Map.insert({ nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TPopupNode_nsImGuiWidgets_TWidgetContainer_Data });
    
    auto nsImGuiWidgets_TPopupNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    
    m.insert({ nsImGuiWidgets_TPopupNode_rtti, nsImGuiWidgets_TPopupNode_Map });
    
    std::map<int, Data> nsImGuiWidgets_TPosition_Map;
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TDockNode_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TDockNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDockNode, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TDockNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDockNode>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TDockNode_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TDockNode_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TMenuNode_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TMenuNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMenuNode, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TMenuNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TMenuNode_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TMenuNode_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TPopupNode_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TPopupNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPopupNode, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TPopupNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TPopupNode_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TPopupNode_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TSeparator_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TSeparator_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSeparator, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TSeparator_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSeparator>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TSeparator_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TSeparator_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TTreeNode_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TTreeNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeNode, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TTreeNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TTreeNode_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TTreeNode_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TPosition_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TPosition_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TPosition>(p); };
    auto nsImGuiWidgets_TPosition_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TPosition_Map.insert({ nsImGuiWidgets_TPosition_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TPosition_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    m.insert({ nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TPosition_Map });
    
    std::map<int, Data> nsImGuiWidgets_TProtoFrame_Map;
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWidgetContainer_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TProtoFrame>(p); };
    auto nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TProtoFrame_Map.insert({ nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TProtoFrame_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    m.insert({ nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TProtoFrame_Map });
    
    std::map<int, Data> nsImGuiWidgets_TRootFrame_Map;
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TGrid_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TGrid_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TGrid, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TGrid_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TGrid>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TGrid_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TGrid_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TPadding_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TPadding_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPadding, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TPadding_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPadding>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TPadding_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TPadding_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TSpacing_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TSpacing_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSpacing, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TSpacing_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSpacing>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TSpacing_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TSpacing_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWidgetContainer_Data });
    
    Data nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TRootFrame>(p); };
    auto nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TRootFrame_Map.insert({ nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TRootFrame_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    m.insert({ nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TRootFrame_Map });
    
    std::map<int, Data> nsImGuiWidgets_TSeparator_Map;
    
    Data nsImGuiWidgets_TSeparator_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TSeparator_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TSeparator>(p); };
    auto nsImGuiWidgets_TSeparator_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TSeparator_Map.insert({ nsImGuiWidgets_TSeparator_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TSeparator_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TSeparator_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TSeparator_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TSeparator>(p); };
    auto nsImGuiWidgets_TSeparator_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TSeparator_Map.insert({ nsImGuiWidgets_TSeparator_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TSeparator_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TSeparator_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TSeparator_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TSeparator>(p); };
    auto nsImGuiWidgets_TSeparator_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TSeparator_Map.insert({ nsImGuiWidgets_TSeparator_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TSeparator_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TSeparator_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TSeparator_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TSeparator>(p); };
    auto nsImGuiWidgets_TSeparator_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TSeparator_Map.insert({ nsImGuiWidgets_TSeparator_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TSeparator_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TSeparator_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TSeparator_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TSeparator>(p); };
    auto nsImGuiWidgets_TSeparator_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TSeparator_Map.insert({ nsImGuiWidgets_TSeparator_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TSeparator_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TSeparator_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TSeparator_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TSeparator>(p); };
    auto nsImGuiWidgets_TSeparator_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TSeparator_Map.insert({ nsImGuiWidgets_TSeparator_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TSeparator_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TSeparator_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TSeparator_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TSeparator>(p); };
    auto nsImGuiWidgets_TSeparator_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TSeparator_Map.insert({ nsImGuiWidgets_TSeparator_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TSeparator_nsImGuiWidgets_TWidget_Data });
    
    auto nsImGuiWidgets_TSeparator_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSeparator>();
    
    m.insert({ nsImGuiWidgets_TSeparator_rtti, nsImGuiWidgets_TSeparator_Map });
    
    std::map<int, Data> nsImGuiWidgets_TSize_Map;
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TDockNode_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TDockNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDockNode, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TDockNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDockNode>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TDockNode_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TDockNode_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TMenuNode_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TMenuNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMenuNode, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TMenuNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TMenuNode_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TMenuNode_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TPopupNode_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TPopupNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPopupNode, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TPopupNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TPopupNode_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TPopupNode_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TSeparator_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TSeparator_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSeparator, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TSeparator_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSeparator>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TSeparator_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TSeparator_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TTreeNode_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TTreeNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeNode, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TTreeNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TTreeNode_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TTreeNode_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TSize_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TSize_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TSize>(p); };
    auto nsImGuiWidgets_TSize_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TSize_Map.insert({ nsImGuiWidgets_TSize_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TSize_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    m.insert({ nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TSize_Map });
    
    std::map<int, Data> nsImGuiWidgets_TSpacing_Map;
    
    Data nsImGuiWidgets_TSpacing_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TSpacing_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TSpacing>(p); };
    auto nsImGuiWidgets_TSpacing_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TSpacing_Map.insert({ nsImGuiWidgets_TSpacing_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TSpacing_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TSpacing_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TSpacing_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TSpacing>(p); };
    auto nsImGuiWidgets_TSpacing_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TSpacing_Map.insert({ nsImGuiWidgets_TSpacing_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TSpacing_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TSpacing_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TSpacing_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TSpacing>(p); };
    auto nsImGuiWidgets_TSpacing_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TSpacing_Map.insert({ nsImGuiWidgets_TSpacing_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TSpacing_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TSpacing_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TSpacing_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TSpacing>(p); };
    auto nsImGuiWidgets_TSpacing_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TSpacing_Map.insert({ nsImGuiWidgets_TSpacing_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TSpacing_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TSpacing_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TSpacing_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TSpacing>(p); };
    auto nsImGuiWidgets_TSpacing_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TSpacing_Map.insert({ nsImGuiWidgets_TSpacing_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TSpacing_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TSpacing_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSpacing>();
    
    m.insert({ nsImGuiWidgets_TSpacing_rtti, nsImGuiWidgets_TSpacing_Map });
    
    std::map<int, Data> nsImGuiWidgets_TTextureReference_Map;
    
    Data nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TMenuNode_Data;
    nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TMenuNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMenuNode, nsImGuiWidgets::TTextureReference>(p); };
    auto nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TMenuNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    
    nsImGuiWidgets_TTextureReference_Map.insert({ nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TMenuNode_rtti, nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TMenuNode_Data });
    
    Data nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TTextureReference>(p); };
    auto nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TTextureReference_Map.insert({ nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TPopupNode_Data;
    nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TPopupNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPopupNode, nsImGuiWidgets::TTextureReference>(p); };
    auto nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TPopupNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    
    nsImGuiWidgets_TTextureReference_Map.insert({ nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TPopupNode_rtti, nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TPopupNode_Data });
    
    Data nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TTextureReference>(p); };
    auto nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TTextureReference_Map.insert({ nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TTreeNode_Data;
    nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TTreeNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeNode, nsImGuiWidgets::TTextureReference>(p); };
    auto nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TTreeNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    
    nsImGuiWidgets_TTextureReference_Map.insert({ nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TTreeNode_rtti, nsImGuiWidgets_TTextureReference_nsImGuiWidgets_TTreeNode_Data });
    
    auto nsImGuiWidgets_TTextureReference_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureReference>();
    
    m.insert({ nsImGuiWidgets_TTextureReference_rtti, nsImGuiWidgets_TTextureReference_Map });
    
    std::map<int, Data> nsImGuiWidgets_TTextureSize_Map;
    
    Data nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TMenuNode_Data;
    nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TMenuNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMenuNode, nsImGuiWidgets::TTextureSize>(p); };
    auto nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TMenuNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    
    nsImGuiWidgets_TTextureSize_Map.insert({ nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TMenuNode_rtti, nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TMenuNode_Data });
    
    Data nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TTextureSize>(p); };
    auto nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TTextureSize_Map.insert({ nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TPopupNode_Data;
    nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TPopupNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPopupNode, nsImGuiWidgets::TTextureSize>(p); };
    auto nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TPopupNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    
    nsImGuiWidgets_TTextureSize_Map.insert({ nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TPopupNode_rtti, nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TPopupNode_Data });
    
    Data nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TTextureSize>(p); };
    auto nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TTextureSize_Map.insert({ nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TTreeNode_Data;
    nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TTreeNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeNode, nsImGuiWidgets::TTextureSize>(p); };
    auto nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TTreeNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    
    nsImGuiWidgets_TTextureSize_Map.insert({ nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TTreeNode_rtti, nsImGuiWidgets_TTextureSize_nsImGuiWidgets_TTreeNode_Data });
    
    auto nsImGuiWidgets_TTextureSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureSize>();
    
    m.insert({ nsImGuiWidgets_TTextureSize_rtti, nsImGuiWidgets_TTextureSize_Map });
    
    std::map<int, Data> nsImGuiWidgets_TTextureUv_Map;
    
    Data nsImGuiWidgets_TTextureUv_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TTextureUv_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TTextureUv>(p); };
    auto nsImGuiWidgets_TTextureUv_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TTextureUv_Map.insert({ nsImGuiWidgets_TTextureUv_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TTextureUv_nsImGuiWidgets_TTexturedFrame_Data });
    
    auto nsImGuiWidgets_TTextureUv_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureUv>();
    
    m.insert({ nsImGuiWidgets_TTextureUv_rtti, nsImGuiWidgets_TTextureUv_Map });
    
    std::map<int, Data> nsImGuiWidgets_TTexturedFrame_Map;
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TGrid_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TGrid_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TGrid, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TGrid_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TGrid>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TGrid_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TGrid_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TPadding_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TPadding_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPadding, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TPadding_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPadding>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TPadding_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TPadding_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TSpacing_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TSpacing_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSpacing, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TSpacing_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSpacing>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TSpacing_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TSpacing_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureReference_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureReference_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTextureReference, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureReference_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureReference>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureReference_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureReference_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureSize_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTextureSize, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureSize>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureSize_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureSize_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureUv_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureUv_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTextureUv, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureUv_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureUv>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureUv_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTextureUv_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TTexturedFrame>(p); };
    auto nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TTexturedFrame_Map.insert({ nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TTexturedFrame_nsImGuiWidgets_TWidgetContainer_Data });
    
    auto nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    m.insert({ nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TTexturedFrame_Map });
    
    std::map<int, Data> nsImGuiWidgets_TTitle_Map;
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TMenuNode_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TMenuNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMenuNode, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TMenuNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TMenuNode_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TMenuNode_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TPopupNode_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TPopupNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPopupNode, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TPopupNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TPopupNode_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TPopupNode_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TSeparator_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TSeparator_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSeparator, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TSeparator_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSeparator>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TSeparator_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TSeparator_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TToolTip_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TToolTip_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TToolTip, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TToolTip_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TToolTip>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TToolTip_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TToolTip_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TTreeNode_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TTreeNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeNode, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TTreeNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TTreeNode_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TTreeNode_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TTitle_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TTitle_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TTitle>(p); };
    auto nsImGuiWidgets_TTitle_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TTitle_Map.insert({ nsImGuiWidgets_TTitle_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TTitle_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    m.insert({ nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TTitle_Map });
    
    std::map<int, Data> nsImGuiWidgets_TToolTip_Map;
    
    Data nsImGuiWidgets_TToolTip_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TToolTip_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TToolTip>(p); };
    auto nsImGuiWidgets_TToolTip_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TToolTip_Map.insert({ nsImGuiWidgets_TToolTip_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TToolTip_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TToolTip_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TToolTip_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TToolTip>(p); };
    auto nsImGuiWidgets_TToolTip_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TToolTip_Map.insert({ nsImGuiWidgets_TToolTip_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TToolTip_nsImGuiWidgets_TVisibility_Data });
    
    auto nsImGuiWidgets_TToolTip_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TToolTip>();
    
    m.insert({ nsImGuiWidgets_TToolTip_rtti, nsImGuiWidgets_TToolTip_Map });
    
    std::map<int, Data> nsImGuiWidgets_TTreeNode_Map;
    
    Data nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TTreeNode>(p); };
    auto nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TTreeNode_Map.insert({ nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TTreeNode>(p); };
    auto nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TTreeNode_Map.insert({ nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TTreeNode>(p); };
    auto nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TTreeNode_Map.insert({ nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TTreeNode>(p); };
    auto nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TTreeNode_Map.insert({ nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TTreeNode>(p); };
    auto nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TTreeNode_Map.insert({ nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTextureReference_Data;
    nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTextureReference_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTextureReference, nsImGuiWidgets::TTreeNode>(p); };
    auto nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTextureReference_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureReference>();
    
    nsImGuiWidgets_TTreeNode_Map.insert({ nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTextureReference_rtti, nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTextureReference_Data });
    
    Data nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTextureSize_Data;
    nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTextureSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTextureSize, nsImGuiWidgets::TTreeNode>(p); };
    auto nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTextureSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureSize>();
    
    nsImGuiWidgets_TTreeNode_Map.insert({ nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTextureSize_rtti, nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTextureSize_Data });
    
    Data nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TTreeNode>(p); };
    auto nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TTreeNode_Map.insert({ nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TTreeNode>(p); };
    auto nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TTreeNode_Map.insert({ nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TTreeNode>(p); };
    auto nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TTreeNode_Map.insert({ nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TTreeNode>(p); };
    auto nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TTreeNode_Map.insert({ nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TTreeNode_nsImGuiWidgets_TWidgetContainer_Data });
    
    auto nsImGuiWidgets_TTreeNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    
    m.insert({ nsImGuiWidgets_TTreeNode_rtti, nsImGuiWidgets_TTreeNode_Map });
    
    std::map<int, Data> nsImGuiWidgets_TTreeView_Map;
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TTreeView_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TTreeView_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TTreeView>(p); };
    auto nsImGuiWidgets_TTreeView_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TTreeView_Map.insert({ nsImGuiWidgets_TTreeView_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TTreeView_nsImGuiWidgets_TWidgetContainer_Data });
    
    auto nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    m.insert({ nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TTreeView_Map });
    
    std::map<int, Data> nsImGuiWidgets_TUnit_Map;
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TUnit_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TUnit_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TUnit>(p); };
    auto nsImGuiWidgets_TUnit_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TUnit_Map.insert({ nsImGuiWidgets_TUnit_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TUnit_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    m.insert({ nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TUnit_Map });
    
    std::map<int, Data> nsImGuiWidgets_TVerticalAlign_Map;
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TVerticalAlign>(p); };
    auto nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TVerticalAlign_Map.insert({ nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TVerticalAlign_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    m.insert({ nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TVerticalAlign_Map });
    
    std::map<int, Data> nsImGuiWidgets_TVisibility_Map;
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TMenuNode_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TMenuNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMenuNode, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TMenuNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TMenuNode_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TMenuNode_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TPopupNode_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TPopupNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPopupNode, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TPopupNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TPopupNode_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TPopupNode_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TSeparator_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TSeparator_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSeparator, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TSeparator_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSeparator>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TSeparator_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TSeparator_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TToolTip_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TToolTip_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TToolTip, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TToolTip_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TToolTip>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TToolTip_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TToolTip_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTreeNode_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTreeNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeNode, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTreeNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTreeNode_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTreeNode_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TVisibility_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TVisibility_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TVisibility>(p); };
    auto nsImGuiWidgets_TVisibility_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TVisibility_Map.insert({ nsImGuiWidgets_TVisibility_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TVisibility_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    m.insert({ nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TVisibility_Map });
    
    std::map<int, Data> nsImGuiWidgets_TWidget_Map;
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TButton_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TButton_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TButton, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TButton_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TButton_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TButton_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TCheckBox_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TCheckBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TCheckBox, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TCheckBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TCheckBox_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TCheckBox_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TComboBox_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TComboBox_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TComboBox, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TComboBox_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TComboBox_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TComboBox_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputDouble_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputDouble_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputDouble, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputDouble_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputDouble_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputDouble_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputInt_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputInt_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputInt, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputInt_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputInt_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputInt_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputMultiText_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputMultiText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputMultiText, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputMultiText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputMultiText_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputMultiText_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputText_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputText_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TInputText, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputText_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputText_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TInputText_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TLabel_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TLabel_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TLabel, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TLabel_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TLabel_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TLabel_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TMenuNode_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TMenuNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMenuNode, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TMenuNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TMenuNode_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TMenuNode_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TPopupNode_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TPopupNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPopupNode, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TPopupNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TPopupNode_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TPopupNode_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TSeparator_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TSeparator_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSeparator, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TSeparator_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSeparator>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TSeparator_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TSeparator_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TTreeNode_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TTreeNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeNode, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TTreeNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TTreeNode_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TTreeNode_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TWidget_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TWidget_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TWidget>(p); };
    auto nsImGuiWidgets_TWidget_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TWidget_Map.insert({ nsImGuiWidgets_TWidget_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TWidget_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    m.insert({ nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TWidget_Map });
    
    std::map<int, Data> nsImGuiWidgets_TWidgetContainer_Map;
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TDialog_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TDialog_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TDialog, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TDialog_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TDialog_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TDialog_Data });
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TMainWindow_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TMainWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMainWindow, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TMainWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TMainWindow_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TMainWindow_Data });
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TMenuNode_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TMenuNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMenuNode, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TMenuNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TMenuNode_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TMenuNode_Data });
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TNode_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TNode, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TNode_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TNode_Data });
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TPopupMenu_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TPopupMenu_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPopupMenu, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TPopupMenu_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupMenu>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TPopupMenu_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TPopupMenu_Data });
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TPopupNode_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TPopupNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPopupNode, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TPopupNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TPopupNode_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TPopupNode_Data });
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTexturedFrame_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTexturedFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTexturedFrame, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTexturedFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTexturedFrame_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTexturedFrame_Data });
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTreeNode_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTreeNode_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeNode, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTreeNode_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTreeNode_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTreeNode_Data });
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTreeView_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTreeView_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTreeView, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTreeView_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTreeView_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TTreeView_Data });
    
    Data nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TWindow_Data;
    nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TWindow_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWindow, nsImGuiWidgets::TWidgetContainer>(p); };
    auto nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    nsImGuiWidgets_TWidgetContainer_Map.insert({ nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TWidgetContainer_nsImGuiWidgets_TWindow_Data });
    
    auto nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    m.insert({ nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TWidgetContainer_Map });
    
    std::map<int, Data> nsImGuiWidgets_TWindow_Map;
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TAnchors_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TAnchors_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TAnchors, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TAnchors_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TAnchors_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TAnchors_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TColor_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TColor_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TColor, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TColor_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TColor_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TColor_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TFocus_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TFocus_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFocus, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TFocus_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TFocus_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TFocus_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TFrame_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TFrame, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TFrame_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TFrame_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TGrid_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TGrid_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TGrid, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TGrid_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TGrid>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TGrid_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TGrid_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_THorizontalAlign_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_THorizontalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::THorizontalAlign, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_THorizontalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_THorizontalAlign_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_THorizontalAlign_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TIdentity_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TIdentity_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TIdentity, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TIdentity_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TIdentity_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TIdentity_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TMaxSize_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TMaxSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMaxSize, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TMaxSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TMaxSize_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TMaxSize_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TMinDistanceToParent_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TMinDistanceToParent_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinDistanceToParent, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TMinDistanceToParent_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TMinDistanceToParent_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TMinDistanceToParent_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TMinSize_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TMinSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TMinSize, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TMinSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TMinSize_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TMinSize_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TPadding_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TPadding_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPadding, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TPadding_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPadding>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TPadding_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TPadding_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TPosition_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TPosition_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TPosition, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TPosition_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TPosition_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TPosition_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TProtoFrame_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TProtoFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TProtoFrame, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TProtoFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TProtoFrame_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TProtoFrame_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TRootFrame_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TRootFrame_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TRootFrame, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TRootFrame_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TRootFrame_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TRootFrame_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TSize_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TSize_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSize, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TSize_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TSize_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TSize_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TSpacing_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TSpacing_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TSpacing, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TSpacing_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TSpacing>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TSpacing_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TSpacing_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TTitle_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TTitle_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TTitle, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TTitle_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TTitle_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TTitle_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TUnit_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TUnit_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TUnit, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TUnit_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TUnit_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TUnit_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TVerticalAlign_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TVerticalAlign_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVerticalAlign, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TVerticalAlign_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TVerticalAlign_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TVerticalAlign_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TVisibility_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TVisibility_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TVisibility, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TVisibility_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TVisibility_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TVisibility_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TWidget_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TWidget_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidget, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TWidget_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TWidget_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TWidget_Data });
    
    Data nsImGuiWidgets_TWindow_nsImGuiWidgets_TWidgetContainer_Data;
    nsImGuiWidgets_TWindow_nsImGuiWidgets_TWidgetContainer_Data.castFunc = [](void* p){ return SmartCast<nsImGuiWidgets::TWidgetContainer, nsImGuiWidgets::TWindow>(p); };
    auto nsImGuiWidgets_TWindow_nsImGuiWidgets_TWidgetContainer_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    
    nsImGuiWidgets_TWindow_Map.insert({ nsImGuiWidgets_TWindow_nsImGuiWidgets_TWidgetContainer_rtti, nsImGuiWidgets_TWindow_nsImGuiWidgets_TWidgetContainer_Data });
    
    auto nsImGuiWidgets_TWindow_rtti = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    
    m.insert({ nsImGuiWidgets_TWindow_rtti, nsImGuiWidgets_TWindow_Map });
    
    int srcMax = 0;
    for (auto& vt : m) {
        srcMax = std::max(vt.first, srcMax);
    }
    
    mDataVector.resize(srcMax + 1);
    for (auto& vt : m) {
        std::vector<Data> vecData;
        int dstMax = 0;
        for (auto& vtDst : vt.second) {
            dstMax = std::max(vtDst.first, dstMax);
        }
        
        vecData.resize(dstMax + 1);
        std::set<int> rttis;
        for (auto& vtDst : vt.second) {
            vecData[vtDst.first] = vtDst.second;
            rttis.insert(vtDst.first);
        }
        
        mRttiCombinations.insert({ vt.first, rttis });
        
        mDataVector[vt.first] = vecData;
    }
}
//---------------------------------------------------------------------------------------
void* TImGuiWidgetsDynamicCaster::Cast(int srcRtti, void* p, int dstRtti)
{
    Init();
    return mDataVector[dstRtti][srcRtti].castFunc(p);
}
//---------------------------------------------------------------------------------------
const std::map<int, std::set<int>>& TImGuiWidgetsDynamicCaster::GetRttiCombinations()
{
    Init();
    return mRttiCombinations;
}
//---------------------------------------------------------------------------------------
