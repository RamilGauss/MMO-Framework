/*
Core Component
*/
// ReflectionCodeGenerator version 2.4.2, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_09_17 10:25:20.699
	
#include "ImGuiWidgetsTypeInfo.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

std::list<std::string> TImGuiWidgetsTypeInfo::mTypeNameList;
std::list<int> TImGuiWidgetsTypeInfo::mRttiList;

std::vector<std::string> TImGuiWidgetsTypeInfo::mNameVector;
std::unordered_map<std::string, int> TImGuiWidgetsTypeInfo::mNameRttiMap;

void TImGuiWidgetsTypeInfo::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    int nsImGuiWidgets_TAnchors_i = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors>();
    std::string nsImGuiWidgets_TAnchors_n = "nsImGuiWidgets::TAnchors";
    mTypeNameList.push_back(nsImGuiWidgets_TAnchors_n);
    mRttiList.push_back(nsImGuiWidgets_TAnchors_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TAnchors_n, nsImGuiWidgets_TAnchors_i });
    
    int nsImGuiWidgets_TButton_i = globalTypeIdentifier->Type<nsImGuiWidgets::TButton>();
    std::string nsImGuiWidgets_TButton_n = "nsImGuiWidgets::TButton";
    mTypeNameList.push_back(nsImGuiWidgets_TButton_n);
    mRttiList.push_back(nsImGuiWidgets_TButton_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TButton_n, nsImGuiWidgets_TButton_i });
    
    int nsImGuiWidgets_TCheckBox_i = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBox>();
    std::string nsImGuiWidgets_TCheckBox_n = "nsImGuiWidgets::TCheckBox";
    mTypeNameList.push_back(nsImGuiWidgets_TCheckBox_n);
    mRttiList.push_back(nsImGuiWidgets_TCheckBox_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TCheckBox_n, nsImGuiWidgets_TCheckBox_i });
    
    int nsImGuiWidgets_TCheckBoxValue_i = globalTypeIdentifier->Type<nsImGuiWidgets::TCheckBoxValue>();
    std::string nsImGuiWidgets_TCheckBoxValue_n = "nsImGuiWidgets::TCheckBoxValue";
    mTypeNameList.push_back(nsImGuiWidgets_TCheckBoxValue_n);
    mRttiList.push_back(nsImGuiWidgets_TCheckBoxValue_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TCheckBoxValue_n, nsImGuiWidgets_TCheckBoxValue_i });
    
    int nsImGuiWidgets_TColor_i = globalTypeIdentifier->Type<nsImGuiWidgets::TColor>();
    std::string nsImGuiWidgets_TColor_n = "nsImGuiWidgets::TColor";
    mTypeNameList.push_back(nsImGuiWidgets_TColor_n);
    mRttiList.push_back(nsImGuiWidgets_TColor_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TColor_n, nsImGuiWidgets_TColor_i });
    
    int nsImGuiWidgets_TComboBox_i = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBox>();
    std::string nsImGuiWidgets_TComboBox_n = "nsImGuiWidgets::TComboBox";
    mTypeNameList.push_back(nsImGuiWidgets_TComboBox_n);
    mRttiList.push_back(nsImGuiWidgets_TComboBox_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TComboBox_n, nsImGuiWidgets_TComboBox_i });
    
    int nsImGuiWidgets_TComboBoxCurrentIndex_i = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBoxCurrentIndex>();
    std::string nsImGuiWidgets_TComboBoxCurrentIndex_n = "nsImGuiWidgets::TComboBoxCurrentIndex";
    mTypeNameList.push_back(nsImGuiWidgets_TComboBoxCurrentIndex_n);
    mRttiList.push_back(nsImGuiWidgets_TComboBoxCurrentIndex_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TComboBoxCurrentIndex_n, nsImGuiWidgets_TComboBoxCurrentIndex_i });
    
    int nsImGuiWidgets_TComboBoxItems_i = globalTypeIdentifier->Type<nsImGuiWidgets::TComboBoxItems>();
    std::string nsImGuiWidgets_TComboBoxItems_n = "nsImGuiWidgets::TComboBoxItems";
    mTypeNameList.push_back(nsImGuiWidgets_TComboBoxItems_n);
    mRttiList.push_back(nsImGuiWidgets_TComboBoxItems_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TComboBoxItems_n, nsImGuiWidgets_TComboBoxItems_i });
    
    int nsImGuiWidgets_TDialog_i = globalTypeIdentifier->Type<nsImGuiWidgets::TDialog>();
    std::string nsImGuiWidgets_TDialog_n = "nsImGuiWidgets::TDialog";
    mTypeNameList.push_back(nsImGuiWidgets_TDialog_n);
    mRttiList.push_back(nsImGuiWidgets_TDialog_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TDialog_n, nsImGuiWidgets_TDialog_i });
    
    int nsImGuiWidgets_TDialogStack_i = globalTypeIdentifier->Type<nsImGuiWidgets::TDialogStack>();
    std::string nsImGuiWidgets_TDialogStack_n = "nsImGuiWidgets::TDialogStack";
    mTypeNameList.push_back(nsImGuiWidgets_TDialogStack_n);
    mRttiList.push_back(nsImGuiWidgets_TDialogStack_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TDialogStack_n, nsImGuiWidgets_TDialogStack_i });
    
    int nsImGuiWidgets_TDockNode_i = globalTypeIdentifier->Type<nsImGuiWidgets::TDockNode>();
    std::string nsImGuiWidgets_TDockNode_n = "nsImGuiWidgets::TDockNode";
    mTypeNameList.push_back(nsImGuiWidgets_TDockNode_n);
    mRttiList.push_back(nsImGuiWidgets_TDockNode_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TDockNode_n, nsImGuiWidgets_TDockNode_i });
    
    int nsImGuiWidgets_TDockTree_i = globalTypeIdentifier->Type<nsImGuiWidgets::TDockTree>();
    std::string nsImGuiWidgets_TDockTree_n = "nsImGuiWidgets::TDockTree";
    mTypeNameList.push_back(nsImGuiWidgets_TDockTree_n);
    mRttiList.push_back(nsImGuiWidgets_TDockTree_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TDockTree_n, nsImGuiWidgets_TDockTree_i });
    
    int nsImGuiWidgets_TDockTreeManager_i = globalTypeIdentifier->Type<nsImGuiWidgets::TDockTreeManager>();
    std::string nsImGuiWidgets_TDockTreeManager_n = "nsImGuiWidgets::TDockTreeManager";
    mTypeNameList.push_back(nsImGuiWidgets_TDockTreeManager_n);
    mRttiList.push_back(nsImGuiWidgets_TDockTreeManager_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TDockTreeManager_n, nsImGuiWidgets_TDockTreeManager_i });
    
    int nsImGuiWidgets_TDockTypeHelper_i = globalTypeIdentifier->Type<nsImGuiWidgets::TDockTypeHelper>();
    std::string nsImGuiWidgets_TDockTypeHelper_n = "nsImGuiWidgets::TDockTypeHelper";
    mTypeNameList.push_back(nsImGuiWidgets_TDockTypeHelper_n);
    mRttiList.push_back(nsImGuiWidgets_TDockTypeHelper_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TDockTypeHelper_n, nsImGuiWidgets_TDockTypeHelper_i });
    
    int nsImGuiWidgets_TFocus_i = globalTypeIdentifier->Type<nsImGuiWidgets::TFocus>();
    std::string nsImGuiWidgets_TFocus_n = "nsImGuiWidgets::TFocus";
    mTypeNameList.push_back(nsImGuiWidgets_TFocus_n);
    mRttiList.push_back(nsImGuiWidgets_TFocus_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TFocus_n, nsImGuiWidgets_TFocus_i });
    
    int nsImGuiWidgets_TFrame_i = globalTypeIdentifier->Type<nsImGuiWidgets::TFrame>();
    std::string nsImGuiWidgets_TFrame_n = "nsImGuiWidgets::TFrame";
    mTypeNameList.push_back(nsImGuiWidgets_TFrame_n);
    mRttiList.push_back(nsImGuiWidgets_TFrame_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TFrame_n, nsImGuiWidgets_TFrame_i });
    
    int nsImGuiWidgets_TGrid_i = globalTypeIdentifier->Type<nsImGuiWidgets::TGrid>();
    std::string nsImGuiWidgets_TGrid_n = "nsImGuiWidgets::TGrid";
    mTypeNameList.push_back(nsImGuiWidgets_TGrid_n);
    mRttiList.push_back(nsImGuiWidgets_TGrid_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TGrid_n, nsImGuiWidgets_TGrid_i });
    
    int nsImGuiWidgets_THorizontalAlign_i = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign>();
    std::string nsImGuiWidgets_THorizontalAlign_n = "nsImGuiWidgets::THorizontalAlign";
    mTypeNameList.push_back(nsImGuiWidgets_THorizontalAlign_n);
    mRttiList.push_back(nsImGuiWidgets_THorizontalAlign_i);
    mNameRttiMap.insert({ nsImGuiWidgets_THorizontalAlign_n, nsImGuiWidgets_THorizontalAlign_i });
    
    int nsImGuiWidgets_TIdentity_i = globalTypeIdentifier->Type<nsImGuiWidgets::TIdentity>();
    std::string nsImGuiWidgets_TIdentity_n = "nsImGuiWidgets::TIdentity";
    mTypeNameList.push_back(nsImGuiWidgets_TIdentity_n);
    mRttiList.push_back(nsImGuiWidgets_TIdentity_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TIdentity_n, nsImGuiWidgets_TIdentity_i });
    
    int nsImGuiWidgets_TImGuiCustom_i = globalTypeIdentifier->Type<nsImGuiWidgets::TImGuiCustom>();
    std::string nsImGuiWidgets_TImGuiCustom_n = "nsImGuiWidgets::TImGuiCustom";
    mTypeNameList.push_back(nsImGuiWidgets_TImGuiCustom_n);
    mRttiList.push_back(nsImGuiWidgets_TImGuiCustom_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TImGuiCustom_n, nsImGuiWidgets_TImGuiCustom_i });
    
    int nsImGuiWidgets_TInputDouble_i = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDouble>();
    std::string nsImGuiWidgets_TInputDouble_n = "nsImGuiWidgets::TInputDouble";
    mTypeNameList.push_back(nsImGuiWidgets_TInputDouble_n);
    mRttiList.push_back(nsImGuiWidgets_TInputDouble_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TInputDouble_n, nsImGuiWidgets_TInputDouble_i });
    
    int nsImGuiWidgets_TInputDoubleValue_i = globalTypeIdentifier->Type<nsImGuiWidgets::TInputDoubleValue>();
    std::string nsImGuiWidgets_TInputDoubleValue_n = "nsImGuiWidgets::TInputDoubleValue";
    mTypeNameList.push_back(nsImGuiWidgets_TInputDoubleValue_n);
    mRttiList.push_back(nsImGuiWidgets_TInputDoubleValue_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TInputDoubleValue_n, nsImGuiWidgets_TInputDoubleValue_i });
    
    int nsImGuiWidgets_TInputInt_i = globalTypeIdentifier->Type<nsImGuiWidgets::TInputInt>();
    std::string nsImGuiWidgets_TInputInt_n = "nsImGuiWidgets::TInputInt";
    mTypeNameList.push_back(nsImGuiWidgets_TInputInt_n);
    mRttiList.push_back(nsImGuiWidgets_TInputInt_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TInputInt_n, nsImGuiWidgets_TInputInt_i });
    
    int nsImGuiWidgets_TInputIntValue_i = globalTypeIdentifier->Type<nsImGuiWidgets::TInputIntValue>();
    std::string nsImGuiWidgets_TInputIntValue_n = "nsImGuiWidgets::TInputIntValue";
    mTypeNameList.push_back(nsImGuiWidgets_TInputIntValue_n);
    mRttiList.push_back(nsImGuiWidgets_TInputIntValue_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TInputIntValue_n, nsImGuiWidgets_TInputIntValue_i });
    
    int nsImGuiWidgets_TInputMultiText_i = globalTypeIdentifier->Type<nsImGuiWidgets::TInputMultiText>();
    std::string nsImGuiWidgets_TInputMultiText_n = "nsImGuiWidgets::TInputMultiText";
    mTypeNameList.push_back(nsImGuiWidgets_TInputMultiText_n);
    mRttiList.push_back(nsImGuiWidgets_TInputMultiText_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TInputMultiText_n, nsImGuiWidgets_TInputMultiText_i });
    
    int nsImGuiWidgets_TInputText_i = globalTypeIdentifier->Type<nsImGuiWidgets::TInputText>();
    std::string nsImGuiWidgets_TInputText_n = "nsImGuiWidgets::TInputText";
    mTypeNameList.push_back(nsImGuiWidgets_TInputText_n);
    mRttiList.push_back(nsImGuiWidgets_TInputText_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TInputText_n, nsImGuiWidgets_TInputText_i });
    
    int nsImGuiWidgets_TInputTextValue_i = globalTypeIdentifier->Type<nsImGuiWidgets::TInputTextValue>();
    std::string nsImGuiWidgets_TInputTextValue_n = "nsImGuiWidgets::TInputTextValue";
    mTypeNameList.push_back(nsImGuiWidgets_TInputTextValue_n);
    mRttiList.push_back(nsImGuiWidgets_TInputTextValue_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TInputTextValue_n, nsImGuiWidgets_TInputTextValue_i });
    
    int nsImGuiWidgets_TLabel_i = globalTypeIdentifier->Type<nsImGuiWidgets::TLabel>();
    std::string nsImGuiWidgets_TLabel_n = "nsImGuiWidgets::TLabel";
    mTypeNameList.push_back(nsImGuiWidgets_TLabel_n);
    mRttiList.push_back(nsImGuiWidgets_TLabel_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TLabel_n, nsImGuiWidgets_TLabel_i });
    
    int nsImGuiWidgets_TLightDockNode_i = globalTypeIdentifier->Type<nsImGuiWidgets::TLightDockNode>();
    std::string nsImGuiWidgets_TLightDockNode_n = "nsImGuiWidgets::TLightDockNode";
    mTypeNameList.push_back(nsImGuiWidgets_TLightDockNode_n);
    mRttiList.push_back(nsImGuiWidgets_TLightDockNode_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TLightDockNode_n, nsImGuiWidgets_TLightDockNode_i });
    
    int nsImGuiWidgets_TLightDockTreeManager_i = globalTypeIdentifier->Type<nsImGuiWidgets::TLightDockTreeManager>();
    std::string nsImGuiWidgets_TLightDockTreeManager_n = "nsImGuiWidgets::TLightDockTreeManager";
    mTypeNameList.push_back(nsImGuiWidgets_TLightDockTreeManager_n);
    mRttiList.push_back(nsImGuiWidgets_TLightDockTreeManager_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TLightDockTreeManager_n, nsImGuiWidgets_TLightDockTreeManager_i });
    
    int nsImGuiWidgets_TLightWindowNode_i = globalTypeIdentifier->Type<nsImGuiWidgets::TLightWindowNode>();
    std::string nsImGuiWidgets_TLightWindowNode_n = "nsImGuiWidgets::TLightWindowNode";
    mTypeNameList.push_back(nsImGuiWidgets_TLightWindowNode_n);
    mRttiList.push_back(nsImGuiWidgets_TLightWindowNode_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TLightWindowNode_n, nsImGuiWidgets_TLightWindowNode_i });
    
    int nsImGuiWidgets_TMainWindow_i = globalTypeIdentifier->Type<nsImGuiWidgets::TMainWindow>();
    std::string nsImGuiWidgets_TMainWindow_n = "nsImGuiWidgets::TMainWindow";
    mTypeNameList.push_back(nsImGuiWidgets_TMainWindow_n);
    mRttiList.push_back(nsImGuiWidgets_TMainWindow_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TMainWindow_n, nsImGuiWidgets_TMainWindow_i });
    
    int nsImGuiWidgets_TMaxSize_i = globalTypeIdentifier->Type<nsImGuiWidgets::TMaxSize>();
    std::string nsImGuiWidgets_TMaxSize_n = "nsImGuiWidgets::TMaxSize";
    mTypeNameList.push_back(nsImGuiWidgets_TMaxSize_n);
    mRttiList.push_back(nsImGuiWidgets_TMaxSize_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TMaxSize_n, nsImGuiWidgets_TMaxSize_i });
    
    int nsImGuiWidgets_TMenuNode_i = globalTypeIdentifier->Type<nsImGuiWidgets::TMenuNode>();
    std::string nsImGuiWidgets_TMenuNode_n = "nsImGuiWidgets::TMenuNode";
    mTypeNameList.push_back(nsImGuiWidgets_TMenuNode_n);
    mRttiList.push_back(nsImGuiWidgets_TMenuNode_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TMenuNode_n, nsImGuiWidgets_TMenuNode_i });
    
    int nsImGuiWidgets_TMinDistanceToParent_i = globalTypeIdentifier->Type<nsImGuiWidgets::TMinDistanceToParent>();
    std::string nsImGuiWidgets_TMinDistanceToParent_n = "nsImGuiWidgets::TMinDistanceToParent";
    mTypeNameList.push_back(nsImGuiWidgets_TMinDistanceToParent_n);
    mRttiList.push_back(nsImGuiWidgets_TMinDistanceToParent_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TMinDistanceToParent_n, nsImGuiWidgets_TMinDistanceToParent_i });
    
    int nsImGuiWidgets_TMinSize_i = globalTypeIdentifier->Type<nsImGuiWidgets::TMinSize>();
    std::string nsImGuiWidgets_TMinSize_n = "nsImGuiWidgets::TMinSize";
    mTypeNameList.push_back(nsImGuiWidgets_TMinSize_n);
    mRttiList.push_back(nsImGuiWidgets_TMinSize_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TMinSize_n, nsImGuiWidgets_TMinSize_i });
    
    int nsImGuiWidgets_TNode_i = globalTypeIdentifier->Type<nsImGuiWidgets::TNode>();
    std::string nsImGuiWidgets_TNode_n = "nsImGuiWidgets::TNode";
    mTypeNameList.push_back(nsImGuiWidgets_TNode_n);
    mRttiList.push_back(nsImGuiWidgets_TNode_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TNode_n, nsImGuiWidgets_TNode_i });
    
    int nsImGuiWidgets_TPadding_i = globalTypeIdentifier->Type<nsImGuiWidgets::TPadding>();
    std::string nsImGuiWidgets_TPadding_n = "nsImGuiWidgets::TPadding";
    mTypeNameList.push_back(nsImGuiWidgets_TPadding_n);
    mRttiList.push_back(nsImGuiWidgets_TPadding_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TPadding_n, nsImGuiWidgets_TPadding_i });
    
    int nsImGuiWidgets_TPopupMenu_i = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupMenu>();
    std::string nsImGuiWidgets_TPopupMenu_n = "nsImGuiWidgets::TPopupMenu";
    mTypeNameList.push_back(nsImGuiWidgets_TPopupMenu_n);
    mRttiList.push_back(nsImGuiWidgets_TPopupMenu_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TPopupMenu_n, nsImGuiWidgets_TPopupMenu_i });
    
    int nsImGuiWidgets_TPopupNode_i = globalTypeIdentifier->Type<nsImGuiWidgets::TPopupNode>();
    std::string nsImGuiWidgets_TPopupNode_n = "nsImGuiWidgets::TPopupNode";
    mTypeNameList.push_back(nsImGuiWidgets_TPopupNode_n);
    mRttiList.push_back(nsImGuiWidgets_TPopupNode_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TPopupNode_n, nsImGuiWidgets_TPopupNode_i });
    
    int nsImGuiWidgets_TPosition_i = globalTypeIdentifier->Type<nsImGuiWidgets::TPosition>();
    std::string nsImGuiWidgets_TPosition_n = "nsImGuiWidgets::TPosition";
    mTypeNameList.push_back(nsImGuiWidgets_TPosition_n);
    mRttiList.push_back(nsImGuiWidgets_TPosition_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TPosition_n, nsImGuiWidgets_TPosition_i });
    
    int nsImGuiWidgets_TProtoFrame_i = globalTypeIdentifier->Type<nsImGuiWidgets::TProtoFrame>();
    std::string nsImGuiWidgets_TProtoFrame_n = "nsImGuiWidgets::TProtoFrame";
    mTypeNameList.push_back(nsImGuiWidgets_TProtoFrame_n);
    mRttiList.push_back(nsImGuiWidgets_TProtoFrame_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TProtoFrame_n, nsImGuiWidgets_TProtoFrame_i });
    
    int nsImGuiWidgets_TRootFrame_i = globalTypeIdentifier->Type<nsImGuiWidgets::TRootFrame>();
    std::string nsImGuiWidgets_TRootFrame_n = "nsImGuiWidgets::TRootFrame";
    mTypeNameList.push_back(nsImGuiWidgets_TRootFrame_n);
    mRttiList.push_back(nsImGuiWidgets_TRootFrame_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TRootFrame_n, nsImGuiWidgets_TRootFrame_i });
    
    int nsImGuiWidgets_TSeparator_i = globalTypeIdentifier->Type<nsImGuiWidgets::TSeparator>();
    std::string nsImGuiWidgets_TSeparator_n = "nsImGuiWidgets::TSeparator";
    mTypeNameList.push_back(nsImGuiWidgets_TSeparator_n);
    mRttiList.push_back(nsImGuiWidgets_TSeparator_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TSeparator_n, nsImGuiWidgets_TSeparator_i });
    
    int nsImGuiWidgets_TSize_i = globalTypeIdentifier->Type<nsImGuiWidgets::TSize>();
    std::string nsImGuiWidgets_TSize_n = "nsImGuiWidgets::TSize";
    mTypeNameList.push_back(nsImGuiWidgets_TSize_n);
    mRttiList.push_back(nsImGuiWidgets_TSize_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TSize_n, nsImGuiWidgets_TSize_i });
    
    int nsImGuiWidgets_TSpacing_i = globalTypeIdentifier->Type<nsImGuiWidgets::TSpacing>();
    std::string nsImGuiWidgets_TSpacing_n = "nsImGuiWidgets::TSpacing";
    mTypeNameList.push_back(nsImGuiWidgets_TSpacing_n);
    mRttiList.push_back(nsImGuiWidgets_TSpacing_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TSpacing_n, nsImGuiWidgets_TSpacing_i });
    
    int nsImGuiWidgets_TTextureReference_i = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureReference>();
    std::string nsImGuiWidgets_TTextureReference_n = "nsImGuiWidgets::TTextureReference";
    mTypeNameList.push_back(nsImGuiWidgets_TTextureReference_n);
    mRttiList.push_back(nsImGuiWidgets_TTextureReference_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TTextureReference_n, nsImGuiWidgets_TTextureReference_i });
    
    int nsImGuiWidgets_TTextureSize_i = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureSize>();
    std::string nsImGuiWidgets_TTextureSize_n = "nsImGuiWidgets::TTextureSize";
    mTypeNameList.push_back(nsImGuiWidgets_TTextureSize_n);
    mRttiList.push_back(nsImGuiWidgets_TTextureSize_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TTextureSize_n, nsImGuiWidgets_TTextureSize_i });
    
    int nsImGuiWidgets_TTextureUv_i = globalTypeIdentifier->Type<nsImGuiWidgets::TTextureUv>();
    std::string nsImGuiWidgets_TTextureUv_n = "nsImGuiWidgets::TTextureUv";
    mTypeNameList.push_back(nsImGuiWidgets_TTextureUv_n);
    mRttiList.push_back(nsImGuiWidgets_TTextureUv_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TTextureUv_n, nsImGuiWidgets_TTextureUv_i });
    
    int nsImGuiWidgets_TTexturedFrame_i = globalTypeIdentifier->Type<nsImGuiWidgets::TTexturedFrame>();
    std::string nsImGuiWidgets_TTexturedFrame_n = "nsImGuiWidgets::TTexturedFrame";
    mTypeNameList.push_back(nsImGuiWidgets_TTexturedFrame_n);
    mRttiList.push_back(nsImGuiWidgets_TTexturedFrame_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TTexturedFrame_n, nsImGuiWidgets_TTexturedFrame_i });
    
    int nsImGuiWidgets_TTitle_i = globalTypeIdentifier->Type<nsImGuiWidgets::TTitle>();
    std::string nsImGuiWidgets_TTitle_n = "nsImGuiWidgets::TTitle";
    mTypeNameList.push_back(nsImGuiWidgets_TTitle_n);
    mRttiList.push_back(nsImGuiWidgets_TTitle_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TTitle_n, nsImGuiWidgets_TTitle_i });
    
    int nsImGuiWidgets_TToolTip_i = globalTypeIdentifier->Type<nsImGuiWidgets::TToolTip>();
    std::string nsImGuiWidgets_TToolTip_n = "nsImGuiWidgets::TToolTip";
    mTypeNameList.push_back(nsImGuiWidgets_TToolTip_n);
    mRttiList.push_back(nsImGuiWidgets_TToolTip_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TToolTip_n, nsImGuiWidgets_TToolTip_i });
    
    int nsImGuiWidgets_TTreeNode_i = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeNode>();
    std::string nsImGuiWidgets_TTreeNode_n = "nsImGuiWidgets::TTreeNode";
    mTypeNameList.push_back(nsImGuiWidgets_TTreeNode_n);
    mRttiList.push_back(nsImGuiWidgets_TTreeNode_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TTreeNode_n, nsImGuiWidgets_TTreeNode_i });
    
    int nsImGuiWidgets_TTreeView_i = globalTypeIdentifier->Type<nsImGuiWidgets::TTreeView>();
    std::string nsImGuiWidgets_TTreeView_n = "nsImGuiWidgets::TTreeView";
    mTypeNameList.push_back(nsImGuiWidgets_TTreeView_n);
    mRttiList.push_back(nsImGuiWidgets_TTreeView_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TTreeView_n, nsImGuiWidgets_TTreeView_i });
    
    int nsImGuiWidgets_TUnit_i = globalTypeIdentifier->Type<nsImGuiWidgets::TUnit>();
    std::string nsImGuiWidgets_TUnit_n = "nsImGuiWidgets::TUnit";
    mTypeNameList.push_back(nsImGuiWidgets_TUnit_n);
    mRttiList.push_back(nsImGuiWidgets_TUnit_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TUnit_n, nsImGuiWidgets_TUnit_i });
    
    int nsImGuiWidgets_TVerticalAlign_i = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign>();
    std::string nsImGuiWidgets_TVerticalAlign_n = "nsImGuiWidgets::TVerticalAlign";
    mTypeNameList.push_back(nsImGuiWidgets_TVerticalAlign_n);
    mRttiList.push_back(nsImGuiWidgets_TVerticalAlign_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TVerticalAlign_n, nsImGuiWidgets_TVerticalAlign_i });
    
    int nsImGuiWidgets_TVisibility_i = globalTypeIdentifier->Type<nsImGuiWidgets::TVisibility>();
    std::string nsImGuiWidgets_TVisibility_n = "nsImGuiWidgets::TVisibility";
    mTypeNameList.push_back(nsImGuiWidgets_TVisibility_n);
    mRttiList.push_back(nsImGuiWidgets_TVisibility_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TVisibility_n, nsImGuiWidgets_TVisibility_i });
    
    int nsImGuiWidgets_TWidget_i = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget>();
    std::string nsImGuiWidgets_TWidget_n = "nsImGuiWidgets::TWidget";
    mTypeNameList.push_back(nsImGuiWidgets_TWidget_n);
    mRttiList.push_back(nsImGuiWidgets_TWidget_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TWidget_n, nsImGuiWidgets_TWidget_i });
    
    int nsImGuiWidgets_TWidgetContainer_i = globalTypeIdentifier->Type<nsImGuiWidgets::TWidgetContainer>();
    std::string nsImGuiWidgets_TWidgetContainer_n = "nsImGuiWidgets::TWidgetContainer";
    mTypeNameList.push_back(nsImGuiWidgets_TWidgetContainer_n);
    mRttiList.push_back(nsImGuiWidgets_TWidgetContainer_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TWidgetContainer_n, nsImGuiWidgets_TWidgetContainer_i });
    
    int nsImGuiWidgets_TWindow_i = globalTypeIdentifier->Type<nsImGuiWidgets::TWindow>();
    std::string nsImGuiWidgets_TWindow_n = "nsImGuiWidgets::TWindow";
    mTypeNameList.push_back(nsImGuiWidgets_TWindow_n);
    mRttiList.push_back(nsImGuiWidgets_TWindow_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TWindow_n, nsImGuiWidgets_TWindow_i });
    
    int nsImGuiWidgets_TAnchors_TAnchor_i = globalTypeIdentifier->Type<nsImGuiWidgets::TAnchors::TAnchor>();
    std::string nsImGuiWidgets_TAnchors_TAnchor_n = "nsImGuiWidgets::TAnchors::TAnchor";
    mTypeNameList.push_back(nsImGuiWidgets_TAnchors_TAnchor_n);
    mRttiList.push_back(nsImGuiWidgets_TAnchors_TAnchor_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TAnchors_TAnchor_n, nsImGuiWidgets_TAnchors_TAnchor_i });
    
    int nsImGuiWidgets_TDockNode_Type_i = globalTypeIdentifier->Type<nsImGuiWidgets::TDockNode::Type>();
    std::string nsImGuiWidgets_TDockNode_Type_n = "nsImGuiWidgets::TDockNode::Type";
    mTypeNameList.push_back(nsImGuiWidgets_TDockNode_Type_n);
    mRttiList.push_back(nsImGuiWidgets_TDockNode_Type_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TDockNode_Type_n, nsImGuiWidgets_TDockNode_Type_i });
    
    int nsImGuiWidgets_TGrid_TCell_i = globalTypeIdentifier->Type<nsImGuiWidgets::TGrid::TCell>();
    std::string nsImGuiWidgets_TGrid_TCell_n = "nsImGuiWidgets::TGrid::TCell";
    mTypeNameList.push_back(nsImGuiWidgets_TGrid_TCell_n);
    mRttiList.push_back(nsImGuiWidgets_TGrid_TCell_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TGrid_TCell_n, nsImGuiWidgets_TGrid_TCell_i });
    
    int nsImGuiWidgets_TGrid_TCellPosition_i = globalTypeIdentifier->Type<nsImGuiWidgets::TGrid::TCellPosition>();
    std::string nsImGuiWidgets_TGrid_TCellPosition_n = "nsImGuiWidgets::TGrid::TCellPosition";
    mTypeNameList.push_back(nsImGuiWidgets_TGrid_TCellPosition_n);
    mRttiList.push_back(nsImGuiWidgets_TGrid_TCellPosition_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TGrid_TCellPosition_n, nsImGuiWidgets_TGrid_TCellPosition_i });
    
    int nsImGuiWidgets_TGrid_TCellSize_i = globalTypeIdentifier->Type<nsImGuiWidgets::TGrid::TCellSize>();
    std::string nsImGuiWidgets_TGrid_TCellSize_n = "nsImGuiWidgets::TGrid::TCellSize";
    mTypeNameList.push_back(nsImGuiWidgets_TGrid_TCellSize_n);
    mRttiList.push_back(nsImGuiWidgets_TGrid_TCellSize_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TGrid_TCellSize_n, nsImGuiWidgets_TGrid_TCellSize_i });
    
    int nsImGuiWidgets_THorizontalAlign_Type_i = globalTypeIdentifier->Type<nsImGuiWidgets::THorizontalAlign::Type>();
    std::string nsImGuiWidgets_THorizontalAlign_Type_n = "nsImGuiWidgets::THorizontalAlign::Type";
    mTypeNameList.push_back(nsImGuiWidgets_THorizontalAlign_Type_n);
    mRttiList.push_back(nsImGuiWidgets_THorizontalAlign_Type_i);
    mNameRttiMap.insert({ nsImGuiWidgets_THorizontalAlign_Type_n, nsImGuiWidgets_THorizontalAlign_Type_i });
    
    int nsImGuiWidgets_TVerticalAlign_Type_i = globalTypeIdentifier->Type<nsImGuiWidgets::TVerticalAlign::Type>();
    std::string nsImGuiWidgets_TVerticalAlign_Type_n = "nsImGuiWidgets::TVerticalAlign::Type";
    mTypeNameList.push_back(nsImGuiWidgets_TVerticalAlign_Type_n);
    mRttiList.push_back(nsImGuiWidgets_TVerticalAlign_Type_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TVerticalAlign_Type_n, nsImGuiWidgets_TVerticalAlign_Type_i });
    
    int nsImGuiWidgets_TWidget_SubType_i = globalTypeIdentifier->Type<nsImGuiWidgets::TWidget::SubType>();
    std::string nsImGuiWidgets_TWidget_SubType_n = "nsImGuiWidgets::TWidget::SubType";
    mTypeNameList.push_back(nsImGuiWidgets_TWidget_SubType_n);
    mRttiList.push_back(nsImGuiWidgets_TWidget_SubType_i);
    mNameRttiMap.insert({ nsImGuiWidgets_TWidget_SubType_n, nsImGuiWidgets_TWidget_SubType_i });
    
    int max = 0;
    for (auto& nameRtti : mNameRttiMap) {
        max = std::max(max, nameRtti.second);
    }
    mNameVector.resize(max + 1);
    for (auto& nameRtti : mNameRttiMap) {
        mNameVector[nameRtti.second] = nameRtti.first;
    }
}
//---------------------------------------------------------------------------------------
const std::list<std::string>* TImGuiWidgetsTypeInfo::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TImGuiWidgetsTypeInfo::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TImGuiWidgetsTypeInfo::ConvertRttiToName(int rtti)
{
    Init();
    
    if (rtti < 0 || rtti >= mNameVector.size()) {
        return nullptr;
    }
    auto pStr = &(mNameVector[rtti]);
    if (pStr->size() == 0) {
        return nullptr;
    }
    return pStr;
}
//---------------------------------------------------------------------------------------
bool TImGuiWidgetsTypeInfo::ConvertNameToRtti(const std::string& typeName, int& rtti)
{
    Init();
    auto fit = mNameRttiMap.find(typeName);
    if (fit == mNameRttiMap.end()) {
        return false;
    }
    rtti = fit->second;
    return true;
}
//---------------------------------------------------------------------------------------
