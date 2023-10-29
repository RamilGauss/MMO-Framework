/*
	ReflectionCodeGeneratorTest
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2023_10_29 17:35:39.248
	
#include "TypeInformationSerializer.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

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
    
    std::map<std::string, std::string> m;
    std::string ExecuteSystem_jc = "{
    "mFileName": "Systems.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\Systems.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::TExecuteSystem",
            "mOriginalTypeName": "nsECSFramework::TExecuteSystem",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "TExecuteSystem",
            "mNameSpace": "",
            "mLongTypeName": "nsECSFramework::TExecuteSystem",
            "originalTemplates": [],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "ExecuteSystem",
    "mNamespaceVec": [],
    "mTemplateArgs": []
}";
    std::string ExecuteSystem_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> ExecuteSystem_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(ExecuteSystem_p_type, ExecuteSystem_jc, ExecuteSystem_err);
    
    std::string Feature_jc = "{
    "mFileName": "Systems.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\Systems.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::TFeature",
            "mOriginalTypeName": "nsECSFramework::TFeature",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "TFeature",
            "mNameSpace": "",
            "mLongTypeName": "nsECSFramework::TFeature",
            "originalTemplates": [],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "Feature",
    "mNamespaceVec": [],
    "mTemplateArgs": []
}";
    std::string Feature_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> Feature_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(Feature_p_type, Feature_jc, Feature_err);
    
    std::string InitSystem_jc = "{
    "mFileName": "Systems.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\Systems.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::TInitSystem",
            "mOriginalTypeName": "nsECSFramework::TInitSystem",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "TInitSystem",
            "mNameSpace": "",
            "mLongTypeName": "nsECSFramework::TInitSystem",
            "originalTemplates": [],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "InitSystem",
    "mNamespaceVec": [],
    "mTemplateArgs": []
}";
    std::string InitSystem_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> InitSystem_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(InitSystem_p_type, InitSystem_jc, InitSystem_err);
    
    std::string OnAddCollect_jc = "{
    "mFileName": "Systems.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\Systems.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::TOnAddCollectReactiveSystem<,OnAddCollect>",
            "mOriginalTypeName": "nsECSFramework::TOnAddCollectReactiveSystem",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "TOnAddCollectReactiveSystem",
            "mNameSpace": "",
            "mLongTypeName": "nsECSFramework::TOnAddCollectReactiveSystem",
            "originalTemplates": [
                "",
                "OnAddCollect"
            ],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "OnAddCollect",
    "mNamespaceVec": [],
    "mTemplateArgs": []
}";
    std::string OnAddCollect_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> OnAddCollect_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(OnAddCollect_p_type, OnAddCollect_jc, OnAddCollect_err);
    
    std::string OnAddInstant_jc = "{
    "mFileName": "Systems.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\Systems.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::TOnAddInstantReactiveSystem<,OnAddInstant>",
            "mOriginalTypeName": "nsECSFramework::TOnAddInstantReactiveSystem",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "TOnAddInstantReactiveSystem",
            "mNameSpace": "",
            "mLongTypeName": "nsECSFramework::TOnAddInstantReactiveSystem",
            "originalTemplates": [
                "",
                "OnAddInstant"
            ],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "OnAddInstant",
    "mNamespaceVec": [],
    "mTemplateArgs": []
}";
    std::string OnAddInstant_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> OnAddInstant_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(OnAddInstant_p_type, OnAddInstant_jc, OnAddInstant_err);
    
    std::string OnRemoveInstant_jc = "{
    "mFileName": "Systems.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\Systems.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::TOnRemoveInstantReactiveSystem<,OnRemoveInstant>",
            "mOriginalTypeName": "nsECSFramework::TOnRemoveInstantReactiveSystem",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "TOnRemoveInstantReactiveSystem",
            "mNameSpace": "",
            "mLongTypeName": "nsECSFramework::TOnRemoveInstantReactiveSystem",
            "originalTemplates": [
                "",
                "OnRemoveInstant"
            ],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "OnRemoveInstant",
    "mNamespaceVec": [],
    "mTemplateArgs": []
}";
    std::string OnRemoveInstant_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> OnRemoveInstant_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(OnRemoveInstant_p_type, OnRemoveInstant_jc, OnRemoveInstant_err);
    
    std::string OnUpdateCollect_jc = "{
    "mFileName": "Systems.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\Systems.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::TOnUpdateCollectReactiveSystem<,OnUpdateCollect>",
            "mOriginalTypeName": "nsECSFramework::TOnUpdateCollectReactiveSystem",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "TOnUpdateCollectReactiveSystem",
            "mNameSpace": "",
            "mLongTypeName": "nsECSFramework::TOnUpdateCollectReactiveSystem",
            "originalTemplates": [
                "",
                "OnUpdateCollect"
            ],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "OnUpdateCollect",
    "mNamespaceVec": [],
    "mTemplateArgs": []
}";
    std::string OnUpdateCollect_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> OnUpdateCollect_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(OnUpdateCollect_p_type, OnUpdateCollect_jc, OnUpdateCollect_err);
    
    std::string OnUpdateInstant_jc = "{
    "mFileName": "Systems.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\Systems.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::TOnUpdateInstantReactiveSystem<,OnUpdateInstant>",
            "mOriginalTypeName": "nsECSFramework::TOnUpdateInstantReactiveSystem",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "TOnUpdateInstantReactiveSystem",
            "mNameSpace": "",
            "mLongTypeName": "nsECSFramework::TOnUpdateInstantReactiveSystem",
            "originalTemplates": [
                "",
                "OnUpdateInstant"
            ],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "OnUpdateInstant",
    "mNamespaceVec": [],
    "mTemplateArgs": []
}";
    std::string OnUpdateInstant_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> OnUpdateInstant_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(OnUpdateInstant_p_type, OnUpdateInstant_jc, OnUpdateInstant_err);
    
    std::string System_jc = "{
    "mFileName": "Systems.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\Systems.h",
    "mPragmaTextSet": [
        "once"
    ],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::TSystem",
            "mOriginalTypeName": "nsECSFramework::TSystem",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "TSystem",
            "mNameSpace": "",
            "mLongTypeName": "nsECSFramework::TSystem",
            "originalTemplates": [],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "System",
    "mNamespaceVec": [],
    "mTemplateArgs": []
}";
    std::string System_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> System_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(System_p_type, System_jc, System_err);
    
    std::string TUnit_jc = "{
    "mFileName": "SimpleComponents.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\SimpleComponents.h",
    "mPragmaTextSet": [],
    "mType": "CLASS",
    "mEnumKeys": [],
    "mInheritanceVec": [],
    "mName": "TUnit",
    "mNamespaceVec": [],
    "mTemplateArgs": []
}";
    std::string TUnit_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> TUnit_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(TUnit_p_type, TUnit_jc, TUnit_err);
    
    std::string TearDownSystem_jc = "{
    "mFileName": "Systems.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\Systems.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::TTearDownSystem",
            "mOriginalTypeName": "nsECSFramework::TTearDownSystem",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "TTearDownSystem",
            "mNameSpace": "",
            "mLongTypeName": "nsECSFramework::TTearDownSystem",
            "originalTemplates": [],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "TearDownSystem",
    "mNamespaceVec": [],
    "mTemplateArgs": []
}";
    std::string TearDownSystem_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> TearDownSystem_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(TearDownSystem_p_type, TearDownSystem_jc, TearDownSystem_err);
    
    std::string nsAllTypes_A_jc = "{
    "mFileName": "AllTypes.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\AllTypes.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [],
    "mName": "A",
    "mNamespaceVec": [
        "nsAllTypes"
    ],
    "mTemplateArgs": []
}";
    std::string nsAllTypes_A_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> nsAllTypes_A_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsAllTypes_A_p_type, nsAllTypes_A_jc, nsAllTypes_A_err);
    
    std::string nsAllTypes_B_jc = "{
    "mFileName": "AllTypes.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\AllTypes.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [],
    "mName": "B",
    "mNamespaceVec": [
        "nsAllTypes"
    ],
    "mTemplateArgs": []
}";
    std::string nsAllTypes_B_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> nsAllTypes_B_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsAllTypes_B_p_type, nsAllTypes_B_jc, nsAllTypes_B_err);
    
    std::string nsAllTypes_C_jc = "{
    "mFileName": "AllTypes.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\AllTypes.h",
    "mPragmaTextSet": [],
    "mType": "CLASS",
    "mEnumKeys": [],
    "mInheritanceVec": [],
    "mName": "C",
    "mNamespaceVec": [
        "nsAllTypes"
    ],
    "mTemplateArgs": []
}";
    std::string nsAllTypes_C_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> nsAllTypes_C_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsAllTypes_C_p_type, nsAllTypes_C_jc, nsAllTypes_C_err);
    
    std::string nsSimpleComponents_TNameComponent_jc = "{
    "mFileName": "SimpleComponents.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\SimpleComponents.h",
    "mPragmaTextSet": [],
    "mType": "CLASS",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::IComponent",
            "mOriginalTypeName": "nsECSFramework::IComponent",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "IComponent",
            "mNameSpace": "nsSimpleComponents",
            "mLongTypeName": "nsSimpleComponents::nsECSFramework::IComponent",
            "originalTemplates": [],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "TNameComponent",
    "mNamespaceVec": [
        "nsSimpleComponents"
    ],
    "mTemplateArgs": []
}";
    std::string nsSimpleComponents_TNameComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> nsSimpleComponents_TNameComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsSimpleComponents_TNameComponent_p_type, nsSimpleComponents_TNameComponent_jc, nsSimpleComponents_TNameComponent_err);
    
    std::string nsSimpleComponents_TSimpleComponent_jc = "{
    "mFileName": "SimpleComponents.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\SimpleComponents.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::IComponent",
            "mOriginalTypeName": "nsECSFramework::IComponent",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "IComponent",
            "mNameSpace": "nsSimpleComponents",
            "mLongTypeName": "nsSimpleComponents::nsECSFramework::IComponent",
            "originalTemplates": [],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "TSimpleComponent",
    "mNamespaceVec": [
        "nsSimpleComponents"
    ],
    "mTemplateArgs": []
}";
    std::string nsSimpleComponents_TSimpleComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> nsSimpleComponents_TSimpleComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsSimpleComponents_TSimpleComponent_p_type, nsSimpleComponents_TSimpleComponent_jc, nsSimpleComponents_TSimpleComponent_err);
    
    std::string nsSimpleComponents_TSizeComponent_jc = "{
    "mFileName": "SimpleComponents.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\SimpleComponents.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "TPropertyOf<TUnit>",
            "mOriginalTypeName": "TPropertyOf",
            "mOriginalNameSpace": "",
            "mShortTypeName": "TPropertyOf",
            "mNameSpace": "nsSimpleComponents",
            "mLongTypeName": "nsSimpleComponents::TPropertyOf",
            "originalTemplates": [
                "TUnit"
            ],
            "mInheritanceAccessLevel": "PUBLIC"
        },
        {
            "mOriginalName": "nsECSFramework::IComponent",
            "mOriginalTypeName": "nsECSFramework::IComponent",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "IComponent",
            "mNameSpace": "nsSimpleComponents",
            "mLongTypeName": "nsSimpleComponents::nsECSFramework::IComponent",
            "originalTemplates": [],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "TSizeComponent",
    "mNamespaceVec": [
        "nsSimpleComponents"
    ],
    "mTemplateArgs": []
}";
    std::string nsSimpleComponents_TSizeComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> nsSimpleComponents_TSizeComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsSimpleComponents_TSizeComponent_p_type, nsSimpleComponents_TSizeComponent_jc, nsSimpleComponents_TSizeComponent_err);
    
    std::string nsSimpleComponents_TValueComponent_jc = "{
    "mFileName": "SimpleComponents.h",
    "mAbsFileName": "C:\\MMOFramework\\Test\\ReflectionCodeGeneratorTest\\DataSources\\SimpleComponents.h",
    "mPragmaTextSet": [],
    "mType": "STRUCT",
    "mEnumKeys": [],
    "mInheritanceVec": [
        {
            "mOriginalName": "nsECSFramework::IComponent",
            "mOriginalTypeName": "nsECSFramework::IComponent",
            "mOriginalNameSpace": "nsECSFramework",
            "mShortTypeName": "IComponent",
            "mNameSpace": "nsSimpleComponents",
            "mLongTypeName": "nsSimpleComponents::nsECSFramework::IComponent",
            "originalTemplates": [],
            "mInheritanceAccessLevel": "PUBLIC"
        }
    ],
    "mName": "TValueComponent",
    "mNamespaceVec": [
        "nsSimpleComponents"
    ],
    "mTemplateArgs": []
}";
    std::string nsSimpleComponents_TValueComponent_err;
    std::shared_ptr<nsCppParser::TTypeInfo*> nsSimpleComponents_TValueComponent_p_type = std::make_shared<nsCppParser::TTypeInfo>();
    nsCppParser::TJsonSerializer::Deserialize(nsSimpleComponents_TValueComponent_p_type, nsSimpleComponents_TValueComponent_jc, nsSimpleComponents_TValueComponent_err);
    
    int max = 0;
}
}
//---------------------------------------------------------------------------------------
const nsCppParser::TTypeInfo* TTypeInformationSerializer::Get(int rtti)
{
Init();
return mTypeInoVector[rtti].get();
}
//---------------------------------------------------------------------------------------
