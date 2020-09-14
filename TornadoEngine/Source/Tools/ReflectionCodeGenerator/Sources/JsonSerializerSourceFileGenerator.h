/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "JsonSerializerFileGenerator.h"
#include <functional>

namespace nsReflectionCodeGenerator
{
    class TJsonSerializerSourceFileGenerator : public TJsonSerializerFileGenerator
    {
        const std::string s_POM = "POM";
        const std::string s_PUM = "PUM";

        const std::string s_ConvertToString = "ConvertToString";

        const std::string s_Obj = "obj";
        const std::string s_Json = "json";

        const std::string s_PushNull = "PushNull";
        const std::string s_Push = "Push";
        const std::string s_PushMap = "PushMap";

        const std::string s_PushSerObjArray = "PushSerObjArray";
        const std::string s_PushSerPtrArray = "PushSerPtrArray";
        const std::string s_PushSerSmartPtrArray = "PushSerSmartPtrArray";

        const std::string s_PushSerObjMap = "PushSerObjMap";
        const std::string s_PushSerPtrMap = "PushSerPtrMap";
        const std::string s_PushSerSmartPtrMap = "PushSerSmartPtrMap";

        const std::string s_PopStr = "PopStr";
        const std::string s_PopBool = "PopBool";
        const std::string s_PopNum = "PopNum";

        const std::string s_PopStrArray = "PopStrArray";
        const std::string s_PopBoolArray = "PopBoolArray";
        const std::string s_PopNumArray = "PopNumArray";

        const std::string s_PopStrSet = "PopStrSet";
        const std::string s_PopBoolSet = "PopBoolSet";
        const std::string s_PopNumSet = "PopNumSet";

        const std::string s_PopStrNumMap = "PopStrNumMap";
        const std::string s_PopStrStrMap = "PopStrStrMap";
        const std::string s_PopStrBoolMap = "PopStrBoolMap";
        const std::string s_PopNumNumMap = "PopNumNumMap";
        const std::string s_PopNumStrMap = "PopNumStrMap";
        const std::string s_PopNumBoolMap = "PopNumBoolMap";

        const std::string s_PopSerObjArray = "PopSerObjArray";
        const std::string s_PopSerPtrArray = "PopSerPtrArray";
        const std::string s_PopSerSmartPtrArray = "PopSerSmartPtrArray";
        const std::string s_PopStrSerObjMap = "PopStrSerObjMap";
        const std::string s_PopStrSerPtrMap = "PopStrSerPtrMap";
        const std::string s_PopStrSerSmartPtrMap = "PopStrSerSmartPtrMap";
        const std::string s_PopNumSerObjMap = "PopNumSerObjMap";
        const std::string s_PopNumSerPtrMap = "PopNumSerPtrMap";
        const std::string s_PopNumSerSmartPtrMap = "PopNumSerSmartPtrMap";

        const std::string s_Object_items = "object_items";
        const std::string s_Array_items = "array_items";

        const std::string s_String_value = "string_value";
        const std::string s_Number_value = "number_value";
        const std::string s_Bool_value = "bool_value";

        const std::string s_IsNull = "is_null";

        const std::string s_StrToNum = "std::stod";

        const std::string s_Init = "Init";
        const std::string s_GetTypeNameList = "GetTypeNameList";
        const std::string s_SerializeByTypeMethod = "Serialize";
        const std::string s_DeserializeByTypeMethod = "Deserialize";
        const std::string s_FillByTypeMethod = "Fill";

        const std::string s_TypeNameFuncsMap = "mTypeNameFuncsMap";
        const std::string s_TypeNameList = "mTypeNameList";

    public:
        virtual void Work() override;

    private:
        void AddInit();

        void AddConstContentMethods();

        void AddImplementations();

        void AddSerializeMethodImplementation(TTypeInfo* p);
        void AddDeserializeMethodImplementation(TTypeInfo* p);

        void AddCallingSerializeParent(const std::string& parentTypeName);
        void AddCallingDeserializeParent(const std::string& parentTypeName);

        void AddPushByMemberInfo(TMemberInfo* memberInfo);
        void AddPopByMemberInfo(TMemberInfo* memberInfo);

        void AddPush(const std::string& objectName);

        void AddPushSerObjArray(const std::string& type, const std::string& name);
        void AddPushSerPtrArray(const std::string& type, const std::string& name);
        void AddPushSerSmartPtrArray(const std::string& type, const std::string& smartPtrType, const std::string& name);

        void AddPushMap(const std::string& name);

        void AddPushSerObjMap(const std::string& type, const std::string& name);
        void AddPushSerPtrMap(const std::string& type, const std::string& name);
        void AddPushSerSmartPtrMap(const std::string& type, const std::string& smartPtrType, const std::string& name);

        void AddPopStr(const std::string& name);

        void AddPopBool(const std::string& name);
        void AddPopNum(const std::string& name);

        void AddPopBoolArray(const std::string& name);
        void AddPopNumArray(const std::string& name, const std::string& type);
        void AddPopStrArray(const std::string& name);

        void AddPopBoolSet(const std::string& name);
        void AddPopNumSet(const std::string& name, const std::string& type);
        void AddPopStrSet(const std::string& name);

        void AddPopNumBoolMap(const std::string& name);
        void AddPopNumNumMap(const std::string& name);
        void AddPopNumStrMap(const std::string& name);
        void AddPopStrBoolMap(const std::string& name);
        void AddPopStrNumMap(const std::string& name);
        void AddPopStrStrMap(const std::string& name);

        void AddPopMap(const std::string& methodName, const std::string& name);
    private:
        void HandlePushReflectionArray(TMemberInfo* pMemberInfo);
        void HandleReflectionForPush(TMemberInfo* pMemberInfo);
        void HandleSmartPtrOrPtrReflectionForPush(TMemberInfo* pMemberInfo);

        void HandlePushBuiltInOrStringSerMap(TMemberInfo* pMemberInfo);

        void HandlePopBuiltIn(TMemberInfo* memberInfo);

        void HandlePopSet(TMemberInfo* pMemberInfo);
        void HandlePopReflection(TMemberInfo* pMemberInfo);
        void HandleSmartPtrOrPtrPopReflection(TMemberInfo* pMemberInfo);

        void HandlePopReflectionArray(TMemberInfo* pMemberInfo);
        void HandlePopReflectionSet(TMemberInfo* pMemberInfo);

        void HandlePopBuiltInOrStringMap(TMemberInfo* pMemberInfo);
        void HandlePopBuiltInOrStringSerMap(TMemberInfo* pMemberInfo);

        void HandleComplexPushZeroDepth(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name);
        void HandleComplexPush(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth);
        void General_HandleComplexPush(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth, const std::string& srcArray);

        void HandlePopSimpleZeroDepth(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name);
        void HandlePushSimple(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth);
        void HandlePushReflection(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth);

        void AddPushByElementName(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth, std::string elementNameFirstOrSecond);


        void HandleComplexPopZeroDepth(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name);
        void HandleComplexPop(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth);
        void General_HandleComplexPop(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth);

        void HandlePopSimple(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth);
        void HandlePopReflection(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth);

        std::string GetPopStrForComplex(std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth);
        std::string ItemAccessByCategory(const TMemberTypeExtendedInfo& ext);
        std::string GetConversionBuiltIn(const TMemberTypeExtendedInfo& ext);

        std::string CollectorName(const std::string& name, int depth);
        std::string ElementName(const std::string& name, int depth);
        std::string IndexName(const std::string& name, int depth);
        std::string SourceName(const std::string& name, int depth);

    private:

        void General_AddPushSerArrayOrMap(const std::string& type, const std::string& fullType, const std::string& name, const std::string& methodName);
        void General_AddPop(const std::string& name, const std::string& methodName);
        void General_AddPopArrayOrSet(const std::string& name, const std::string& type, const std::string& methodName);

        void General_AddPopSerArrayOrMap(const std::string& keyType, const std::string& valueType,
            const std::string& typeForLambda,
            const std::string& fullType, const std::string& name, const std::string& methodName);
    };
}
