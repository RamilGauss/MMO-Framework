/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "JsonSerializerFileGenerator.h"
#include <functional>

namespace nsCodeGeneratorImplementation
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


        nsCppParser::TTypeInfo* mCurrentTypeInfo = nullptr;

    public:
        virtual void Work() override;

    private:
        void AddInit();

        void AddConstContentMethods();

        void AddImplementations();

        void AddSerializeMethodImplementation(nsCppParser::TTypeInfo* p);
        void AddDeserializeMethodImplementation(nsCppParser::TTypeInfo* p);

        void AddSerializeEnumMethodImplementation(nsCppParser::TTypeInfo* p);
        void AddDeserializeEnumMethodImplementation(nsCppParser::TTypeInfo* p);

        void AddCallingSerializeParent(nsCppParser::TInheritanceInfo* pInheritanceInfo);
        void AddCallingDeserializeParent(nsCppParser::TInheritanceInfo* pInheritanceInfo);

        void AddPushByMemberInfo(nsCppParser::TMemberInfo* memberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr = nullptr, int depth = 0);

        void AddPush(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);
        void AddPushZeroDepth(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr);
        void AddPushDepth(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        void AddPushReflection(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);
        void AddPushReflectionZeroDepth(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr);
        void AddPushReflectionDepth(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        void AddPushReflectionDepthSetListVector(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);
        void AddPushReflectionDepthMap(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        void AddBeginPushListOrSet(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);
        void AddEndPushListOrSet(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        void AddBeginPushVector(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);
        void AddEndPushVector(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        void AddBeginPushMap(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);
        void AddEndPushMap(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        //=======================================================================
        void AddPopByMemberInfo(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr = nullptr, int depth = 0);

        void AddPop(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);
        void AddPopZeroDepth(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr);
        void AddPopDepth(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        void AddPopReflection(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        void AddPopReflectionZeroDepth(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr);
        void AddPopReflectionDepth(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        void AddPopReflectionDepthSetListVector(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);
        void AddPopReflectionDepthMap(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        void AddBeginPopListSetVector(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);
        void AddBeginPopMap(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        void AddEndPop(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        void AddPopLastElementListSetVector(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);

        void AddEndPopMap(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);
        void AddEndPopListSetVector(nsCppParser::TMemberInfo* pMemberInfo,
            std::vector<nsCppParser::TMemberExtendedTypeInfo>* pExtArr, int depth);
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
