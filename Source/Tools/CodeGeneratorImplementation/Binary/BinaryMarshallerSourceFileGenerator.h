/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "BinaryMarshallerFileGenerator.h"

#include <format>

namespace nsCodeGeneratorImplementation
{
    class TBinaryMarshallerSourceFileGenerator : public TBinaryMarshallerFileGenerator
    {
        const std::string s_BinaryMaster = "TBinaryMaster";
        const std::string s_SizeType = "SizeType";
        const std::string s_BinaryMaster_SizeType = std::format("{}{}{}", s_BinaryMaster, s_CC, s_SizeType);

        const std::list<std::string> GetBinaryImplementation();

        nsCppParser::TTypeInfo* mCurrentTypeInfo = nullptr;
    public:
        virtual void Work() override;

    private:
        void AddPackImplentation();
        void AddImplementations();

        void AddCase(nsCppParser::TTypeInfo* p);

        void AddImplementation(nsCppParser::TTypeInfo* p);

        void AddSerializeImplementation(nsCppParser::TTypeInfo* p);
        void AddDeserializeImplementation(nsCppParser::TTypeInfo* p);
        void AddGetTypeIDImplementation(nsCppParser::TTypeInfo* p);
        void AddDeallocateImplentation(nsCppParser::TTypeInfo* p);

        void AddCallingSerializeParent(nsCppParser::TInheritanceInfo* pInheritanceInfo);
        void AddCallingDeserializeParent(nsCppParser::TInheritanceInfo* pInheritanceInfo);


        void AddPushByMemberInfo(nsCppParser::TMemberInfo* pMemberInfo);
        void AddPopByMemberInfo(nsCppParser::TMemberInfo* pMemberInfo);
        void AddDeallocateByMemberInfo(nsCppParser::TMemberInfo* pMemberInfo);

        // Push XXX
        void AddPushStr(const std::string& name);
        void AddPushBool(const std::string& name);
        void AddPushNum(const std::string& name);

        void AddPushBoolArray(const std::string& name);
        void AddPushNumArray(const std::string& type, const std::string& name);
        void AddPushStrArray(const std::string& name);

        void AddPushSerObjArray(const std::string& type, const std::string& name);
        void AddPushSerPtrArray(const std::string& type, const std::string& name);
        void AddPushSerSmartPtrArray(const std::string& type, const std::string& smartPtrType, const std::string& name);

        void AddPushSerObjMap(const std::string& keyType, const std::string& valueType, const std::string& name);
        void AddPushSerPtrMap(const std::string& keyType, const std::string& valueType, const std::string& name);
        void AddPushSerSmartPtrMap(const std::string& keyType, const std::string& valueType,
            const std::string& smartPtrType, const std::string& name);

        void AddPushSerObj(const std::string& type, const std::string& name);
        void AddPushSerPtr(const std::string& type, const std::string& name);
        void AddPushSerSmartPtr(const std::string& type, const std::string& name);


        void AddPopStr(const std::string& name);
        void AddPopBool(const std::string& name);
        void AddPopNum(const std::string& name);

        void AddPopNumSet(const std::string& type, const std::string& name);
        void AddPopStrSet(const std::string& name);

        void AddPopStrArray(const std::string& name);
        void AddPopBoolArray(const std::string& name);
        void AddPopNumArray(const std::string& type, const std::string& name);

        void AddPopSerObj(const std::string& name);
        void AddPopSerPtr(const std::string& type, const std::string& name);
        void AddPopSerSmartPtr(const std::string& type, const std::string& name);

        void AddPopSerObjArray(const std::string& type, const std::string& name);
        void AddPopSerPtrArray(const std::string& type, const std::string& name);
        void AddPopSerSmartPtrArray(const std::string& type, const std::string& smartPtrType, const std::string& name);

        void AddPopSerObjMap(const std::string& keyType, const std::string& valueType, const std::string& name);
        void AddPopSerPtrMap(const std::string& keyType, const std::string& valueType, const std::string& name);
        void AddPopSerSmartPtrMap(const std::string& keyType, const std::string& valueType, const std::string& smartPointer, const std::string& name);

        // Handlers
        void HandlePushBuiltIn(nsCppParser::TMemberInfo* pMemberInfo);
        void HandlePushArray(nsCppParser::TMemberInfo* pMemberInfo);
        void HandlePushMap(nsCppParser::TMemberInfo* pMemberInfo);
        void HandleReflectionForPush(nsCppParser::TMemberInfo* pMemberInfo);

        void HandleAddPushBuiltInArray(nsCppParser::TMemberInfo* pMemberInfo);
        void HandlePushSerArray(nsCppParser::TMemberInfo* pMemberInfo);
        void HandleAddPushValueAsReflectionMap(nsCppParser::TMemberInfo* pMemberInfo);
        void HandleAddPushNotReflectionMap(nsCppParser::TMemberInfo* pMemberInfo);

        void HandlePopBuiltIn(nsCppParser::TMemberInfo* pMemberInfo);
        void HandlePopArray(nsCppParser::TMemberInfo* pMemberInfo);
        void HandlePopSet(nsCppParser::TMemberInfo* pMemberInfo);
        void HandlePopMap(nsCppParser::TMemberInfo* pMemberInfo);
        void HandlePopReflection(nsCppParser::TMemberInfo* pMemberInfo);

        void HandlePopBuiltInArray(nsCppParser::TMemberInfo* pMemberInfo);
        void HandlePopReflectionArray(nsCppParser::TMemberInfo* pMemberInfo);

        void HandleAddPopValueAsReflectionMap(nsCppParser::TMemberInfo* pMemberInfo);
        void HandleAddPopNotReflectionMap(nsCppParser::TMemberInfo* pMemberInfo);

        void HandleComplexPushZeroDepth(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name);
        void HandleComplexPush(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);
        void General_ComplexPush(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);

        void AddPushKey(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);
        void AddPushValue(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);

        void AddPushElement(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);

        void AddPushSerializeValue(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);
        void AddPushSerializeElement(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);
        std::string GetTemplateForGetAddress(nsCppParser::AccessMethod accessMethod);

        std::string GetIsElementNotNull(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);


        void HandleBuiltInComplexPush(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);
        void HandleStringComplexPush(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);
        void HandleReflectionComplexPush(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);

        void AddCleanerArrayOrMap(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name);
        void HandleDeallocateReflection(nsCppParser::TMemberInfo* pMemberInfo);

        void HandleComplexPopZeroDepth(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name);
        void HandleComplexPop(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);
        void General_ComplexPop(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);
        void HandleBuiltInComplexPop(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);
        void HandleReflectionComplexPop(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);


        std::string ElementName(const std::string& name, int depth);
        std::string SizeName(const std::string& name, int depth);
        std::string IndexName(const std::string& name, int depth);
        std::string KeyName(const std::string& name, int depth);
        std::string ValueName(const std::string& name, int depth);
        std::string CollectorName(const std::string& name, int depth);

        //std::string GetAddMethodByCategory(nsCppParser::TMemberExtendedTypeInfo::TypeCategory& category);
        std::string GetPushMethodBy(nsCppParser::TMemberExtendedTypeInfo& ext);
        std::string GetAccessName(std::vector<nsCppParser::TMemberExtendedTypeInfo>& extArr, const std::string& name, int depth);
        std::string GetFusionForAdd(nsCppParser::TMemberExtendedTypeInfo& ext, const std::string& name, int depth);

        std::string GetPopMethodBy(nsCppParser::TMemberExtendedTypeInfo& ext);
        std::string GetInitExpression(nsCppParser::TMemberExtendedTypeInfo& ext);

        // general
        void General_AddPushSerArray(const std::string& keyType,
            const std::string& smartPtrType, const std::string& name, const std::string& methodName);
        void General_AddPushSerMap(const std::string& keyType,
            const std::string& valueType, const std::string& smartPtrType,
            const std::string& name, const std::string& methodName);
        void General_AddPushSerArrayOrMap(const std::string& keyType,
            const std::string& valueType, const std::string& smartPtrType,
            const std::string& name, const std::string& methodName, bool arrayOrMap);

        void General_AddPushReflection(const std::string& ptrName, const std::string& getAddress);

        void General_AddPopSerArray(const std::string& keyType,
            const std::string& smartPtrType, const std::string& name, const std::string& methodName);
        void General_AddPopSerMap(const std::string& keyType,
            const std::string& valueType, const std::string& smartPtrType,
            const std::string& name, const std::string& methodName);
        void General_AddPopSerArrayOrMap(const std::string& keyType,
            const std::string& valueType, const std::string& smartPtrType,
            const std::string& name, const std::string& methodName, bool arrayOrMap);
        void General_AddPopReflection(const std::string& ptrName,
            const std::string& checkOnNullCondition, const std::string& newPtrExpression);

    };
}

