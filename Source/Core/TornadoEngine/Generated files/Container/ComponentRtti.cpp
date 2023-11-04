/*
Core Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_11_04 19:35:23.627
	
#include "ComponentRtti.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"
#include "Parser/Sources/Generated files/JsonSerializer.h"

using namespace nsTornadoEngine;

std::vector<std::shared_ptr<nsCppParser::TTypeInfo>> TComponentRtti::mTypeInoVector;

void TComponentRtti::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, std::shared_ptr<nsCppParser::TTypeInfo>> m;
    int nsCommonWrapper_TGlobalMatrixComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TGlobalMatrixComponent>();
    std::string nsCommonWrapper_TGlobalMatrixComponent_jc = "{"
"    \"mFileName\": \"GlobalMatrixComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Shared\\\\GlobalMatrixComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsGraphicEngine::TRenderableObject>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsGraphicEngine::TRenderableObject\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TGlobalMatrixComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TGlobalMatrixComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TGlobalMatrixComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TGlobalMatrixComponent_p_type.get(), nsCommonWrapper_TGlobalMatrixComponent_jc, nsCommonWrapper_TGlobalMatrixComponent_err);
    m.insert({ nsCommonWrapper_TGlobalMatrixComponent_i, nsCommonWrapper_TGlobalMatrixComponent_p_type });
    
    int nsCommonWrapper_TGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TGuidComponent>();
    std::string nsCommonWrapper_TGuidComponent_jc = "{"
"    \"mFileName\": \"GuidComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\GuidComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TGuidComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TGuidComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TGuidComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TGuidComponent_p_type.get(), nsCommonWrapper_TGuidComponent_jc, nsCommonWrapper_TGuidComponent_err);
    m.insert({ nsCommonWrapper_TGuidComponent_i, nsCommonWrapper_TGuidComponent_p_type });
    
    int nsCommonWrapper_TNameComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TNameComponent>();
    std::string nsCommonWrapper_TNameComponent_jc = "{"
"    \"mFileName\": \"NameComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\NameComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TNameComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TNameComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TNameComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TNameComponent_p_type.get(), nsCommonWrapper_TNameComponent_jc, nsCommonWrapper_TNameComponent_err);
    m.insert({ nsCommonWrapper_TNameComponent_i, nsCommonWrapper_TNameComponent_p_type });
    
    int nsCommonWrapper_TNeedDestroyObjectTagComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TNeedDestroyObjectTagComponent>();
    std::string nsCommonWrapper_TNeedDestroyObjectTagComponent_jc = "{"
"    \"mFileName\": \"NeedDestroyObjectTagComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\NeedDestroyObjectTagComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TNeedDestroyObjectTagComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TNeedDestroyObjectTagComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TNeedDestroyObjectTagComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TNeedDestroyObjectTagComponent_p_type.get(), nsCommonWrapper_TNeedDestroyObjectTagComponent_jc, nsCommonWrapper_TNeedDestroyObjectTagComponent_err);
    m.insert({ nsCommonWrapper_TNeedDestroyObjectTagComponent_i, nsCommonWrapper_TNeedDestroyObjectTagComponent_p_type });
    
    int nsCommonWrapper_TParentGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TParentGuidComponent>();
    std::string nsCommonWrapper_TParentGuidComponent_jc = "{"
"    \"mFileName\": \"ParentGuidComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\ParentGuidComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TParentGuidComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TParentGuidComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TParentGuidComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TParentGuidComponent_p_type.get(), nsCommonWrapper_TParentGuidComponent_jc, nsCommonWrapper_TParentGuidComponent_err);
    m.insert({ nsCommonWrapper_TParentGuidComponent_i, nsCommonWrapper_TParentGuidComponent_p_type });
    
    int nsCommonWrapper_TPrefabGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabGuidComponent>();
    std::string nsCommonWrapper_TPrefabGuidComponent_jc = "{"
"    \"mFileName\": \"PrefabGuidComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\PrefabGuidComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TPrefabGuidComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TPrefabGuidComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TPrefabGuidComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TPrefabGuidComponent_p_type.get(), nsCommonWrapper_TPrefabGuidComponent_jc, nsCommonWrapper_TPrefabGuidComponent_err);
    m.insert({ nsCommonWrapper_TPrefabGuidComponent_i, nsCommonWrapper_TPrefabGuidComponent_p_type });
    
    int nsCommonWrapper_TPrefabInstanceGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabInstanceGuidComponent>();
    std::string nsCommonWrapper_TPrefabInstanceGuidComponent_jc = "{"
"    \"mFileName\": \"PrefabInstanceGuidComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\PrefabInstanceGuidComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TPrefabInstanceGuidComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TPrefabInstanceGuidComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TPrefabInstanceGuidComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TPrefabInstanceGuidComponent_p_type.get(), nsCommonWrapper_TPrefabInstanceGuidComponent_jc, nsCommonWrapper_TPrefabInstanceGuidComponent_err);
    m.insert({ nsCommonWrapper_TPrefabInstanceGuidComponent_i, nsCommonWrapper_TPrefabInstanceGuidComponent_p_type });
    
    int nsCommonWrapper_TPrefabOriginalGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabOriginalGuidComponent>();
    std::string nsCommonWrapper_TPrefabOriginalGuidComponent_jc = "{"
"    \"mFileName\": \"PrefabOriginalGuidComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\PrefabOriginalGuidComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TPrefabOriginalGuidComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TPrefabOriginalGuidComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TPrefabOriginalGuidComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TPrefabOriginalGuidComponent_p_type.get(), nsCommonWrapper_TPrefabOriginalGuidComponent_jc, nsCommonWrapper_TPrefabOriginalGuidComponent_err);
    m.insert({ nsCommonWrapper_TPrefabOriginalGuidComponent_i, nsCommonWrapper_TPrefabOriginalGuidComponent_p_type });
    
    int nsCommonWrapper_TPrefabRootComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabRootComponent>();
    std::string nsCommonWrapper_TPrefabRootComponent_jc = "{"
"    \"mFileName\": \"PrefabRootComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\PrefabRootComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TPrefabRootComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TPrefabRootComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TPrefabRootComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TPrefabRootComponent_p_type.get(), nsCommonWrapper_TPrefabRootComponent_jc, nsCommonWrapper_TPrefabRootComponent_err);
    m.insert({ nsCommonWrapper_TPrefabRootComponent_i, nsCommonWrapper_TPrefabRootComponent_p_type });
    
    int nsCommonWrapper_TProjectionToUniverseComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TProjectionToUniverseComponent>();
    std::string nsCommonWrapper_TProjectionToUniverseComponent_jc = "{"
"    \"mFileName\": \"ProjectionToUniverseComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\ProjectionToUniverseComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TProjectionToUniverseComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TProjectionToUniverseComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TProjectionToUniverseComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TProjectionToUniverseComponent_p_type.get(), nsCommonWrapper_TProjectionToUniverseComponent_jc, nsCommonWrapper_TProjectionToUniverseComponent_err);
    m.insert({ nsCommonWrapper_TProjectionToUniverseComponent_i, nsCommonWrapper_TProjectionToUniverseComponent_p_type });
    
    int nsCommonWrapper_TSceneGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TSceneGuidComponent>();
    std::string nsCommonWrapper_TSceneGuidComponent_jc = "{"
"    \"mFileName\": \"SceneGuidComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\SceneGuidComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSceneGuidComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TSceneGuidComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TSceneGuidComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TSceneGuidComponent_p_type.get(), nsCommonWrapper_TSceneGuidComponent_jc, nsCommonWrapper_TSceneGuidComponent_err);
    m.insert({ nsCommonWrapper_TSceneGuidComponent_i, nsCommonWrapper_TSceneGuidComponent_p_type });
    
    int nsCommonWrapper_TSceneInstanceGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TSceneInstanceGuidComponent>();
    std::string nsCommonWrapper_TSceneInstanceGuidComponent_jc = "{"
"    \"mFileName\": \"SceneInstanceGuidComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\SceneInstanceGuidComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSceneInstanceGuidComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TSceneInstanceGuidComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TSceneInstanceGuidComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TSceneInstanceGuidComponent_p_type.get(), nsCommonWrapper_TSceneInstanceGuidComponent_jc, nsCommonWrapper_TSceneInstanceGuidComponent_err);
    m.insert({ nsCommonWrapper_TSceneInstanceGuidComponent_i, nsCommonWrapper_TSceneInstanceGuidComponent_p_type });
    
    int nsCommonWrapper_TSceneOriginalGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TSceneOriginalGuidComponent>();
    std::string nsCommonWrapper_TSceneOriginalGuidComponent_jc = "{"
"    \"mFileName\": \"SceneOriginalGuidComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\SceneOriginalGuidComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSceneOriginalGuidComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TSceneOriginalGuidComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TSceneOriginalGuidComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TSceneOriginalGuidComponent_p_type.get(), nsCommonWrapper_TSceneOriginalGuidComponent_jc, nsCommonWrapper_TSceneOriginalGuidComponent_err);
    m.insert({ nsCommonWrapper_TSceneOriginalGuidComponent_i, nsCommonWrapper_TSceneOriginalGuidComponent_p_type });
    
    int nsCommonWrapper_TSceneRootComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TSceneRootComponent>();
    std::string nsCommonWrapper_TSceneRootComponent_jc = "{"
"    \"mFileName\": \"SceneRootComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\SceneRootComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSceneRootComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TSceneRootComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TSceneRootComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TSceneRootComponent_p_type.get(), nsCommonWrapper_TSceneRootComponent_jc, nsCommonWrapper_TSceneRootComponent_err);
    m.insert({ nsCommonWrapper_TSceneRootComponent_i, nsCommonWrapper_TSceneRootComponent_p_type });
    
    int nsCommonWrapper_TUniverseGuidComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseGuidComponent>();
    std::string nsCommonWrapper_TUniverseGuidComponent_jc = "{"
"    \"mFileName\": \"UniverseGuidComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\UniverseGuidComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TUniverseGuidComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TUniverseGuidComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TUniverseGuidComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TUniverseGuidComponent_p_type.get(), nsCommonWrapper_TUniverseGuidComponent_jc, nsCommonWrapper_TUniverseGuidComponent_err);
    m.insert({ nsCommonWrapper_TUniverseGuidComponent_i, nsCommonWrapper_TUniverseGuidComponent_p_type });
    
    int nsCommonWrapper_TUniverseIndexComponent_i = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseIndexComponent>();
    std::string nsCommonWrapper_TUniverseIndexComponent_jc = "{"
"    \"mFileName\": \"UniverseIndexComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Meta\\\\UniverseIndexComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsCommonWrapper\","
"            \"mLongTypeName\": \"nsCommonWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TUniverseIndexComponent\","
"    \"mNamespaceVec\": ["
"        \"nsCommonWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsCommonWrapper_TUniverseIndexComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsCommonWrapper_TUniverseIndexComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsCommonWrapper_TUniverseIndexComponent_p_type.get(), nsCommonWrapper_TUniverseIndexComponent_jc, nsCommonWrapper_TUniverseIndexComponent_err);
    m.insert({ nsCommonWrapper_TUniverseIndexComponent_i, nsCommonWrapper_TUniverseIndexComponent_p_type });
    
    int nsGraphicWrapper_TCameraComponent_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraComponent>();
    std::string nsGraphicWrapper_TCameraComponent_jc = "{"
"    \"mFileName\": \"CameraComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Graphic\\\\CameraComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGraphicWrapper\","
"            \"mLongTypeName\": \"nsGraphicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TCameraComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGraphicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGraphicWrapper_TCameraComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGraphicWrapper_TCameraComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGraphicWrapper_TCameraComponent_p_type.get(), nsGraphicWrapper_TCameraComponent_jc, nsGraphicWrapper_TCameraComponent_err);
    m.insert({ nsGraphicWrapper_TCameraComponent_i, nsGraphicWrapper_TCameraComponent_p_type });
    
    int nsGraphicWrapper_TCameraTextureTagComponent_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraTextureTagComponent>();
    std::string nsGraphicWrapper_TCameraTextureTagComponent_jc = "{"
"    \"mFileName\": \"CameraTextureTagComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Graphic\\\\CameraTextureTagComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGraphicWrapper\","
"            \"mLongTypeName\": \"nsGraphicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TCameraTextureTagComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGraphicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGraphicWrapper_TCameraTextureTagComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGraphicWrapper_TCameraTextureTagComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGraphicWrapper_TCameraTextureTagComponent_p_type.get(), nsGraphicWrapper_TCameraTextureTagComponent_jc, nsGraphicWrapper_TCameraTextureTagComponent_err);
    m.insert({ nsGraphicWrapper_TCameraTextureTagComponent_i, nsGraphicWrapper_TCameraTextureTagComponent_p_type });
    
    int nsGraphicWrapper_TCameraWindowPositionComponent_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowPositionComponent>();
    std::string nsGraphicWrapper_TCameraWindowPositionComponent_jc = "{"
"    \"mFileName\": \"CameraWindowPositionComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Graphic\\\\CameraWindowPositionComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGraphicWrapper\","
"            \"mLongTypeName\": \"nsGraphicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TCameraWindowPositionComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGraphicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGraphicWrapper_TCameraWindowPositionComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGraphicWrapper_TCameraWindowPositionComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGraphicWrapper_TCameraWindowPositionComponent_p_type.get(), nsGraphicWrapper_TCameraWindowPositionComponent_jc, nsGraphicWrapper_TCameraWindowPositionComponent_err);
    m.insert({ nsGraphicWrapper_TCameraWindowPositionComponent_i, nsGraphicWrapper_TCameraWindowPositionComponent_p_type });
    
    int nsGraphicWrapper_TCameraWindowSizeComponent_i = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowSizeComponent>();
    std::string nsGraphicWrapper_TCameraWindowSizeComponent_jc = "{"
"    \"mFileName\": \"CameraWindowSizeComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Graphic\\\\CameraWindowSizeComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGraphicWrapper\","
"            \"mLongTypeName\": \"nsGraphicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TCameraWindowSizeComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGraphicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGraphicWrapper_TCameraWindowSizeComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGraphicWrapper_TCameraWindowSizeComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGraphicWrapper_TCameraWindowSizeComponent_p_type.get(), nsGraphicWrapper_TCameraWindowSizeComponent_jc, nsGraphicWrapper_TCameraWindowSizeComponent_err);
    m.insert({ nsGraphicWrapper_TCameraWindowSizeComponent_i, nsGraphicWrapper_TCameraWindowSizeComponent_p_type });
    
    int nsGraphicWrapper_TGuiCameraTagComponent_i = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiCameraTagComponent>();
    std::string nsGraphicWrapper_TGuiCameraTagComponent_jc = "{"
"    \"mFileName\": \"GuiCameraTagComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Graphic\\\\GuiCameraTagComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGraphicWrapper\","
"            \"mLongTypeName\": \"nsGraphicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TGuiCameraTagComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGraphicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGraphicWrapper_TGuiCameraTagComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGraphicWrapper_TGuiCameraTagComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGraphicWrapper_TGuiCameraTagComponent_p_type.get(), nsGraphicWrapper_TGuiCameraTagComponent_jc, nsGraphicWrapper_TGuiCameraTagComponent_err);
    m.insert({ nsGraphicWrapper_TGuiCameraTagComponent_i, nsGraphicWrapper_TGuiCameraTagComponent_p_type });
    
    int nsGraphicWrapper_TLightComponent_i = globalTypeIdentifier->Type<nsGraphicWrapper::TLightComponent>();
    std::string nsGraphicWrapper_TLightComponent_jc = "{"
"    \"mFileName\": \"LightComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Graphic\\\\LightComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGraphicWrapper\","
"            \"mLongTypeName\": \"nsGraphicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TLightComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGraphicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGraphicWrapper_TLightComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGraphicWrapper_TLightComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGraphicWrapper_TLightComponent_p_type.get(), nsGraphicWrapper_TLightComponent_jc, nsGraphicWrapper_TLightComponent_err);
    m.insert({ nsGraphicWrapper_TLightComponent_i, nsGraphicWrapper_TLightComponent_p_type });
    
    int nsGraphicWrapper_TRenderToTextureCameraComponent_i = globalTypeIdentifier->Type<nsGraphicWrapper::TRenderToTextureCameraComponent>();
    std::string nsGraphicWrapper_TRenderToTextureCameraComponent_jc = "{"
"    \"mFileName\": \"RenderToTextureCameraComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Graphic\\\\RenderToTextureCameraComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGraphicWrapper\","
"            \"mLongTypeName\": \"nsGraphicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TRenderToTextureCameraComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGraphicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGraphicWrapper_TRenderToTextureCameraComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGraphicWrapper_TRenderToTextureCameraComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGraphicWrapper_TRenderToTextureCameraComponent_p_type.get(), nsGraphicWrapper_TRenderToTextureCameraComponent_jc, nsGraphicWrapper_TRenderToTextureCameraComponent_err);
    m.insert({ nsGraphicWrapper_TRenderToTextureCameraComponent_i, nsGraphicWrapper_TRenderToTextureCameraComponent_p_type });
    
    int nsGraphicWrapper_TTextureFromCameraComponent_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromCameraComponent>();
    std::string nsGraphicWrapper_TTextureFromCameraComponent_jc = "{"
"    \"mFileName\": \"TextureFromCameraComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Graphic\\\\TextureFromCameraComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGraphicWrapper\","
"            \"mLongTypeName\": \"nsGraphicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TTextureFromCameraComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGraphicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGraphicWrapper_TTextureFromCameraComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGraphicWrapper_TTextureFromCameraComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGraphicWrapper_TTextureFromCameraComponent_p_type.get(), nsGraphicWrapper_TTextureFromCameraComponent_jc, nsGraphicWrapper_TTextureFromCameraComponent_err);
    m.insert({ nsGraphicWrapper_TTextureFromCameraComponent_i, nsGraphicWrapper_TTextureFromCameraComponent_p_type });
    
    int nsGraphicWrapper_TTextureFromFileComponent_i = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromFileComponent>();
    std::string nsGraphicWrapper_TTextureFromFileComponent_jc = "{"
"    \"mFileName\": \"TextureFromFileComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Graphic\\\\TextureFromFileComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsGraphicEngine::TRenderableObject>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGraphicWrapper\","
"            \"mLongTypeName\": \"nsGraphicWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsGraphicEngine::TRenderableObject\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGraphicWrapper\","
"            \"mLongTypeName\": \"nsGraphicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TTextureFromFileComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGraphicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGraphicWrapper_TTextureFromFileComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGraphicWrapper_TTextureFromFileComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGraphicWrapper_TTextureFromFileComponent_p_type.get(), nsGraphicWrapper_TTextureFromFileComponent_jc, nsGraphicWrapper_TTextureFromFileComponent_err);
    m.insert({ nsGraphicWrapper_TTextureFromFileComponent_i, nsGraphicWrapper_TTextureFromFileComponent_p_type });
    
    int nsGraphicWrapper_TUniverseCameraComponent_i = globalTypeIdentifier->Type<nsGraphicWrapper::TUniverseCameraComponent>();
    std::string nsGraphicWrapper_TUniverseCameraComponent_jc = "{"
"    \"mFileName\": \"UniverseCameraComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Graphic\\\\UniverseCameraComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGraphicWrapper\","
"            \"mLongTypeName\": \"nsGraphicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TUniverseCameraComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGraphicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGraphicWrapper_TUniverseCameraComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGraphicWrapper_TUniverseCameraComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGraphicWrapper_TUniverseCameraComponent_p_type.get(), nsGraphicWrapper_TUniverseCameraComponent_jc, nsGraphicWrapper_TUniverseCameraComponent_err);
    m.insert({ nsGraphicWrapper_TUniverseCameraComponent_i, nsGraphicWrapper_TUniverseCameraComponent_p_type });
    
    int nsGuiWrapper_TAnchorsComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TAnchorsComponent>();
    std::string nsGuiWrapper_TAnchorsComponent_jc = "{"
"    \"mFileName\": \"AnchorsComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\AnchorsComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TAnchors>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TAnchors\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TAnchorsComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TAnchorsComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TAnchorsComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TAnchorsComponent_p_type.get(), nsGuiWrapper_TAnchorsComponent_jc, nsGuiWrapper_TAnchorsComponent_err);
    m.insert({ nsGuiWrapper_TAnchorsComponent_i, nsGuiWrapper_TAnchorsComponent_p_type });
    
    int nsGuiWrapper_TButtonComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TButtonComponent>();
    std::string nsGuiWrapper_TButtonComponent_jc = "{"
"    \"mFileName\": \"ButtonComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Widgets\\\\ButtonComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TButtonComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TButtonComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TButtonComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TButtonComponent_p_type.get(), nsGuiWrapper_TButtonComponent_jc, nsGuiWrapper_TButtonComponent_err);
    m.insert({ nsGuiWrapper_TButtonComponent_i, nsGuiWrapper_TButtonComponent_p_type });
    
    int nsGuiWrapper_TColorComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TColorComponent>();
    std::string nsGuiWrapper_TColorComponent_jc = "{"
"    \"mFileName\": \"ColorComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\ColorComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TColor>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TColor\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TColorComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TColorComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TColorComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TColorComponent_p_type.get(), nsGuiWrapper_TColorComponent_jc, nsGuiWrapper_TColorComponent_err);
    m.insert({ nsGuiWrapper_TColorComponent_i, nsGuiWrapper_TColorComponent_p_type });
    
    int nsGuiWrapper_TDialogComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TDialogComponent>();
    std::string nsGuiWrapper_TDialogComponent_jc = "{"
"    \"mFileName\": \"DialogComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Widgets\\\\DialogComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TDialogComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TDialogComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TDialogComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TDialogComponent_p_type.get(), nsGuiWrapper_TDialogComponent_jc, nsGuiWrapper_TDialogComponent_err);
    m.insert({ nsGuiWrapper_TDialogComponent_i, nsGuiWrapper_TDialogComponent_p_type });
    
    int nsGuiWrapper_TFocusComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TFocusComponent>();
    std::string nsGuiWrapper_TFocusComponent_jc = "{"
"    \"mFileName\": \"FocusComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\FocusComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TFocus>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TFocus\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TFocusComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TFocusComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TFocusComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TFocusComponent_p_type.get(), nsGuiWrapper_TFocusComponent_jc, nsGuiWrapper_TFocusComponent_err);
    m.insert({ nsGuiWrapper_TFocusComponent_i, nsGuiWrapper_TFocusComponent_p_type });
    
    int nsGuiWrapper_TFrameComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TFrameComponent>();
    std::string nsGuiWrapper_TFrameComponent_jc = "{"
"    \"mFileName\": \"FrameComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Widgets\\\\FrameComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TFrameComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TFrameComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TFrameComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TFrameComponent_p_type.get(), nsGuiWrapper_TFrameComponent_jc, nsGuiWrapper_TFrameComponent_err);
    m.insert({ nsGuiWrapper_TFrameComponent_i, nsGuiWrapper_TFrameComponent_p_type });
    
    int nsGuiWrapper_TGridComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TGridComponent>();
    std::string nsGuiWrapper_TGridComponent_jc = "{"
"    \"mFileName\": \"GridComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\GridComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TGrid>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TGrid\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TGridComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TGridComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TGridComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TGridComponent_p_type.get(), nsGuiWrapper_TGridComponent_jc, nsGuiWrapper_TGridComponent_err);
    m.insert({ nsGuiWrapper_TGridComponent_i, nsGuiWrapper_TGridComponent_p_type });
    
    int nsGuiWrapper_THorizontalAlignComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::THorizontalAlignComponent>();
    std::string nsGuiWrapper_THorizontalAlignComponent_jc = "{"
"    \"mFileName\": \"HorizontalAlignComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\HorizontalAlignComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::THorizontalAlign>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::THorizontalAlign\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"THorizontalAlignComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_THorizontalAlignComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_THorizontalAlignComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_THorizontalAlignComponent_p_type.get(), nsGuiWrapper_THorizontalAlignComponent_jc, nsGuiWrapper_THorizontalAlignComponent_err);
    m.insert({ nsGuiWrapper_THorizontalAlignComponent_i, nsGuiWrapper_THorizontalAlignComponent_p_type });
    
    int nsGuiWrapper_TInputTextComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextComponent>();
    std::string nsGuiWrapper_TInputTextComponent_jc = "{"
"    \"mFileName\": \"InputTextComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Widgets\\\\InputTextComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TInputTextComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TInputTextComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TInputTextComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TInputTextComponent_p_type.get(), nsGuiWrapper_TInputTextComponent_jc, nsGuiWrapper_TInputTextComponent_err);
    m.insert({ nsGuiWrapper_TInputTextComponent_i, nsGuiWrapper_TInputTextComponent_p_type });
    
    int nsGuiWrapper_TInputTextValueComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextValueComponent>();
    std::string nsGuiWrapper_TInputTextValueComponent_jc = "{"
"    \"mFileName\": \"InputTextValueComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\InputTextValueComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TInputTextValue>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TInputTextValue\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TInputTextValueComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TInputTextValueComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TInputTextValueComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TInputTextValueComponent_p_type.get(), nsGuiWrapper_TInputTextValueComponent_jc, nsGuiWrapper_TInputTextValueComponent_err);
    m.insert({ nsGuiWrapper_TInputTextValueComponent_i, nsGuiWrapper_TInputTextValueComponent_p_type });
    
    int nsGuiWrapper_TLabelComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TLabelComponent>();
    std::string nsGuiWrapper_TLabelComponent_jc = "{"
"    \"mFileName\": \"LabelComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Widgets\\\\LabelComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TLabelComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TLabelComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TLabelComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TLabelComponent_p_type.get(), nsGuiWrapper_TLabelComponent_jc, nsGuiWrapper_TLabelComponent_err);
    m.insert({ nsGuiWrapper_TLabelComponent_i, nsGuiWrapper_TLabelComponent_p_type });
    
    int nsGuiWrapper_TLabelValueComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TLabelValueComponent>();
    std::string nsGuiWrapper_TLabelValueComponent_jc = "{"
"    \"mFileName\": \"LabelValueComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\LabelValueComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TLabel>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TLabel\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TLabelValueComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TLabelValueComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TLabelValueComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TLabelValueComponent_p_type.get(), nsGuiWrapper_TLabelValueComponent_jc, nsGuiWrapper_TLabelValueComponent_err);
    m.insert({ nsGuiWrapper_TLabelValueComponent_i, nsGuiWrapper_TLabelValueComponent_p_type });
    
    int nsGuiWrapper_TMainWindowComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TMainWindowComponent>();
    std::string nsGuiWrapper_TMainWindowComponent_jc = "{"
"    \"mFileName\": \"MainWindowComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Widgets\\\\MainWindowComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TMainWindowComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TMainWindowComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TMainWindowComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TMainWindowComponent_p_type.get(), nsGuiWrapper_TMainWindowComponent_jc, nsGuiWrapper_TMainWindowComponent_err);
    m.insert({ nsGuiWrapper_TMainWindowComponent_i, nsGuiWrapper_TMainWindowComponent_p_type });
    
    int nsGuiWrapper_TMaxSizeComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TMaxSizeComponent>();
    std::string nsGuiWrapper_TMaxSizeComponent_jc = "{"
"    \"mFileName\": \"MaxSizeComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\MaxSizeComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TMaxSize>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TMaxSize\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TMaxSizeComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TMaxSizeComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TMaxSizeComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TMaxSizeComponent_p_type.get(), nsGuiWrapper_TMaxSizeComponent_jc, nsGuiWrapper_TMaxSizeComponent_err);
    m.insert({ nsGuiWrapper_TMaxSizeComponent_i, nsGuiWrapper_TMaxSizeComponent_p_type });
    
    int nsGuiWrapper_TMenuNodeComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TMenuNodeComponent>();
    std::string nsGuiWrapper_TMenuNodeComponent_jc = "{"
"    \"mFileName\": \"MenuNodeComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Widgets\\\\MenuNodeComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TMenuNodeComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TMenuNodeComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TMenuNodeComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TMenuNodeComponent_p_type.get(), nsGuiWrapper_TMenuNodeComponent_jc, nsGuiWrapper_TMenuNodeComponent_err);
    m.insert({ nsGuiWrapper_TMenuNodeComponent_i, nsGuiWrapper_TMenuNodeComponent_p_type });
    
    int nsGuiWrapper_TMinDistanceToParentComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TMinDistanceToParentComponent>();
    std::string nsGuiWrapper_TMinDistanceToParentComponent_jc = "{"
"    \"mFileName\": \"MinDistanceToParentComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\MinDistanceToParentComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TMinDistanceToParent>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TMinDistanceToParent\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TMinDistanceToParentComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TMinDistanceToParentComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TMinDistanceToParentComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TMinDistanceToParentComponent_p_type.get(), nsGuiWrapper_TMinDistanceToParentComponent_jc, nsGuiWrapper_TMinDistanceToParentComponent_err);
    m.insert({ nsGuiWrapper_TMinDistanceToParentComponent_i, nsGuiWrapper_TMinDistanceToParentComponent_p_type });
    
    int nsGuiWrapper_TMinSizeComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TMinSizeComponent>();
    std::string nsGuiWrapper_TMinSizeComponent_jc = "{"
"    \"mFileName\": \"MinSizeComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\MinSizeComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TMinSize>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TMinSize\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TMinSizeComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TMinSizeComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TMinSizeComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TMinSizeComponent_p_type.get(), nsGuiWrapper_TMinSizeComponent_jc, nsGuiWrapper_TMinSizeComponent_err);
    m.insert({ nsGuiWrapper_TMinSizeComponent_i, nsGuiWrapper_TMinSizeComponent_p_type });
    
    int nsGuiWrapper_TNodeIconComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TNodeIconComponent>();
    std::string nsGuiWrapper_TNodeIconComponent_jc = "{"
"    \"mFileName\": \"NodeIconComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\NodeIconComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TTextureSize>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TTextureSize\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TNodeIconComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TNodeIconComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TNodeIconComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TNodeIconComponent_p_type.get(), nsGuiWrapper_TNodeIconComponent_jc, nsGuiWrapper_TNodeIconComponent_err);
    m.insert({ nsGuiWrapper_TNodeIconComponent_i, nsGuiWrapper_TNodeIconComponent_p_type });
    
    int nsGuiWrapper_TPaddingComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TPaddingComponent>();
    std::string nsGuiWrapper_TPaddingComponent_jc = "{"
"    \"mFileName\": \"PaddingComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\PaddingComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TPadding>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TPadding\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TPaddingComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TPaddingComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TPaddingComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TPaddingComponent_p_type.get(), nsGuiWrapper_TPaddingComponent_jc, nsGuiWrapper_TPaddingComponent_err);
    m.insert({ nsGuiWrapper_TPaddingComponent_i, nsGuiWrapper_TPaddingComponent_p_type });
    
    int nsGuiWrapper_TPositionComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TPositionComponent>();
    std::string nsGuiWrapper_TPositionComponent_jc = "{"
"    \"mFileName\": \"PositionComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\PositionComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TPosition>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TPosition\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TPositionComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TPositionComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TPositionComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TPositionComponent_p_type.get(), nsGuiWrapper_TPositionComponent_jc, nsGuiWrapper_TPositionComponent_err);
    m.insert({ nsGuiWrapper_TPositionComponent_i, nsGuiWrapper_TPositionComponent_p_type });
    
    int nsGuiWrapper_TPositionInGridComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TPositionInGridComponent>();
    std::string nsGuiWrapper_TPositionInGridComponent_jc = "{"
"    \"mFileName\": \"PositionInGridComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\PositionInGridComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TUnit>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TUnit\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TPositionInGridComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TPositionInGridComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TPositionInGridComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TPositionInGridComponent_p_type.get(), nsGuiWrapper_TPositionInGridComponent_jc, nsGuiWrapper_TPositionInGridComponent_err);
    m.insert({ nsGuiWrapper_TPositionInGridComponent_i, nsGuiWrapper_TPositionInGridComponent_p_type });
    
    int nsGuiWrapper_TSelectedTreeNodeGuidComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TSelectedTreeNodeGuidComponent>();
    std::string nsGuiWrapper_TSelectedTreeNodeGuidComponent_jc = "{"
"    \"mFileName\": \"SelectedTreeNodeGuidComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\SelectedTreeNodeGuidComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TTreeNode>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TTreeNode\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSelectedTreeNodeGuidComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TSelectedTreeNodeGuidComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TSelectedTreeNodeGuidComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TSelectedTreeNodeGuidComponent_p_type.get(), nsGuiWrapper_TSelectedTreeNodeGuidComponent_jc, nsGuiWrapper_TSelectedTreeNodeGuidComponent_err);
    m.insert({ nsGuiWrapper_TSelectedTreeNodeGuidComponent_i, nsGuiWrapper_TSelectedTreeNodeGuidComponent_p_type });
    
    int nsGuiWrapper_TSizeComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TSizeComponent>();
    std::string nsGuiWrapper_TSizeComponent_jc = "{"
"    \"mFileName\": \"SizeComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\SizeComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TSize>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TSize\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSizeComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TSizeComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TSizeComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TSizeComponent_p_type.get(), nsGuiWrapper_TSizeComponent_jc, nsGuiWrapper_TSizeComponent_err);
    m.insert({ nsGuiWrapper_TSizeComponent_i, nsGuiWrapper_TSizeComponent_p_type });
    
    int nsGuiWrapper_TSizeInGridComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TSizeInGridComponent>();
    std::string nsGuiWrapper_TSizeInGridComponent_jc = "{"
"    \"mFileName\": \"SizeInGridComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\SizeInGridComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TUnit>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TUnit\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSizeInGridComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TSizeInGridComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TSizeInGridComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TSizeInGridComponent_p_type.get(), nsGuiWrapper_TSizeInGridComponent_jc, nsGuiWrapper_TSizeInGridComponent_err);
    m.insert({ nsGuiWrapper_TSizeInGridComponent_i, nsGuiWrapper_TSizeInGridComponent_p_type });
    
    int nsGuiWrapper_TSpacingComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TSpacingComponent>();
    std::string nsGuiWrapper_TSpacingComponent_jc = "{"
"    \"mFileName\": \"SpacingComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\SpacingComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TSpacing>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TSpacing\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSpacingComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TSpacingComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TSpacingComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TSpacingComponent_p_type.get(), nsGuiWrapper_TSpacingComponent_jc, nsGuiWrapper_TSpacingComponent_err);
    m.insert({ nsGuiWrapper_TSpacingComponent_i, nsGuiWrapper_TSpacingComponent_p_type });
    
    int nsGuiWrapper_TTitleComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TTitleComponent>();
    std::string nsGuiWrapper_TTitleComponent_jc = "{"
"    \"mFileName\": \"TitleComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\TitleComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TTitle>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TTitle\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TTitleComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TTitleComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TTitleComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TTitleComponent_p_type.get(), nsGuiWrapper_TTitleComponent_jc, nsGuiWrapper_TTitleComponent_err);
    m.insert({ nsGuiWrapper_TTitleComponent_i, nsGuiWrapper_TTitleComponent_p_type });
    
    int nsGuiWrapper_TTreeNodeComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TTreeNodeComponent>();
    std::string nsGuiWrapper_TTreeNodeComponent_jc = "{"
"    \"mFileName\": \"TreeNodeComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Widgets\\\\TreeNodeComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TTreeNodeComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TTreeNodeComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TTreeNodeComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TTreeNodeComponent_p_type.get(), nsGuiWrapper_TTreeNodeComponent_jc, nsGuiWrapper_TTreeNodeComponent_err);
    m.insert({ nsGuiWrapper_TTreeNodeComponent_i, nsGuiWrapper_TTreeNodeComponent_p_type });
    
    int nsGuiWrapper_TTreeViewComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TTreeViewComponent>();
    std::string nsGuiWrapper_TTreeViewComponent_jc = "{"
"    \"mFileName\": \"TreeViewComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Widgets\\\\TreeViewComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TTreeViewComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TTreeViewComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TTreeViewComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TTreeViewComponent_p_type.get(), nsGuiWrapper_TTreeViewComponent_jc, nsGuiWrapper_TTreeViewComponent_err);
    m.insert({ nsGuiWrapper_TTreeViewComponent_i, nsGuiWrapper_TTreeViewComponent_p_type });
    
    int nsGuiWrapper_TVerticalAlignComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TVerticalAlignComponent>();
    std::string nsGuiWrapper_TVerticalAlignComponent_jc = "{"
"    \"mFileName\": \"VerticalAlignComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\VerticalAlignComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TVerticalAlign>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TVerticalAlign\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TVerticalAlignComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TVerticalAlignComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TVerticalAlignComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TVerticalAlignComponent_p_type.get(), nsGuiWrapper_TVerticalAlignComponent_jc, nsGuiWrapper_TVerticalAlignComponent_err);
    m.insert({ nsGuiWrapper_TVerticalAlignComponent_i, nsGuiWrapper_TVerticalAlignComponent_p_type });
    
    int nsGuiWrapper_TVisibilityComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TVisibilityComponent>();
    std::string nsGuiWrapper_TVisibilityComponent_jc = "{"
"    \"mFileName\": \"VisibilityComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Properties\\\\VisibilityComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsTornadoEngine::TPropertyOf<nsImGuiWidgets::TVisibility>\","
"            \"mOriginalTypeName\": \"nsTornadoEngine::TPropertyOf\","
"            \"mOriginalNameSpace\": \"nsTornadoEngine\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsTornadoEngine::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"nsImGuiWidgets::TVisibility\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TVisibilityComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TVisibilityComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TVisibilityComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TVisibilityComponent_p_type.get(), nsGuiWrapper_TVisibilityComponent_jc, nsGuiWrapper_TVisibilityComponent_err);
    m.insert({ nsGuiWrapper_TVisibilityComponent_i, nsGuiWrapper_TVisibilityComponent_p_type });
    
    int nsGuiWrapper_TWindowComponent_i = globalTypeIdentifier->Type<nsGuiWrapper::TWindowComponent>();
    std::string nsGuiWrapper_TWindowComponent_jc = "{"
"    \"mFileName\": \"WindowComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Gui\\\\Widgets\\\\WindowComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsGuiWrapper\","
"            \"mLongTypeName\": \"nsGuiWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TWindowComponent\","
"    \"mNamespaceVec\": ["
"        \"nsGuiWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsGuiWrapper_TWindowComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsGuiWrapper_TWindowComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsGuiWrapper_TWindowComponent_p_type.get(), nsGuiWrapper_TWindowComponent_jc, nsGuiWrapper_TWindowComponent_err);
    m.insert({ nsGuiWrapper_TWindowComponent_i, nsGuiWrapper_TWindowComponent_p_type });
    
    int nsLogicWrapper_TGlobalHandlerComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TGlobalHandlerComponent>();
    std::string nsLogicWrapper_TGlobalHandlerComponent_jc = "{"
"    \"mFileName\": \"GlobalHandlerComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Handler\\\\GlobalHandlerComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsLogicWrapper\","
"            \"mLongTypeName\": \"nsLogicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TGlobalHandlerComponent\","
"    \"mNamespaceVec\": ["
"        \"nsLogicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsLogicWrapper_TGlobalHandlerComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsLogicWrapper_TGlobalHandlerComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsLogicWrapper_TGlobalHandlerComponent_p_type.get(), nsLogicWrapper_TGlobalHandlerComponent_jc, nsLogicWrapper_TGlobalHandlerComponent_err);
    m.insert({ nsLogicWrapper_TGlobalHandlerComponent_i, nsLogicWrapper_TGlobalHandlerComponent_p_type });
    
    int nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent>();
    std::string nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_jc = "{"
"    \"mFileName\": \"ObjectInstantiationCompletionHandlerComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Logic\\\\ObjectInstantiationCompletionHandlerComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsLogicWrapper\","
"            \"mLongTypeName\": \"nsLogicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TObjectInstantiationCompletionHandlerComponent\","
"    \"mNamespaceVec\": ["
"        \"nsLogicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_p_type.get(), nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_jc, nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_err);
    m.insert({ nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_i, nsLogicWrapper_TObjectInstantiationCompletionHandlerComponent_p_type });
    
    int nsLogicWrapper_TPrefabObjectReferenceComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabObjectReferenceComponent>();
    std::string nsLogicWrapper_TPrefabObjectReferenceComponent_jc = "{"
"    \"mFileName\": \"PrefabObjectReferenceComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Logic\\\\PrefabObjectReferenceComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsLogicWrapper\","
"            \"mLongTypeName\": \"nsLogicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TPrefabObjectReferenceComponent\","
"    \"mNamespaceVec\": ["
"        \"nsLogicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsLogicWrapper_TPrefabObjectReferenceComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsLogicWrapper_TPrefabObjectReferenceComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsLogicWrapper_TPrefabObjectReferenceComponent_p_type.get(), nsLogicWrapper_TPrefabObjectReferenceComponent_jc, nsLogicWrapper_TPrefabObjectReferenceComponent_err);
    m.insert({ nsLogicWrapper_TPrefabObjectReferenceComponent_i, nsLogicWrapper_TPrefabObjectReferenceComponent_p_type });
    
    int nsLogicWrapper_TPrefabReferenceComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabReferenceComponent>();
    std::string nsLogicWrapper_TPrefabReferenceComponent_jc = "{"
"    \"mFileName\": \"PrefabReferenceComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Logic\\\\PrefabReferenceComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsLogicWrapper\","
"            \"mLongTypeName\": \"nsLogicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TPrefabReferenceComponent\","
"    \"mNamespaceVec\": ["
"        \"nsLogicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsLogicWrapper_TPrefabReferenceComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsLogicWrapper_TPrefabReferenceComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsLogicWrapper_TPrefabReferenceComponent_p_type.get(), nsLogicWrapper_TPrefabReferenceComponent_jc, nsLogicWrapper_TPrefabReferenceComponent_err);
    m.insert({ nsLogicWrapper_TPrefabReferenceComponent_i, nsLogicWrapper_TPrefabReferenceComponent_p_type });
    
    int nsLogicWrapper_TSceneInstantiationCompletionHandlerComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TSceneInstantiationCompletionHandlerComponent>();
    std::string nsLogicWrapper_TSceneInstantiationCompletionHandlerComponent_jc = "{"
"    \"mFileName\": \"SceneInstantiationCompletionHandlerComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Logic\\\\SceneInstantiationCompletionHandlerComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsLogicWrapper\","
"            \"mLongTypeName\": \"nsLogicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSceneInstantiationCompletionHandlerComponent\","
"    \"mNamespaceVec\": ["
"        \"nsLogicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsLogicWrapper_TSceneInstantiationCompletionHandlerComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsLogicWrapper_TSceneInstantiationCompletionHandlerComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsLogicWrapper_TSceneInstantiationCompletionHandlerComponent_p_type.get(), nsLogicWrapper_TSceneInstantiationCompletionHandlerComponent_jc, nsLogicWrapper_TSceneInstantiationCompletionHandlerComponent_err);
    m.insert({ nsLogicWrapper_TSceneInstantiationCompletionHandlerComponent_i, nsLogicWrapper_TSceneInstantiationCompletionHandlerComponent_p_type });
    
    int nsLogicWrapper_TSceneObjectReferenceComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TSceneObjectReferenceComponent>();
    std::string nsLogicWrapper_TSceneObjectReferenceComponent_jc = "{"
"    \"mFileName\": \"SceneObjectReferenceComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Logic\\\\SceneObjectReferenceComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsLogicWrapper\","
"            \"mLongTypeName\": \"nsLogicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSceneObjectReferenceComponent\","
"    \"mNamespaceVec\": ["
"        \"nsLogicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsLogicWrapper_TSceneObjectReferenceComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsLogicWrapper_TSceneObjectReferenceComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsLogicWrapper_TSceneObjectReferenceComponent_p_type.get(), nsLogicWrapper_TSceneObjectReferenceComponent_jc, nsLogicWrapper_TSceneObjectReferenceComponent_err);
    m.insert({ nsLogicWrapper_TSceneObjectReferenceComponent_i, nsLogicWrapper_TSceneObjectReferenceComponent_p_type });
    
    int nsLogicWrapper_TSceneReferenceComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TSceneReferenceComponent>();
    std::string nsLogicWrapper_TSceneReferenceComponent_jc = "{"
"    \"mFileName\": \"SceneReferenceComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Logic\\\\SceneReferenceComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsLogicWrapper\","
"            \"mLongTypeName\": \"nsLogicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSceneReferenceComponent\","
"    \"mNamespaceVec\": ["
"        \"nsLogicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsLogicWrapper_TSceneReferenceComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsLogicWrapper_TSceneReferenceComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsLogicWrapper_TSceneReferenceComponent_p_type.get(), nsLogicWrapper_TSceneReferenceComponent_jc, nsLogicWrapper_TSceneReferenceComponent_err);
    m.insert({ nsLogicWrapper_TSceneReferenceComponent_i, nsLogicWrapper_TSceneReferenceComponent_p_type });
    
    int nsLogicWrapper_TSystemComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TSystemComponent>();
    std::string nsLogicWrapper_TSystemComponent_jc = "{"
"    \"mFileName\": \"SystemComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Logic\\\\SystemComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsLogicWrapper\","
"            \"mLongTypeName\": \"nsLogicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSystemComponent\","
"    \"mNamespaceVec\": ["
"        \"nsLogicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsLogicWrapper_TSystemComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsLogicWrapper_TSystemComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsLogicWrapper_TSystemComponent_p_type.get(), nsLogicWrapper_TSystemComponent_jc, nsLogicWrapper_TSystemComponent_err);
    m.insert({ nsLogicWrapper_TSystemComponent_i, nsLogicWrapper_TSystemComponent_p_type });
    
    int nsLogicWrapper_TTargetHandlerComponent_i = globalTypeIdentifier->Type<nsLogicWrapper::TTargetHandlerComponent>();
    std::string nsLogicWrapper_TTargetHandlerComponent_jc = "{"
"    \"mFileName\": \"TargetHandlerComponent.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Source\\\\Core\\\\TornadoEngine\\\\Components\\\\Handler\\\\TargetHandlerComponent.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsLogicWrapper\","
"            \"mLongTypeName\": \"nsLogicWrapper::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TTargetHandlerComponent\","
"    \"mNamespaceVec\": ["
"        \"nsLogicWrapper\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsLogicWrapper_TTargetHandlerComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsLogicWrapper_TTargetHandlerComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsLogicWrapper_TTargetHandlerComponent_p_type.get(), nsLogicWrapper_TTargetHandlerComponent_jc, nsLogicWrapper_TTargetHandlerComponent_err);
    m.insert({ nsLogicWrapper_TTargetHandlerComponent_i, nsLogicWrapper_TTargetHandlerComponent_p_type });
    
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
const nsCppParser::TTypeInfo* TComponentRtti::Get(int rtti)
{
    Init();
    return mTypeInoVector[rtti].get();
}
//---------------------------------------------------------------------------------------
