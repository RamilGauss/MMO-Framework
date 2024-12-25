/*
Core Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2024_12_25 11:43:17.761
#include "ComponentDynamicCaster.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

std::vector<std::vector<TComponentDynamicCaster::Data>> TComponentDynamicCaster::mDataVector;
std::map<int, std::set<int>> TComponentDynamicCaster::mRttiCombinations;

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

void TComponentDynamicCaster::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, std::map<int, Data>> m;
    
    std::map<int, Data> nsCommonWrapper_TGlobalMatrixComponent_Map;
    
    Data nsCommonWrapper_TGlobalMatrixComponent_nsTornadoEngine_IPropertyOf_Data;
    nsCommonWrapper_TGlobalMatrixComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsCommonWrapper::TGlobalMatrixComponent>(p); };
    auto nsCommonWrapper_TGlobalMatrixComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsCommonWrapper_TGlobalMatrixComponent_Map.insert({ nsCommonWrapper_TGlobalMatrixComponent_nsTornadoEngine_IPropertyOf_rtti, nsCommonWrapper_TGlobalMatrixComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsCommonWrapper_TGlobalMatrixComponent_rtti = globalTypeIdentifier->Type<nsCommonWrapper::TGlobalMatrixComponent>();
    
    m.insert({ nsCommonWrapper_TGlobalMatrixComponent_rtti, nsCommonWrapper_TGlobalMatrixComponent_Map });
    
    std::map<int, Data> nsGraphicWrapper_TTextureFromFileComponent_Map;
    
    Data nsGraphicWrapper_TTextureFromFileComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGraphicWrapper_TTextureFromFileComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGraphicWrapper::TTextureFromFileComponent>(p); };
    auto nsGraphicWrapper_TTextureFromFileComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGraphicWrapper_TTextureFromFileComponent_Map.insert({ nsGraphicWrapper_TTextureFromFileComponent_nsTornadoEngine_IPropertyOf_rtti, nsGraphicWrapper_TTextureFromFileComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGraphicWrapper_TTextureFromFileComponent_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromFileComponent>();
    
    m.insert({ nsGraphicWrapper_TTextureFromFileComponent_rtti, nsGraphicWrapper_TTextureFromFileComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TAnchorsComponent_Map;
    
    Data nsGuiWrapper_TAnchorsComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TAnchorsComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TAnchorsComponent>(p); };
    auto nsGuiWrapper_TAnchorsComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TAnchorsComponent_Map.insert({ nsGuiWrapper_TAnchorsComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TAnchorsComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TAnchorsComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TAnchorsComponent>();
    
    m.insert({ nsGuiWrapper_TAnchorsComponent_rtti, nsGuiWrapper_TAnchorsComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TColorComponent_Map;
    
    Data nsGuiWrapper_TColorComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TColorComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TColorComponent>(p); };
    auto nsGuiWrapper_TColorComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TColorComponent_Map.insert({ nsGuiWrapper_TColorComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TColorComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TColorComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TColorComponent>();
    
    m.insert({ nsGuiWrapper_TColorComponent_rtti, nsGuiWrapper_TColorComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TFocusComponent_Map;
    
    Data nsGuiWrapper_TFocusComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TFocusComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TFocusComponent>(p); };
    auto nsGuiWrapper_TFocusComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TFocusComponent_Map.insert({ nsGuiWrapper_TFocusComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TFocusComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TFocusComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TFocusComponent>();
    
    m.insert({ nsGuiWrapper_TFocusComponent_rtti, nsGuiWrapper_TFocusComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TGridComponent_Map;
    
    Data nsGuiWrapper_TGridComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TGridComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TGridComponent>(p); };
    auto nsGuiWrapper_TGridComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TGridComponent_Map.insert({ nsGuiWrapper_TGridComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TGridComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TGridComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TGridComponent>();
    
    m.insert({ nsGuiWrapper_TGridComponent_rtti, nsGuiWrapper_TGridComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_THorizontalAlignComponent_Map;
    
    Data nsGuiWrapper_THorizontalAlignComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_THorizontalAlignComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::THorizontalAlignComponent>(p); };
    auto nsGuiWrapper_THorizontalAlignComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_THorizontalAlignComponent_Map.insert({ nsGuiWrapper_THorizontalAlignComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_THorizontalAlignComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_THorizontalAlignComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::THorizontalAlignComponent>();
    
    m.insert({ nsGuiWrapper_THorizontalAlignComponent_rtti, nsGuiWrapper_THorizontalAlignComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TInputTextValueComponent_Map;
    
    Data nsGuiWrapper_TInputTextValueComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TInputTextValueComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TInputTextValueComponent>(p); };
    auto nsGuiWrapper_TInputTextValueComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TInputTextValueComponent_Map.insert({ nsGuiWrapper_TInputTextValueComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TInputTextValueComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TInputTextValueComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextValueComponent>();
    
    m.insert({ nsGuiWrapper_TInputTextValueComponent_rtti, nsGuiWrapper_TInputTextValueComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TLabelValueComponent_Map;
    
    Data nsGuiWrapper_TLabelValueComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TLabelValueComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TLabelValueComponent>(p); };
    auto nsGuiWrapper_TLabelValueComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TLabelValueComponent_Map.insert({ nsGuiWrapper_TLabelValueComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TLabelValueComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TLabelValueComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TLabelValueComponent>();
    
    m.insert({ nsGuiWrapper_TLabelValueComponent_rtti, nsGuiWrapper_TLabelValueComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TMaxSizeComponent_Map;
    
    Data nsGuiWrapper_TMaxSizeComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TMaxSizeComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TMaxSizeComponent>(p); };
    auto nsGuiWrapper_TMaxSizeComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TMaxSizeComponent_Map.insert({ nsGuiWrapper_TMaxSizeComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TMaxSizeComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TMaxSizeComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMaxSizeComponent>();
    
    m.insert({ nsGuiWrapper_TMaxSizeComponent_rtti, nsGuiWrapper_TMaxSizeComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TMinDistanceToParentComponent_Map;
    
    Data nsGuiWrapper_TMinDistanceToParentComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TMinDistanceToParentComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TMinDistanceToParentComponent>(p); };
    auto nsGuiWrapper_TMinDistanceToParentComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TMinDistanceToParentComponent_Map.insert({ nsGuiWrapper_TMinDistanceToParentComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TMinDistanceToParentComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TMinDistanceToParentComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMinDistanceToParentComponent>();
    
    m.insert({ nsGuiWrapper_TMinDistanceToParentComponent_rtti, nsGuiWrapper_TMinDistanceToParentComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TMinSizeComponent_Map;
    
    Data nsGuiWrapper_TMinSizeComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TMinSizeComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TMinSizeComponent>(p); };
    auto nsGuiWrapper_TMinSizeComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TMinSizeComponent_Map.insert({ nsGuiWrapper_TMinSizeComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TMinSizeComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TMinSizeComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMinSizeComponent>();
    
    m.insert({ nsGuiWrapper_TMinSizeComponent_rtti, nsGuiWrapper_TMinSizeComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TNodeIconComponent_Map;
    
    Data nsGuiWrapper_TNodeIconComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TNodeIconComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TNodeIconComponent>(p); };
    auto nsGuiWrapper_TNodeIconComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TNodeIconComponent_Map.insert({ nsGuiWrapper_TNodeIconComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TNodeIconComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TNodeIconComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TNodeIconComponent>();
    
    m.insert({ nsGuiWrapper_TNodeIconComponent_rtti, nsGuiWrapper_TNodeIconComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TPaddingComponent_Map;
    
    Data nsGuiWrapper_TPaddingComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TPaddingComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TPaddingComponent>(p); };
    auto nsGuiWrapper_TPaddingComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TPaddingComponent_Map.insert({ nsGuiWrapper_TPaddingComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TPaddingComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TPaddingComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TPaddingComponent>();
    
    m.insert({ nsGuiWrapper_TPaddingComponent_rtti, nsGuiWrapper_TPaddingComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TPositionComponent_Map;
    
    Data nsGuiWrapper_TPositionComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TPositionComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TPositionComponent>(p); };
    auto nsGuiWrapper_TPositionComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TPositionComponent_Map.insert({ nsGuiWrapper_TPositionComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TPositionComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TPositionComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TPositionComponent>();
    
    m.insert({ nsGuiWrapper_TPositionComponent_rtti, nsGuiWrapper_TPositionComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TPositionInGridComponent_Map;
    
    Data nsGuiWrapper_TPositionInGridComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TPositionInGridComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TPositionInGridComponent>(p); };
    auto nsGuiWrapper_TPositionInGridComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TPositionInGridComponent_Map.insert({ nsGuiWrapper_TPositionInGridComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TPositionInGridComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TPositionInGridComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TPositionInGridComponent>();
    
    m.insert({ nsGuiWrapper_TPositionInGridComponent_rtti, nsGuiWrapper_TPositionInGridComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TSelectedTreeNodeGuidComponent_Map;
    
    Data nsGuiWrapper_TSelectedTreeNodeGuidComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TSelectedTreeNodeGuidComponent>(p); };
    auto nsGuiWrapper_TSelectedTreeNodeGuidComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TSelectedTreeNodeGuidComponent_Map.insert({ nsGuiWrapper_TSelectedTreeNodeGuidComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TSelectedTreeNodeGuidComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TSelectedTreeNodeGuidComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSelectedTreeNodeGuidComponent>();
    
    m.insert({ nsGuiWrapper_TSelectedTreeNodeGuidComponent_rtti, nsGuiWrapper_TSelectedTreeNodeGuidComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TSizeComponent_Map;
    
    Data nsGuiWrapper_TSizeComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TSizeComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TSizeComponent>(p); };
    auto nsGuiWrapper_TSizeComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TSizeComponent_Map.insert({ nsGuiWrapper_TSizeComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TSizeComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TSizeComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSizeComponent>();
    
    m.insert({ nsGuiWrapper_TSizeComponent_rtti, nsGuiWrapper_TSizeComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TSizeInGridComponent_Map;
    
    Data nsGuiWrapper_TSizeInGridComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TSizeInGridComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TSizeInGridComponent>(p); };
    auto nsGuiWrapper_TSizeInGridComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TSizeInGridComponent_Map.insert({ nsGuiWrapper_TSizeInGridComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TSizeInGridComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TSizeInGridComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSizeInGridComponent>();
    
    m.insert({ nsGuiWrapper_TSizeInGridComponent_rtti, nsGuiWrapper_TSizeInGridComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TSpacingComponent_Map;
    
    Data nsGuiWrapper_TSpacingComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TSpacingComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TSpacingComponent>(p); };
    auto nsGuiWrapper_TSpacingComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TSpacingComponent_Map.insert({ nsGuiWrapper_TSpacingComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TSpacingComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TSpacingComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSpacingComponent>();
    
    m.insert({ nsGuiWrapper_TSpacingComponent_rtti, nsGuiWrapper_TSpacingComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TTitleComponent_Map;
    
    Data nsGuiWrapper_TTitleComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TTitleComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TTitleComponent>(p); };
    auto nsGuiWrapper_TTitleComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TTitleComponent_Map.insert({ nsGuiWrapper_TTitleComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TTitleComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TTitleComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TTitleComponent>();
    
    m.insert({ nsGuiWrapper_TTitleComponent_rtti, nsGuiWrapper_TTitleComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TVerticalAlignComponent_Map;
    
    Data nsGuiWrapper_TVerticalAlignComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TVerticalAlignComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TVerticalAlignComponent>(p); };
    auto nsGuiWrapper_TVerticalAlignComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TVerticalAlignComponent_Map.insert({ nsGuiWrapper_TVerticalAlignComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TVerticalAlignComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TVerticalAlignComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TVerticalAlignComponent>();
    
    m.insert({ nsGuiWrapper_TVerticalAlignComponent_rtti, nsGuiWrapper_TVerticalAlignComponent_Map });
    
    std::map<int, Data> nsGuiWrapper_TVisibilityComponent_Map;
    
    Data nsGuiWrapper_TVisibilityComponent_nsTornadoEngine_IPropertyOf_Data;
    nsGuiWrapper_TVisibilityComponent_nsTornadoEngine_IPropertyOf_Data.castFunc = [](void* p){ return SmartCast<nsTornadoEngine::IPropertyOf, nsGuiWrapper::TVisibilityComponent>(p); };
    auto nsGuiWrapper_TVisibilityComponent_nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    nsGuiWrapper_TVisibilityComponent_Map.insert({ nsGuiWrapper_TVisibilityComponent_nsTornadoEngine_IPropertyOf_rtti, nsGuiWrapper_TVisibilityComponent_nsTornadoEngine_IPropertyOf_Data });
    
    auto nsGuiWrapper_TVisibilityComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TVisibilityComponent>();
    
    m.insert({ nsGuiWrapper_TVisibilityComponent_rtti, nsGuiWrapper_TVisibilityComponent_Map });
    
    std::map<int, Data> nsTornadoEngine_IPropertyOf_Map;
    
    Data nsTornadoEngine_IPropertyOf_nsCommonWrapper_TGlobalMatrixComponent_Data;
    nsTornadoEngine_IPropertyOf_nsCommonWrapper_TGlobalMatrixComponent_Data.castFunc = [](void* p){ return SmartCast<nsCommonWrapper::TGlobalMatrixComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsCommonWrapper_TGlobalMatrixComponent_rtti = globalTypeIdentifier->Type<nsCommonWrapper::TGlobalMatrixComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsCommonWrapper_TGlobalMatrixComponent_rtti, nsTornadoEngine_IPropertyOf_nsCommonWrapper_TGlobalMatrixComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGraphicWrapper_TTextureFromFileComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGraphicWrapper_TTextureFromFileComponent_Data.castFunc = [](void* p){ return SmartCast<nsGraphicWrapper::TTextureFromFileComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGraphicWrapper_TTextureFromFileComponent_rtti = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromFileComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGraphicWrapper_TTextureFromFileComponent_rtti, nsTornadoEngine_IPropertyOf_nsGraphicWrapper_TTextureFromFileComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TAnchorsComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TAnchorsComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TAnchorsComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TAnchorsComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TAnchorsComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TAnchorsComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TAnchorsComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TColorComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TColorComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TColorComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TColorComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TColorComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TColorComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TColorComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TFocusComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TFocusComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TFocusComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TFocusComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TFocusComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TFocusComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TFocusComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TGridComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TGridComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TGridComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TGridComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TGridComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TGridComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TGridComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_THorizontalAlignComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_THorizontalAlignComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::THorizontalAlignComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_THorizontalAlignComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::THorizontalAlignComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_THorizontalAlignComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_THorizontalAlignComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TInputTextValueComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TInputTextValueComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TInputTextValueComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TInputTextValueComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextValueComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TInputTextValueComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TInputTextValueComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TLabelValueComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TLabelValueComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TLabelValueComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TLabelValueComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TLabelValueComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TLabelValueComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TLabelValueComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMaxSizeComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMaxSizeComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TMaxSizeComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMaxSizeComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMaxSizeComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMaxSizeComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMaxSizeComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMinDistanceToParentComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMinDistanceToParentComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TMinDistanceToParentComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMinDistanceToParentComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMinDistanceToParentComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMinDistanceToParentComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMinDistanceToParentComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMinSizeComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMinSizeComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TMinSizeComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMinSizeComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TMinSizeComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMinSizeComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TMinSizeComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TNodeIconComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TNodeIconComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TNodeIconComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TNodeIconComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TNodeIconComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TNodeIconComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TNodeIconComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPaddingComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPaddingComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TPaddingComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPaddingComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TPaddingComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPaddingComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPaddingComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPositionComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPositionComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TPositionComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPositionComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TPositionComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPositionComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPositionComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPositionInGridComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPositionInGridComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TPositionInGridComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPositionInGridComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TPositionInGridComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPositionInGridComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TPositionInGridComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TSelectedTreeNodeGuidComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSelectedTreeNodeGuidComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSelectedTreeNodeGuidComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSelectedTreeNodeGuidComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSelectedTreeNodeGuidComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSizeComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSizeComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TSizeComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSizeComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSizeComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSizeComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSizeComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSizeInGridComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSizeInGridComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TSizeInGridComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSizeInGridComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSizeInGridComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSizeInGridComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSizeInGridComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSpacingComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSpacingComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TSpacingComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSpacingComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TSpacingComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSpacingComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TSpacingComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TTitleComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TTitleComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TTitleComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TTitleComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TTitleComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TTitleComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TTitleComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TVerticalAlignComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TVerticalAlignComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TVerticalAlignComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TVerticalAlignComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TVerticalAlignComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TVerticalAlignComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TVerticalAlignComponent_Data });
    
    Data nsTornadoEngine_IPropertyOf_nsGuiWrapper_TVisibilityComponent_Data;
    nsTornadoEngine_IPropertyOf_nsGuiWrapper_TVisibilityComponent_Data.castFunc = [](void* p){ return SmartCast<nsGuiWrapper::TVisibilityComponent, nsTornadoEngine::IPropertyOf>(p); };
    auto nsTornadoEngine_IPropertyOf_nsGuiWrapper_TVisibilityComponent_rtti = globalTypeIdentifier->Type<nsGuiWrapper::TVisibilityComponent>();
    
    nsTornadoEngine_IPropertyOf_Map.insert({ nsTornadoEngine_IPropertyOf_nsGuiWrapper_TVisibilityComponent_rtti, nsTornadoEngine_IPropertyOf_nsGuiWrapper_TVisibilityComponent_Data });
    
    auto nsTornadoEngine_IPropertyOf_rtti = globalTypeIdentifier->Type<nsTornadoEngine::IPropertyOf>();
    
    m.insert({ nsTornadoEngine_IPropertyOf_rtti, nsTornadoEngine_IPropertyOf_Map });
    
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
void* TComponentDynamicCaster::Cast(int srcRtti, void* p, int dstRtti)
{
    Init();
    return mDataVector[dstRtti][srcRtti].castFunc(p);
}
//---------------------------------------------------------------------------------------
const std::map<int, std::set<int>>& TComponentDynamicCaster::GetRttiCombinations()
{
    Init();
    return mRttiCombinations;
}
//---------------------------------------------------------------------------------------
