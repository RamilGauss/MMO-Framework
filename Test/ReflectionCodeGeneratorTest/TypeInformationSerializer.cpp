/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_10_30 17:47:51.208
	
#include "TypeInformationSerializer.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"
#include "Parser/Sources/Generated files/JsonSerializer.h"

using namespace nsTypeInformation;

std::vector<std::shared_ptr<nsCppParser::TTypeInfo>> TTypeInformationSerializer::mTypeInoVector;

void TTypeInformationSerializer::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, std::shared_ptr<nsCppParser::TTypeInfo>> m;
    int ExecuteSystem_i = globalTypeIdentifier->Type<ExecuteSystem>();
    std::string ExecuteSystem_jc = "{"
"    \"mFileName\": \"Systems.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\Systems.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::TExecuteSystem\","
"            \"mOriginalTypeName\": \"nsECSFramework::TExecuteSystem\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"TExecuteSystem\","
"            \"mNameSpace\": \"\","
"            \"mLongTypeName\": \"nsECSFramework::TExecuteSystem\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"ExecuteSystem\","
"    \"mNamespaceVec\": [],"
"    \"mTemplateArgs\": []"
"}";
    std::string ExecuteSystem_err;
    std::shared_ptr<nsCppParser::TTypeInfo> ExecuteSystem_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(ExecuteSystem_p_type.get(), ExecuteSystem_jc, ExecuteSystem_err);
    m.insert({ ExecuteSystem_i, ExecuteSystem_p_type });
    
    int Feature_i = globalTypeIdentifier->Type<Feature>();
    std::string Feature_jc = "{"
"    \"mFileName\": \"Systems.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\Systems.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::TFeature\","
"            \"mOriginalTypeName\": \"nsECSFramework::TFeature\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"TFeature\","
"            \"mNameSpace\": \"\","
"            \"mLongTypeName\": \"nsECSFramework::TFeature\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"Feature\","
"    \"mNamespaceVec\": [],"
"    \"mTemplateArgs\": []"
"}";
    std::string Feature_err;
    std::shared_ptr<nsCppParser::TTypeInfo> Feature_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(Feature_p_type.get(), Feature_jc, Feature_err);
    m.insert({ Feature_i, Feature_p_type });
    
    int InitSystem_i = globalTypeIdentifier->Type<InitSystem>();
    std::string InitSystem_jc = "{"
"    \"mFileName\": \"Systems.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\Systems.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::TInitSystem\","
"            \"mOriginalTypeName\": \"nsECSFramework::TInitSystem\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"TInitSystem\","
"            \"mNameSpace\": \"\","
"            \"mLongTypeName\": \"nsECSFramework::TInitSystem\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"InitSystem\","
"    \"mNamespaceVec\": [],"
"    \"mTemplateArgs\": []"
"}";
    std::string InitSystem_err;
    std::shared_ptr<nsCppParser::TTypeInfo> InitSystem_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(InitSystem_p_type.get(), InitSystem_jc, InitSystem_err);
    m.insert({ InitSystem_i, InitSystem_p_type });
    
    int OnAddCollect_i = globalTypeIdentifier->Type<OnAddCollect>();
    std::string OnAddCollect_jc = "{"
"    \"mFileName\": \"Systems.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\Systems.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::TOnAddCollectReactiveSystem<,OnAddCollect>\","
"            \"mOriginalTypeName\": \"nsECSFramework::TOnAddCollectReactiveSystem\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"TOnAddCollectReactiveSystem\","
"            \"mNameSpace\": \"\","
"            \"mLongTypeName\": \"nsECSFramework::TOnAddCollectReactiveSystem\","
"            \"originalTemplates\": ["
"                \"\","
"                \"OnAddCollect\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"OnAddCollect\","
"    \"mNamespaceVec\": [],"
"    \"mTemplateArgs\": []"
"}";
    std::string OnAddCollect_err;
    std::shared_ptr<nsCppParser::TTypeInfo> OnAddCollect_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(OnAddCollect_p_type.get(), OnAddCollect_jc, OnAddCollect_err);
    m.insert({ OnAddCollect_i, OnAddCollect_p_type });
    
    int OnAddInstant_i = globalTypeIdentifier->Type<OnAddInstant>();
    std::string OnAddInstant_jc = "{"
"    \"mFileName\": \"Systems.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\Systems.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::TOnAddInstantReactiveSystem<,OnAddInstant>\","
"            \"mOriginalTypeName\": \"nsECSFramework::TOnAddInstantReactiveSystem\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"TOnAddInstantReactiveSystem\","
"            \"mNameSpace\": \"\","
"            \"mLongTypeName\": \"nsECSFramework::TOnAddInstantReactiveSystem\","
"            \"originalTemplates\": ["
"                \"\","
"                \"OnAddInstant\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"OnAddInstant\","
"    \"mNamespaceVec\": [],"
"    \"mTemplateArgs\": []"
"}";
    std::string OnAddInstant_err;
    std::shared_ptr<nsCppParser::TTypeInfo> OnAddInstant_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(OnAddInstant_p_type.get(), OnAddInstant_jc, OnAddInstant_err);
    m.insert({ OnAddInstant_i, OnAddInstant_p_type });
    
    int OnRemoveInstant_i = globalTypeIdentifier->Type<OnRemoveInstant>();
    std::string OnRemoveInstant_jc = "{"
"    \"mFileName\": \"Systems.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\Systems.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::TOnRemoveInstantReactiveSystem<,OnRemoveInstant>\","
"            \"mOriginalTypeName\": \"nsECSFramework::TOnRemoveInstantReactiveSystem\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"TOnRemoveInstantReactiveSystem\","
"            \"mNameSpace\": \"\","
"            \"mLongTypeName\": \"nsECSFramework::TOnRemoveInstantReactiveSystem\","
"            \"originalTemplates\": ["
"                \"\","
"                \"OnRemoveInstant\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"OnRemoveInstant\","
"    \"mNamespaceVec\": [],"
"    \"mTemplateArgs\": []"
"}";
    std::string OnRemoveInstant_err;
    std::shared_ptr<nsCppParser::TTypeInfo> OnRemoveInstant_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(OnRemoveInstant_p_type.get(), OnRemoveInstant_jc, OnRemoveInstant_err);
    m.insert({ OnRemoveInstant_i, OnRemoveInstant_p_type });
    
    int OnUpdateCollect_i = globalTypeIdentifier->Type<OnUpdateCollect>();
    std::string OnUpdateCollect_jc = "{"
"    \"mFileName\": \"Systems.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\Systems.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::TOnUpdateCollectReactiveSystem<,OnUpdateCollect>\","
"            \"mOriginalTypeName\": \"nsECSFramework::TOnUpdateCollectReactiveSystem\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"TOnUpdateCollectReactiveSystem\","
"            \"mNameSpace\": \"\","
"            \"mLongTypeName\": \"nsECSFramework::TOnUpdateCollectReactiveSystem\","
"            \"originalTemplates\": ["
"                \"\","
"                \"OnUpdateCollect\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"OnUpdateCollect\","
"    \"mNamespaceVec\": [],"
"    \"mTemplateArgs\": []"
"}";
    std::string OnUpdateCollect_err;
    std::shared_ptr<nsCppParser::TTypeInfo> OnUpdateCollect_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(OnUpdateCollect_p_type.get(), OnUpdateCollect_jc, OnUpdateCollect_err);
    m.insert({ OnUpdateCollect_i, OnUpdateCollect_p_type });
    
    int OnUpdateInstant_i = globalTypeIdentifier->Type<OnUpdateInstant>();
    std::string OnUpdateInstant_jc = "{"
"    \"mFileName\": \"Systems.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\Systems.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::TOnUpdateInstantReactiveSystem<,OnUpdateInstant>\","
"            \"mOriginalTypeName\": \"nsECSFramework::TOnUpdateInstantReactiveSystem\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"TOnUpdateInstantReactiveSystem\","
"            \"mNameSpace\": \"\","
"            \"mLongTypeName\": \"nsECSFramework::TOnUpdateInstantReactiveSystem\","
"            \"originalTemplates\": ["
"                \"\","
"                \"OnUpdateInstant\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"OnUpdateInstant\","
"    \"mNamespaceVec\": [],"
"    \"mTemplateArgs\": []"
"}";
    std::string OnUpdateInstant_err;
    std::shared_ptr<nsCppParser::TTypeInfo> OnUpdateInstant_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(OnUpdateInstant_p_type.get(), OnUpdateInstant_jc, OnUpdateInstant_err);
    m.insert({ OnUpdateInstant_i, OnUpdateInstant_p_type });
    
    int System_i = globalTypeIdentifier->Type<System>();
    std::string System_jc = "{"
"    \"mFileName\": \"Systems.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\Systems.h\","
"    \"mPragmaTextSet\": ["
"        \"once\""
"    ],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::TSystem\","
"            \"mOriginalTypeName\": \"nsECSFramework::TSystem\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"TSystem\","
"            \"mNameSpace\": \"\","
"            \"mLongTypeName\": \"nsECSFramework::TSystem\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"System\","
"    \"mNamespaceVec\": [],"
"    \"mTemplateArgs\": []"
"}";
    std::string System_err;
    std::shared_ptr<nsCppParser::TTypeInfo> System_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(System_p_type.get(), System_jc, System_err);
    m.insert({ System_i, System_p_type });
    
    int TUnit_i = globalTypeIdentifier->Type<TUnit>();
    std::string TUnit_jc = "{"
"    \"mFileName\": \"SimpleComponents.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\SimpleComponents.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": [],"
"    \"mName\": \"TUnit\","
"    \"mNamespaceVec\": [],"
"    \"mTemplateArgs\": []"
"}";
    std::string TUnit_err;
    std::shared_ptr<nsCppParser::TTypeInfo> TUnit_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(TUnit_p_type.get(), TUnit_jc, TUnit_err);
    m.insert({ TUnit_i, TUnit_p_type });
    
    int TearDownSystem_i = globalTypeIdentifier->Type<TearDownSystem>();
    std::string TearDownSystem_jc = "{"
"    \"mFileName\": \"Systems.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\Systems.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::TTearDownSystem\","
"            \"mOriginalTypeName\": \"nsECSFramework::TTearDownSystem\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"TTearDownSystem\","
"            \"mNameSpace\": \"\","
"            \"mLongTypeName\": \"nsECSFramework::TTearDownSystem\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TearDownSystem\","
"    \"mNamespaceVec\": [],"
"    \"mTemplateArgs\": []"
"}";
    std::string TearDownSystem_err;
    std::shared_ptr<nsCppParser::TTypeInfo> TearDownSystem_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(TearDownSystem_p_type.get(), TearDownSystem_jc, TearDownSystem_err);
    m.insert({ TearDownSystem_i, TearDownSystem_p_type });
    
    int nsAllTypes_A_i = globalTypeIdentifier->Type<nsAllTypes::A>();
    std::string nsAllTypes_A_jc = "{"
"    \"mFileName\": \"AllTypes.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\AllTypes.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": [],"
"    \"mName\": \"A\","
"    \"mNamespaceVec\": ["
"        \"nsAllTypes\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsAllTypes_A_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsAllTypes_A_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsAllTypes_A_p_type.get(), nsAllTypes_A_jc, nsAllTypes_A_err);
    m.insert({ nsAllTypes_A_i, nsAllTypes_A_p_type });
    
    int nsAllTypes_B_i = globalTypeIdentifier->Type<nsAllTypes::B>();
    std::string nsAllTypes_B_jc = "{"
"    \"mFileName\": \"AllTypes.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\AllTypes.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": [],"
"    \"mName\": \"B\","
"    \"mNamespaceVec\": ["
"        \"nsAllTypes\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsAllTypes_B_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsAllTypes_B_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsAllTypes_B_p_type.get(), nsAllTypes_B_jc, nsAllTypes_B_err);
    m.insert({ nsAllTypes_B_i, nsAllTypes_B_p_type });
    
    int nsAllTypes_C_i = globalTypeIdentifier->Type<nsAllTypes::C>();
    std::string nsAllTypes_C_jc = "{"
"    \"mFileName\": \"AllTypes.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\AllTypes.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": [],"
"    \"mName\": \"C\","
"    \"mNamespaceVec\": ["
"        \"nsAllTypes\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsAllTypes_C_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsAllTypes_C_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsAllTypes_C_p_type.get(), nsAllTypes_C_jc, nsAllTypes_C_err);
    m.insert({ nsAllTypes_C_i, nsAllTypes_C_p_type });
    
    int nsSimpleComponents_TNameComponent_i = globalTypeIdentifier->Type<nsSimpleComponents::TNameComponent>();
    std::string nsSimpleComponents_TNameComponent_jc = "{"
"    \"mFileName\": \"SimpleComponents.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\SimpleComponents.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"CLASS\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsSimpleComponents\","
"            \"mLongTypeName\": \"nsSimpleComponents::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TNameComponent\","
"    \"mNamespaceVec\": ["
"        \"nsSimpleComponents\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsSimpleComponents_TNameComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsSimpleComponents_TNameComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsSimpleComponents_TNameComponent_p_type.get(), nsSimpleComponents_TNameComponent_jc, nsSimpleComponents_TNameComponent_err);
    m.insert({ nsSimpleComponents_TNameComponent_i, nsSimpleComponents_TNameComponent_p_type });
    
    int nsSimpleComponents_TSimpleComponent_i = globalTypeIdentifier->Type<nsSimpleComponents::TSimpleComponent>();
    std::string nsSimpleComponents_TSimpleComponent_jc = "{"
"    \"mFileName\": \"SimpleComponents.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\SimpleComponents.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsSimpleComponents\","
"            \"mLongTypeName\": \"nsSimpleComponents::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSimpleComponent\","
"    \"mNamespaceVec\": ["
"        \"nsSimpleComponents\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsSimpleComponents_TSimpleComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsSimpleComponents_TSimpleComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsSimpleComponents_TSimpleComponent_p_type.get(), nsSimpleComponents_TSimpleComponent_jc, nsSimpleComponents_TSimpleComponent_err);
    m.insert({ nsSimpleComponents_TSimpleComponent_i, nsSimpleComponents_TSimpleComponent_p_type });
    
    int nsSimpleComponents_TSizeComponent_i = globalTypeIdentifier->Type<nsSimpleComponents::TSizeComponent>();
    std::string nsSimpleComponents_TSizeComponent_jc = "{"
"    \"mFileName\": \"SimpleComponents.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\SimpleComponents.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"TPropertyOf<TUnit>\","
"            \"mOriginalTypeName\": \"TPropertyOf\","
"            \"mOriginalNameSpace\": \"\","
"            \"mShortTypeName\": \"TPropertyOf\","
"            \"mNameSpace\": \"nsSimpleComponents\","
"            \"mLongTypeName\": \"nsSimpleComponents::TPropertyOf\","
"            \"originalTemplates\": ["
"                \"TUnit\""
"            ],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        },"
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsSimpleComponents\","
"            \"mLongTypeName\": \"nsSimpleComponents::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TSizeComponent\","
"    \"mNamespaceVec\": ["
"        \"nsSimpleComponents\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsSimpleComponents_TSizeComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsSimpleComponents_TSizeComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsSimpleComponents_TSizeComponent_p_type.get(), nsSimpleComponents_TSizeComponent_jc, nsSimpleComponents_TSizeComponent_err);
    m.insert({ nsSimpleComponents_TSizeComponent_i, nsSimpleComponents_TSizeComponent_p_type });
    
    int nsSimpleComponents_TValueComponent_i = globalTypeIdentifier->Type<nsSimpleComponents::TValueComponent>();
    std::string nsSimpleComponents_TValueComponent_jc = "{"
"    \"mFileName\": \"SimpleComponents.h\","
"    \"mAbsFileName\": \"C:\\\\MMOFramework\\\\Test\\\\ReflectionCodeGeneratorTest\\\\DataSources\\\\SimpleComponents.h\","
"    \"mPragmaTextSet\": [],"
"    \"mType\": \"STRUCT\","
"    \"mEnumKeys\": [],"
"    \"mInheritanceVec\": ["
"        {"
"            \"mOriginalName\": \"nsECSFramework::IComponent\","
"            \"mOriginalTypeName\": \"nsECSFramework::IComponent\","
"            \"mOriginalNameSpace\": \"nsECSFramework\","
"            \"mShortTypeName\": \"IComponent\","
"            \"mNameSpace\": \"nsSimpleComponents\","
"            \"mLongTypeName\": \"nsSimpleComponents::nsECSFramework::IComponent\","
"            \"originalTemplates\": [],"
"            \"mInheritanceAccessLevel\": \"PUBLIC\""
"        }"
"    ],"
"    \"mName\": \"TValueComponent\","
"    \"mNamespaceVec\": ["
"        \"nsSimpleComponents\""
"    ],"
"    \"mTemplateArgs\": []"
"}";
    std::string nsSimpleComponents_TValueComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo> nsSimpleComponents_TValueComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsSimpleComponents_TValueComponent_p_type.get(), nsSimpleComponents_TValueComponent_jc, nsSimpleComponents_TValueComponent_err);
    m.insert({ nsSimpleComponents_TValueComponent_i, nsSimpleComponents_TValueComponent_p_type });
    
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
const nsCppParser::TTypeInfo* TTypeInformationSerializer::Get(int rtti)
{
    Init();
    return mTypeInoVector[rtti].get();
}
//---------------------------------------------------------------------------------------
