/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/compile.h>

#include "Base/Common/HiTimer.h"

#include "ReflectionCodeGeneratorLib/Sources/IFileGenerator.h"

using namespace nsReflectionCodeGenerator;
using namespace nsCppParser;

void IFileGenerator::Init(TResolvedConfig* resolvedConfig, TTypeManager* typeManager,
     TTypeNameDataBase* typeNameDbPtr, TStrListPair& strListPair, TSerializerExt* serializer)
{
    pStrListPair = &strListPair;
    mSerializer = serializer;
    mTypeNameDbPtr = typeNameDbPtr;
    mResolvedConfig = resolvedConfig;
    mTypeManager = typeManager;
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddHeader(const std::string& header)
{
    std::list<std::string> strList;
    strList.push_back("/*");
    strList.push_back(header);
    strList.push_back("*/");

    AddList(strList);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddTimeHeader()
{
    auto s = s_TimeHeader;

    s = fmt::format(fmt::runtime(s), TProgramInfo::Get(), ht_GetTimeStr());

    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddSwitch(const std::string& expr)
{
    auto s = fmt::format("switch ({}) {{", expr);
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddCase(const std::string& condition)
{
    auto s = fmt::format("case {}:", condition);
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddBreak()
{
    Add("break;");
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddDefault()
{
    Add("default:;");
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddIf(const std::string& condition)
{
    auto s = fmt::format("if ({})", condition);
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddElse()
{
    auto s = "else";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddLeftBrace()
{
    auto s = "{";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddRightBrace()
{
    auto s = "}";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddEmptyLine()
{
    auto s = "";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddCommentedLongLine()
{
    auto s = "//---------------------------------------------------------------------------------------";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddPragmaOnce()
{
    auto s = "#pragma once";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddInclude(const std::string& fileName)
{
    AddIncludeExt(fileName, "\"", "\"");
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddStandartInclude(const std::string& fileName)
{
    AddIncludeExt(fileName, "<", ">");
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddNamespaceBegin(const std::string& namespaceName)
{
    auto s = fmt::format("namespace {}", namespaceName);
    Add(s);
    s = "{";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddNamespaceEnd()
{
    auto s = "}";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddUsingNamespace(const std::string& namespaceName)
{
    auto s = fmt::format("using namespace {};", namespaceName);
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddUsing(const std::string& expression)
{
    auto s = fmt::format("using {};", expression);
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddClassBegin(const std::string& exportDeclaration, const std::string& className)
{
    std::string sEexportDeclaration;
    if (exportDeclaration.length()) {
        sEexportDeclaration = fmt::format(" {}", exportDeclaration);
    }
    auto s = fmt::format("class{} {}", sEexportDeclaration, className);
    Add(s);
    s = "{";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddClassEnd()
{
    auto s = "};";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddIncludeExt(const std::string& fileName, const std::string& beginBrace, const std::string& endBrace)
{
    auto s = fmt::format("#include {0}{1}{2}", beginBrace, fileName, endBrace);
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::Add(const std::string& str)
{
    auto s = AddTabsToStr(str, mTabCounter);

    pStrListPair->second.push_back(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::IncrementTabs()
{
    mTabCounter++;
}
//----------------------------------------------------------------------------------
void IFileGenerator::DecrementTabs()
{
    mTabCounter--;
}
//----------------------------------------------------------------------------------
void IFileGenerator::ClearTabs()
{
    mTabCounter = 0;
}
//----------------------------------------------------------------------------------
std::string IFileGenerator::AddTabsToStr(const std::string& str, int tabCounter)
{
    std::string tabAcculumator;
    for (auto i = 0; i < tabCounter; i++) {
        tabAcculumator += sTab;
    }
    return tabAcculumator + str;
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddPublicSection()
{
    auto s = "public:";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddProtectedSection()
{
    auto s = "protected:";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddPrivateSection()
{
    auto s = "private:";
    Add(s);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddList(const std::list<std::string>& strList)
{
    for (auto& str : strList) {
        Add(str);
    }
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddStaticMethodDeclaration(const std::string& retName, const std::string& name, std::list<std::string>& paramList)
{
    std::string str = fmt::format("{} {} {}(", s_Static, retName, name);
    str += EnumerateParamToStr(paramList);
    str += ");";
    Add(str);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddMethodImplementationBegin(const std::string& retName, const std::string& className, const std::string& name, std::list<std::string>& paramList)
{
    std::string str = fmt::format("{} {}::{}(", retName, className, name);

    str += EnumerateParamToStr(paramList);
    str += ")";
    Add(str);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddCallFunction(const std::string& namespaceFunc, const std::string& funcName, std::list<std::string>& templateList, std::list<std::string>& argList)
{
    General_AddCallFunctionOrObjMethod("", namespaceFunc, funcName, templateList, argList);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddCallObjMethod(const std::string& objectName, const std::string& methodName, std::list<std::string>& templateList, std::list<std::string>& argList)
{
    General_AddCallFunctionOrObjMethod(objectName, "", methodName, templateList, argList);
}
//----------------------------------------------------------------------------------
void IFileGenerator::General_AddCallFunctionOrObjMethod(const std::string& objectName, const std::string& namespaceFunc,
    const std::string& funcName, std::list<std::string>& templateList, std::list<std::string>& argList)
{
    std::string namespacePredict;
    if (namespaceFunc.length()) {
        namespacePredict = namespaceFunc + "::";
    }

    std::string objPredict;
    if (objectName.length()) {
        objPredict = objectName + ".";
    }

    std::string str = fmt::format("{}{}{}", objPredict, namespacePredict, funcName);
    auto templ = EnumerateParamToStr(templateList);
    if (templ.length()) {
        str += fmt::format("<{}>", templ);
    }

    str += "(";
    auto args = EnumerateParamToStr(argList);
    if (args.length()) {
        str += " " + args;
    }

    str += ");";
    Add(str);
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddVarDeclaration(const std::string& typeName, const std::string& varName)
{
    auto str = fmt::format("{} {};", typeName, varName);
    Add(str);
}
//----------------------------------------------------------------------------------
std::string IFileGenerator::EnumerateParamToStr(std::list<std::string>& paramList)
{
    std::list<std::string> existStrList;
    for (auto param : paramList) {
        if (param.length() > 0) {
            existStrList.push_back(param);
        }
    }

    std::string str;
    size_t cnt = existStrList.size();
    size_t i = 0;
    for (auto param : existStrList) {
        str += param;
        if (i != cnt - 1) {
            str += ", ";
        }
        i++;
    }
    return str;
}
//----------------------------------------------------------------------------------
std::string IFileGenerator::GetNullExpression(TMemberExtendedTypeInfo& ext)
{
    auto typeName = ext.GetTypeNameWithNameSpace();
    switch (ext.mAccessMethod) {
        case AccessMethod::OBJECT:
            return "";
        case AccessMethod::POINTER:
            return " = nullptr";
        case AccessMethod::SMART_POINTER:
            return "";
    }
    return std::string();
}
//-----------------------------------------------------------------------------------------------------------
void IFileGenerator::AddCallingMethodForParent(TTypeInfo* p, std::function<void(TInheritanceInfo*)> func)
{
    for (auto& inheritanceInfo : p->mInheritanceVec) {
        if (inheritanceInfo.mInheritanceAccessLevel != AccessLevel::PUBLIC) {
            continue;
        }
        func(&inheritanceInfo);
    }
}
//-----------------------------------------------------------------------------------------------------------
void IFileGenerator::AddCallingMethod(TTypeInfo* p, std::function<void(TMemberInfo*)> func)
{
    auto& pubMembers = p->mMembers[(int) AccessLevel::PUBLIC];
    for (auto memberInfo : pubMembers) {
        func(memberInfo.get());
    }
}
//-----------------------------------------------------------------------------------------------------------
void IFileGenerator::AddIncludeForExternalSources()
{
    std::set<std::string> fileNameSet;

    auto& fullTypeNameReferenceMap = mTypeNameDbPtr->GetFullTypeNameReferenceMap();
    for (auto& fullTypeRef : fullTypeNameReferenceMap) {
        auto& refType = fullTypeRef.second;
        if (refType.refType == TTypeNameDataBase::ReferenceType::CUSTOMIZED) {
            fileNameSet.insert(refType.reflectionInfo->fileName + ".h");
        }
    }

    for (auto& fileName : fileNameSet) {
        AddInclude(fileName);
    }
}
//-----------------------------------------------------------------------------------------------------------
std::string IFileGenerator::GetSerializeMethod(TMemberExtendedTypeInfo* pMemberExtendedInfo,
    const std::list<std::string>& withinClassTypeNameList)
{
    return GetMethod(pMemberExtendedInfo, withinClassTypeNameList, sSerializeMethod, sSerializeEnumMethod);
}
//-----------------------------------------------------------------------------------------------------------
std::string IFileGenerator::GetDeserializeMethod(TMemberExtendedTypeInfo* pMemberExtendedInfo,
    const std::list<std::string>& withinClassTypeNameList)
{
    return GetMethod(pMemberExtendedInfo, withinClassTypeNameList, sDeserializeMethod, sDeserializeEnumMethod);
}
//-----------------------------------------------------------------------------------------------------------
std::string IFileGenerator::GetMethod(TMemberExtendedTypeInfo* pMemberExtendedInfo,
    const std::list<std::string>& withinClassTypeNameList,
    const std::string& methodStructOrClassName, const std::string& methodEnumName)
{
    std::string method;
    TTypeInfo* type = nullptr;
    TTypeNameDataBase::TTypeInfo typeInfo{ pMemberExtendedInfo->mNameSpace , pMemberExtendedInfo->mShortType };
    auto refType = Find(typeInfo, withinClassTypeNameList, type);
    if (type == nullptr) {
        return method;
    }

    std::string methodName = 
        type->mType == DeclarationType::ENUM ? methodEnumName : methodStructOrClassName;

    if (refType->refType == TTypeNameDataBase::ReferenceType::GENERATED) {
        method = fmt::format("{}", methodName);
    } else {
        auto reflInfo = refType->reflectionInfo.get();
        method = fmt::format("{}::{}::{}",
            reflInfo->nameSpace, reflInfo->className, methodName);
    }
    return method;
}
//-----------------------------------------------------------------------------------------------------------
const TTypeNameDataBase::TReferenceInfo* IFileGenerator::Find(TMemberExtendedTypeInfo* pMemberExtendedInfo, 
    const std::list<std::string>& withinClassTypeNameList,
    TTypeInfo*& type)
{
    TTypeNameDataBase::TTypeInfo typeInfo{ pMemberExtendedInfo->mNameSpace , pMemberExtendedInfo->mShortType };
    return Find(typeInfo, withinClassTypeNameList, type);
}
//-----------------------------------------------------------------------------------------------------------
const TTypeNameDataBase::TReferenceInfo* IFileGenerator::Find(const TTypeNameDataBase::TTypeInfo& typeInfo,
    const std::list<std::string>& withinClassTypeNameList, TTypeInfo*& type)
{
    type = nullptr;
    for (auto& withinClassTypeName : withinClassTypeNameList) {
        TTypeNameDataBase::TRequestParams requestParams;

        requestParams.typeInfo = typeInfo;
        requestParams.preferredNameSpace = withinClassTypeName;

        auto refType = mTypeNameDbPtr->GetReferenceFullTypeName(requestParams);
        if (refType == nullptr) {
            continue;
        }

        type = mTypeManager->Get(refType->typeInfo.GetFullType());
        return refType;
    }

    return nullptr;
}
//-----------------------------------------------------------------------------------------------------------
