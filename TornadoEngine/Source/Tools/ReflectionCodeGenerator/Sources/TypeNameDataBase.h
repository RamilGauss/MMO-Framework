/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>
#include <string>
#include <map>
#include <list>
#include <memory>

namespace nsReflectionCodeGenerator
{
    class TTypeNameDataBase
    {
    public:
        enum class ReferenceType
        {
            GENERATED,
            CUSTOMIZED,
        };

        struct TReflectionInfo
        {
            std::string fileName;
            std::string nameSpace;
            std::string className;
        };

        struct TTypeInfo
        {
            std::string nameSpace;
            std::string typeName;

            std::string GetFullType() const;
            bool operator == (TTypeInfo const& p) const;
            bool operator<(TTypeInfo const& p) const;
        };

        struct TReferenceInfo
        {
            TTypeInfo typeInfo;
            ReferenceType refType;
            std::shared_ptr<TReflectionInfo> reflectionInfo;
        };

        struct TRequestParams
        {
            TTypeInfo typeInfo;
            std::string preferredNameSpace;
        };

        void AddForGenerate(TTypeInfo& typeInfo);
        const std::set<TTypeInfo>* GetForGenerate() const;

        void AddReference(TReferenceInfo& refInfo);
        const TReferenceInfo* GetReferenceFullTypeName(TRequestParams& requestParams);
    protected:
        const TReferenceInfo* Find(const std::string& fullTypeName);
        void GetReferenceVariants(TRequestParams& requestParams, std::list<std::string>& variants);

        std::map<std::string, TReferenceInfo> mFullTypeNameReferenceMap;
        std::set<TTypeInfo> mForGenerateList;
    };
}
