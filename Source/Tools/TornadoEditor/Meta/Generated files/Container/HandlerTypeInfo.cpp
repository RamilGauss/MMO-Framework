/*
Project Handler
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_11_12 12:58:30.681
	
#include "HandlerTypeInfo.h"

#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"
#include "Parser/Sources/Generated files/JsonSerializer.h"

using namespace nsTornadoEditor;

std::vector<std::shared_ptr<nsCppParser::TTypeInfo>> THandlerTypeInfo::mTypeInoVector;

void THandlerTypeInfo::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, std::shared_ptr<nsCppParser::TTypeInfo>> m;
    int nsTornadoEditor_TCurrentPathToInputTextHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TCurrentPathToInputTextHandler>();
    std::string nsTornadoEditor_TCurrentPathToInputTextHandler_jc = "{"
"    \"mFileName\": \"CurrentPathToInputTextHandler.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Tools\\\\TornadoEditor\\\\Sources\\\\Handlers\\\\CurrentPathToInputTextHandler.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsLogicWrapper::IObjectInstantiationCompletionHandler\","
"            \"mOriginalTypeName\": \"nsLogicWrapper::IObjectInstantiationCompletionHandler\","
"            \"mOriginalNameSpace\": \"nsLogicWrapper\","
"            \"mShortTypeName\": \"IObjectInstantiationCompletionHandler\","
"            \"mNameSpace\": \"nsTornadoEditor\","
"            \"mLongTypeName\": \"nsTornadoEditor::nsLogicWrapper::IObjectInstantiationCompletionHandler\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TCurrentPathToInputTextHandler\","
"    \"mNamespaceVec\": ["
"        \"nsTornadoEditor\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsTornadoEditor_TCurrentPathToInputTextHandler_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsTornadoEditor_TCurrentPathToInputTextHandler_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsTornadoEditor_TCurrentPathToInputTextHandler_p_type.get(), nsTornadoEditor_TCurrentPathToInputTextHandler_jc, nsTornadoEditor_TCurrentPathToInputTextHandler_err);
    m.insert({ nsTornadoEditor_TCurrentPathToInputTextHandler_i, nsTornadoEditor_TCurrentPathToInputTextHandler_p_type });
    
    int nsTornadoEditor_TDialogButtonClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TDialogButtonClickHandler>();
    std::string nsTornadoEditor_TDialogButtonClickHandler_jc = "{"
"    \"mFileName\": \"DialogButtonClickHandler.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Tools\\\\TornadoEditor\\\\Sources\\\\Handlers\\\\DialogButtonClickHandler.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsGuiWrapper::IButtonClickHandler\","
"            \"mOriginalTypeName\": \"nsGuiWrapper::IButtonClickHandler\","
"            \"mOriginalNameSpace\": \"nsGuiWrapper\","
"            \"mShortTypeName\": \"IButtonClickHandler\","
"            \"mNameSpace\": \"nsTornadoEditor\","
"            \"mLongTypeName\": \"nsTornadoEditor::nsGuiWrapper::IButtonClickHandler\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TDialogButtonClickHandler\","
"    \"mNamespaceVec\": ["
"        \"nsTornadoEditor\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsTornadoEditor_TDialogButtonClickHandler_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsTornadoEditor_TDialogButtonClickHandler_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsTornadoEditor_TDialogButtonClickHandler_p_type.get(), nsTornadoEditor_TDialogButtonClickHandler_jc, nsTornadoEditor_TDialogButtonClickHandler_err);
    m.insert({ nsTornadoEditor_TDialogButtonClickHandler_i, nsTornadoEditor_TDialogButtonClickHandler_p_type });
    
    int nsTornadoEditor_TOnExitClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnExitClickHandler>();
    std::string nsTornadoEditor_TOnExitClickHandler_jc = "{"
"    \"mFileName\": \"OnExitClickHandler.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Tools\\\\TornadoEditor\\\\Sources\\\\Handlers\\\\OnExitClickHandler.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsGuiWrapper::IMenuNodeClickHandler\","
"            \"mOriginalTypeName\": \"nsGuiWrapper::IMenuNodeClickHandler\","
"            \"mOriginalNameSpace\": \"nsGuiWrapper\","
"            \"mShortTypeName\": \"IMenuNodeClickHandler\","
"            \"mNameSpace\": \"nsTornadoEditor\","
"            \"mLongTypeName\": \"nsTornadoEditor::nsGuiWrapper::IMenuNodeClickHandler\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TOnExitClickHandler\","
"    \"mNamespaceVec\": ["
"        \"nsTornadoEditor\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsTornadoEditor_TOnExitClickHandler_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsTornadoEditor_TOnExitClickHandler_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsTornadoEditor_TOnExitClickHandler_p_type.get(), nsTornadoEditor_TOnExitClickHandler_jc, nsTornadoEditor_TOnExitClickHandler_err);
    m.insert({ nsTornadoEditor_TOnExitClickHandler_i, nsTornadoEditor_TOnExitClickHandler_p_type });
    
    int nsTornadoEditor_TOnFileHierarchyClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnFileHierarchyClickHandler>();
    std::string nsTornadoEditor_TOnFileHierarchyClickHandler_jc = "{"
"    \"mFileName\": \"OnFileHierarchyClickHandler.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Tools\\\\TornadoEditor\\\\Sources\\\\Handlers\\\\OnFileHierarchyClickHandler.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsGuiWrapper::IMenuNodeClickHandler\","
"            \"mOriginalTypeName\": \"nsGuiWrapper::IMenuNodeClickHandler\","
"            \"mOriginalNameSpace\": \"nsGuiWrapper\","
"            \"mShortTypeName\": \"IMenuNodeClickHandler\","
"            \"mNameSpace\": \"nsTornadoEditor\","
"            \"mLongTypeName\": \"nsTornadoEditor::nsGuiWrapper::IMenuNodeClickHandler\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TOnFileHierarchyClickHandler\","
"    \"mNamespaceVec\": ["
"        \"nsTornadoEditor\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsTornadoEditor_TOnFileHierarchyClickHandler_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsTornadoEditor_TOnFileHierarchyClickHandler_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsTornadoEditor_TOnFileHierarchyClickHandler_p_type.get(), nsTornadoEditor_TOnFileHierarchyClickHandler_jc, nsTornadoEditor_TOnFileHierarchyClickHandler_err);
    m.insert({ nsTornadoEditor_TOnFileHierarchyClickHandler_i, nsTornadoEditor_TOnFileHierarchyClickHandler_p_type });
    
    int nsTornadoEditor_TOnMouseClickFileNodeHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnMouseClickFileNodeHandler>();
    std::string nsTornadoEditor_TOnMouseClickFileNodeHandler_jc = "{"
"    \"mFileName\": \"OnMouseClickFileNodeHandler.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Tools\\\\TornadoEditor\\\\Sources\\\\Handlers\\\\OnMouseClickFileNodeHandler.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsGuiWrapper::IFrameMouseClickHandler\","
"            \"mOriginalTypeName\": \"nsGuiWrapper::IFrameMouseClickHandler\","
"            \"mOriginalNameSpace\": \"nsGuiWrapper\","
"            \"mShortTypeName\": \"IFrameMouseClickHandler\","
"            \"mNameSpace\": \"nsTornadoEditor\","
"            \"mLongTypeName\": \"nsTornadoEditor::nsGuiWrapper::IFrameMouseClickHandler\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TOnMouseClickFileNodeHandler\","
"    \"mNamespaceVec\": ["
"        \"nsTornadoEditor\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsTornadoEditor_TOnMouseClickFileNodeHandler_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsTornadoEditor_TOnMouseClickFileNodeHandler_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsTornadoEditor_TOnMouseClickFileNodeHandler_p_type.get(), nsTornadoEditor_TOnMouseClickFileNodeHandler_jc, nsTornadoEditor_TOnMouseClickFileNodeHandler_err);
    m.insert({ nsTornadoEditor_TOnMouseClickFileNodeHandler_i, nsTornadoEditor_TOnMouseClickFileNodeHandler_p_type });
    
    int nsTornadoEditor_TOnOpenComponentViewerClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenComponentViewerClickHandler>();
    std::string nsTornadoEditor_TOnOpenComponentViewerClickHandler_jc = "{"
"    \"mFileName\": \"OnOpenComponentViewerClickHandler.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Tools\\\\TornadoEditor\\\\Sources\\\\Handlers\\\\OnOpenComponentViewerClickHandler.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsGuiWrapper::IMenuNodeClickHandler\","
"            \"mOriginalTypeName\": \"nsGuiWrapper::IMenuNodeClickHandler\","
"            \"mOriginalNameSpace\": \"nsGuiWrapper\","
"            \"mShortTypeName\": \"IMenuNodeClickHandler\","
"            \"mNameSpace\": \"nsTornadoEditor\","
"            \"mLongTypeName\": \"nsTornadoEditor::nsGuiWrapper::IMenuNodeClickHandler\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TOnOpenComponentViewerClickHandler\","
"    \"mNamespaceVec\": ["
"        \"nsTornadoEditor\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsTornadoEditor_TOnOpenComponentViewerClickHandler_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsTornadoEditor_TOnOpenComponentViewerClickHandler_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsTornadoEditor_TOnOpenComponentViewerClickHandler_p_type.get(), nsTornadoEditor_TOnOpenComponentViewerClickHandler_jc, nsTornadoEditor_TOnOpenComponentViewerClickHandler_err);
    m.insert({ nsTornadoEditor_TOnOpenComponentViewerClickHandler_i, nsTornadoEditor_TOnOpenComponentViewerClickHandler_p_type });
    
    int nsTornadoEditor_TOnOpenProjectClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenProjectClickHandler>();
    std::string nsTornadoEditor_TOnOpenProjectClickHandler_jc = "{"
"    \"mFileName\": \"OnOpenProjectClickHandler.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Tools\\\\TornadoEditor\\\\Sources\\\\Handlers\\\\OnOpenProjectClickHandler.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsGuiWrapper::IMenuNodeClickHandler\","
"            \"mOriginalTypeName\": \"nsGuiWrapper::IMenuNodeClickHandler\","
"            \"mOriginalNameSpace\": \"nsGuiWrapper\","
"            \"mShortTypeName\": \"IMenuNodeClickHandler\","
"            \"mNameSpace\": \"nsTornadoEditor\","
"            \"mLongTypeName\": \"nsTornadoEditor::nsGuiWrapper::IMenuNodeClickHandler\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TOnOpenProjectClickHandler\","
"    \"mNamespaceVec\": ["
"        \"nsTornadoEditor\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsTornadoEditor_TOnOpenProjectClickHandler_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsTornadoEditor_TOnOpenProjectClickHandler_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsTornadoEditor_TOnOpenProjectClickHandler_p_type.get(), nsTornadoEditor_TOnOpenProjectClickHandler_jc, nsTornadoEditor_TOnOpenProjectClickHandler_err);
    m.insert({ nsTornadoEditor_TOnOpenProjectClickHandler_i, nsTornadoEditor_TOnOpenProjectClickHandler_p_type });
    
    int nsTornadoEditor_TOnOpenSystemViewerClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenSystemViewerClickHandler>();
    std::string nsTornadoEditor_TOnOpenSystemViewerClickHandler_jc = "{"
"    \"mFileName\": \"OnOpenSystemViewerClickHandler.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Tools\\\\TornadoEditor\\\\Sources\\\\Handlers\\\\OnOpenSystemViewerClickHandler.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsGuiWrapper::IMenuNodeClickHandler\","
"            \"mOriginalTypeName\": \"nsGuiWrapper::IMenuNodeClickHandler\","
"            \"mOriginalNameSpace\": \"nsGuiWrapper\","
"            \"mShortTypeName\": \"IMenuNodeClickHandler\","
"            \"mNameSpace\": \"nsTornadoEditor\","
"            \"mLongTypeName\": \"nsTornadoEditor::nsGuiWrapper::IMenuNodeClickHandler\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TOnOpenSystemViewerClickHandler\","
"    \"mNamespaceVec\": ["
"        \"nsTornadoEditor\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsTornadoEditor_TOnOpenSystemViewerClickHandler_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsTornadoEditor_TOnOpenSystemViewerClickHandler_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsTornadoEditor_TOnOpenSystemViewerClickHandler_p_type.get(), nsTornadoEditor_TOnOpenSystemViewerClickHandler_jc, nsTornadoEditor_TOnOpenSystemViewerClickHandler_err);
    m.insert({ nsTornadoEditor_TOnOpenSystemViewerClickHandler_i, nsTornadoEditor_TOnOpenSystemViewerClickHandler_p_type });
    
    int nsTornadoEditor_TOpenProjectCancelButtonClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOpenProjectCancelButtonClickHandler>();
    std::string nsTornadoEditor_TOpenProjectCancelButtonClickHandler_jc = "{"
"    \"mFileName\": \"OpenProjectCancelButtonClickHandler.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Tools\\\\TornadoEditor\\\\Sources\\\\Handlers\\\\OpenProjectCancelButtonClickHandler.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsGuiWrapper::IButtonClickHandler\","
"            \"mOriginalTypeName\": \"nsGuiWrapper::IButtonClickHandler\","
"            \"mOriginalNameSpace\": \"nsGuiWrapper\","
"            \"mShortTypeName\": \"IButtonClickHandler\","
"            \"mNameSpace\": \"nsTornadoEditor\","
"            \"mLongTypeName\": \"nsTornadoEditor::nsGuiWrapper::IButtonClickHandler\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TOpenProjectCancelButtonClickHandler\","
"    \"mNamespaceVec\": ["
"        \"nsTornadoEditor\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsTornadoEditor_TOpenProjectCancelButtonClickHandler_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsTornadoEditor_TOpenProjectCancelButtonClickHandler_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsTornadoEditor_TOpenProjectCancelButtonClickHandler_p_type.get(), nsTornadoEditor_TOpenProjectCancelButtonClickHandler_jc, nsTornadoEditor_TOpenProjectCancelButtonClickHandler_err);
    m.insert({ nsTornadoEditor_TOpenProjectCancelButtonClickHandler_i, nsTornadoEditor_TOpenProjectCancelButtonClickHandler_p_type });
    
    int nsTornadoEditor_TOpenProjectOkButtonClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOpenProjectOkButtonClickHandler>();
    std::string nsTornadoEditor_TOpenProjectOkButtonClickHandler_jc = "{"
"    \"mFileName\": \"OpenProjectOkButtonClickHandler.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Tools\\\\TornadoEditor\\\\Sources\\\\Handlers\\\\OpenProjectOkButtonClickHandler.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsGuiWrapper::IButtonClickHandler\","
"            \"mOriginalTypeName\": \"nsGuiWrapper::IButtonClickHandler\","
"            \"mOriginalNameSpace\": \"nsGuiWrapper\","
"            \"mShortTypeName\": \"IButtonClickHandler\","
"            \"mNameSpace\": \"nsTornadoEditor\","
"            \"mLongTypeName\": \"nsTornadoEditor::nsGuiWrapper::IButtonClickHandler\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TOpenProjectOkButtonClickHandler\","
"    \"mNamespaceVec\": ["
"        \"nsTornadoEditor\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsTornadoEditor_TOpenProjectOkButtonClickHandler_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsTornadoEditor_TOpenProjectOkButtonClickHandler_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsTornadoEditor_TOpenProjectOkButtonClickHandler_p_type.get(), nsTornadoEditor_TOpenProjectOkButtonClickHandler_jc, nsTornadoEditor_TOpenProjectOkButtonClickHandler_err);
    m.insert({ nsTornadoEditor_TOpenProjectOkButtonClickHandler_i, nsTornadoEditor_TOpenProjectOkButtonClickHandler_p_type });
    
    int max = 0;
    for (auto& rttiType : m) {
        max = std::max(max, rttiType.first);
    }
    mTypeInoVector.resize(max + 1);
    for (auto& rttiType : m) {
        mTypeInoVector[rttiType.first] = rttiType.second;
    }
}
//---------------------------------------------------------------------------------------
const nsCppParser::TTypeInfo* THandlerTypeInfo::Get(int rtti)
{
    Init();
    return mTypeInoVector[rtti].get();
}
//---------------------------------------------------------------------------------------
