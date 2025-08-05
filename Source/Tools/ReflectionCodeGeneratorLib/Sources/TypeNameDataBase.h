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

#include "Base/Common/TypeDef.h"

namespace nsReflectionCodeGenerator
{
    class DllExport TTypeNameDataBase
    {
    public:
        enum class ReferenceType
        {
            GENERATED,
            CUSTOMIZED,
        };

        struct DllExport TReflectionInfo
        {
            std::string fileName;
            std::string nameSpace;
            std::string className;

            std::string absFilePath;
            std::string filePathForInclude;
        };

        struct DllExport TTypeInfo
        {
            std::string nameSpace;
            std::string typeName;

            std::string GetFullType() const;
            bool operator == (TTypeInfo const& p) const;
            bool operator<(TTypeInfo const& p) const;
        };

        struct DllExport TReferenceInfo
        {
            TTypeInfo typeInfo;
            ReferenceType refType;
            std::shared_ptr<TReflectionInfo> reflectionInfo;
        };

        struct DllExport TRequestParams
        {
            TTypeInfo typeInfo;
            std::string preferredNameSpace;
        };

        void AddForGenerate(TTypeInfo& typeInfo);
        const std::set<TTypeInfo>& GetForGenerate() const;

        void AddReference(TReferenceInfo& refInfo);
        const TReferenceInfo* GetReferenceFullTypeName(TRequestParams& requestParams);

        const std::map<std::string, TReferenceInfo>& GetFullTypeNameReferenceMap() const;
    protected:
        const TReferenceInfo* Find(const std::string& fullTypeName);
        void GetReferenceVariants(TRequestParams& requestParams, std::list<std::string>& variants);

        std::map<std::string, TReferenceInfo> mFullTypeNameReferenceMap;
        std::set<TTypeInfo> mForGenerateList;
    };
}
