/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IGenerator.h"
#include <functional>
#include "Parser/Sources/MemberExtendedTypeInfo.h"

namespace nsReflectionCodeGenerator
{
    class DllExport IFileGenerator : public IGenerator
    {
    protected:
        const std::string s_TimeHeader = "// {}\n// File has been generated at {}";

        const std::string s_TypeObject = "p";

        const std::string sTab = "    ";
        const std::string s_Bool = "bool";

        const std::string s_CC = "::";
        const std::string s_STD = "std";
        const std::string s_STD_ = "std" + s_CC;

        const std::string s_PushBack = "push_back";
        const std::string s_Insert = "insert";

        const std::string s_First = "first";
        const std::string s_Second = "second";

        const std::string s_Nullptr = "nullptr";
        const std::string s_Static = "static";
        const std::string s_Void = "void";

        const std::string sSerializeMethod = "_Serialize";
        const std::string sDeserializeMethod = "_Deserialize";

        TStrListPair* pStrListPair = nullptr;
        TTypeNameDataBase* mTypeNameDbPtr = nullptr;
        TSerializer* mSerializer = nullptr;

    private:
        int mTabCounter = 0;

    public:
        void Init(TTypeNameDataBase* typeNameDbPtr, TStrListPair& strListPair, TSerializer* serializer);

    protected:
        void AddHeader(const std::string& header);
        void AddTimeHeader();

        void AddCase(const std::string& condition);
        void AddBreak();

        void AddIf(const std::string& condition);
        void AddElse();

        void AddLeftBrace();
        void AddRightBrace();

        void AddEmptyLine();
        void AddCommentedLongLine();

        void AddPragmaOnce();

        void AddInclude(const std::string& fileName);
        void AddStandartInclude(const std::string& fileName);

        void AddNamespaceBegin(const std::string& namespaceName);
        void AddNamespaceEnd();
        void AddUsingNamespace(const std::string& namespaceName);
        void AddUsing(const std::string& expression);

        void AddClassBegin(const std::string& exportDeclaration, const std::string& className);
        void AddClassEnd();

        void AddPublicSection();
        void AddProtectedSection();
        void AddPrivateSection();

        void IncrementTabs();
        void DecrementTabs();
        void ClearTabs();

        void AddStaticMethodDeclaration(const std::string& retName, const std::string& name, std::list<std::string>& paramList);

        void AddMethodImplementationBegin(const std::string& retName, const std::string& className, const std::string& name, std::list<std::string>& paramList);

        void AddCallFunction(const std::string& namespaceFunc, const std::string& funcName, std::list<std::string>& templateList, std::list<std::string>& argList);
        void AddCallObjMethod(const std::string& objectName, const std::string& methodName, std::list<std::string>& templateList, std::list<std::string>& argList);

        void AddVarDeclaration(const std::string& typeName, const std::string& varName);

    protected:
        void Add(const std::string& str);
        void AddList(const std::list<std::string>& strList);
        void AddIncludeExt(const std::string& fileName, const std::string& beginBrace, const std::string& endBrace);

        std::string AddTabsToStr(const std::string& str, int tabCounter);

    protected:
        std::string EnumerateParamToStr(std::list<std::string>& strList);

        std::string GetNullExpression(nsCppParser::TMemberExtendedTypeInfo& ext);

    protected:
        void AddCallingMethodForParent(nsCppParser::TTypeInfo* p, std::function<void(const std::string&)> func);
        void AddCallingMethod(nsCppParser::TTypeInfo* p, std::function<void(nsCppParser::TMemberInfo*)> func);
    private:

        void General_AddCallFunctionOrObjMethod(const std::string& objectName, 
            const std::string& namespaceFunc, const std::string& funcName, 
            std::list<std::string>& templateList, std::list<std::string>& argList);

    protected:
        void AddIncludeForExternalSources(TExternalSources* pExrSrc);

        std::string GetSerializeMethod(nsCppParser::TMemberExtendedTypeInfo* pExt, const std::string& withinClassTypeName);
        std::string GetDeserializeMethod(nsCppParser::TMemberExtendedTypeInfo* pExt, const std::string& withinClassTypeName);

        std::string GetSerializeMethod(const std::string& namespaceWithType, const std::string& withinClassTypeName);
        std::string GetDeserializeMethod(const std::string& namespaceWithType, const std::string& withinClassTypeName);
    
    private:
        std::string GetMethod(const std::string& namespaceWithType, 
            const std::string& withinClassTypeName, const std::string& methodName);
    };
}
