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

        const std::string s_Value = "Value";
        const std::string s_Obj = "obj";

        const std::string s_kArrayType = "rapidjson::kArrayType";
        const std::string s_kObjectType = "rapidjson::kObjectType";

        const std::string s_AddObject = "AddObject";

        const std::string s_PushNull = "PushNull";
        const std::string s_PushToArrayNull = "PushBackNull";
        const std::string s_Push = "Push";
        const std::string s_PushToArray = "PushBack";

        const std::string s_PopStr = "PopStr";
        const std::string s_PopBool = "PopBool";
        const std::string s_PopNum = "PopNum";

        const std::string s_FindObject = "FindObject";
        const std::string s_FindArray = "FindArray";

        const std::string s_GetObject = "GetObject";
        const std::string s_GetArray = "GetArray";

        const std::string s_GetString = "GetString";
        const std::string s_GetDouble = "GetDouble";
        const std::string s_GetInt64 = "GetInt64";
        const std::string s_GetBool = "GetBool";

        const std::string s_IsExist = "IsExist";
        const std::string s_IsNull = "IsNull";

        const std::string s_IsArray = "IsArray";

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

        void AddPushByMemberInfo(TMemberInfo* memberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr = nullptr, int depth = 0);

        void AddPush(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);
        void AddPushZeroDepth(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr);
        void AddPushDepth(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        void AddPushReflection(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);
        void AddPushReflectionZeroDepth(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr);
        void AddPushReflectionDepth(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        void AddPushReflectionDepthSetListVector(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);
        void AddPushReflectionDepthMap(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        void AddBeginPushListOrSet(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);
        void AddEndPushListOrSet(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        void AddBeginPushVector(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);
        void AddEndPushVector(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        void AddBeginPushMap(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);
        void AddEndPushMap(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        //=======================================================================
        void AddPopByMemberInfo(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr = nullptr, int depth = 0);

        void AddPop(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);
        void AddPopZeroDepth(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr);
        void AddPopDepth(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        void AddPopReflection(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        void AddPopReflectionZeroDepth(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr);
        void AddPopReflectionDepth(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        void AddPopReflectionDepthSetListVector(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);
        void AddPopReflectionDepthMap(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        void AddBeginPopListSetVector(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);
        void AddBeginPopMap(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        void AddEndPop(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        void AddPopLastElementListSetVector(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);

        void AddEndPopMap(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);
        void AddEndPopListSetVector(TMemberInfo* pMemberInfo,
            std::vector<TMemberTypeExtendedInfo>* pExtArr, int depth);
    private:

        std::string CollectorName(const std::string& name, int depth);
        std::string ElementName(const std::string& name, int depth);
        std::string IndexName(const std::string& name, int depth);
        std::string SourceName(const std::string& name, int depth);
        std::string ArrayName(const std::string& name, int depth);
        std::string ObjectName(const std::string& name, int depth);
        std::string TempName(const std::string& name, int depth);
    };
}
