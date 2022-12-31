/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TextGenerator.h"

#include <fmt/core.h>

namespace nsBase
{
    TTextGenerator::TTextGenerator(std::string& content) :
        mContent(content)
    {

    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::IncrementTabs()
    {
        mTabCount++;
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::DecrementTabs()
    {
        mTabCount--;
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::SetTabs(int value)
    {
        mTabCount = value;
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::Add(const std::list<std::string>& strList)
    {
        for (auto& s : strList) {
            Add(s);
        }
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::Add(const std::string& str)
    {
        mContent += str;
    }
    //--------------------------------------------------------------------------------------------------
    template<typename ... Args>
    void TTextGenerator::AddFormat(const char* format, Args && ... args)
    {
        mContent += fmt::format(format, std::forward<Args>(args)...);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddLine(const std::string& str)
    {
        AddTabs(mTabCount);
        Add(str);
        Add("\n");
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddEmpty()
    {
        AddTabs(mTabCount);
        Add("\n");
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddPragmaOnce()
    {
        AddLine("#pragma once");
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddTabs(int count)
    {
        Add(std::string(mTabCount * 4, ' '));
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddInclude(const std::string& str)
    {
        AddFormatLine("#include \"{}\"", str);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddStdInclude(const std::string& str)
    {
        AddFormatLine("#include <{}>", str);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddNamespace(const std::string& str)
    {
        AddFormatLine("namespace {}", str);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddUsingNamespace(const std::string& str)
    {
        AddFormatLine("using namespace {};", str);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddLeft()
    {
        AddLine("{");
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddRight(bool semiColon)
    {
        if (semiColon) {
            AddLine("};");
        } else {
            AddLine("}");
        }
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddClass(const std::string& typeName, const std::list<std::string>& inheritances)
    {
        AddTemplateClass(typeName, {}, inheritances);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddTemplateClass(const std::string& typeName, const std::list<std::string>& templateArgs,
        const std::list<std::string>& inheritances)
    {
        AddTemplateType("class", typeName, templateArgs, inheritances);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddStruct(const std::string& typeName, const std::list<std::string>& inheritances)
    {
        AddTemplateStruct(typeName, {}, inheritances);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddTemplateStruct(const std::string& typeName, const std::list<std::string>& templateArgs,
        const std::list<std::string>& inheritances)
    {
        AddTemplateType("struct", typeName, templateArgs, inheritances);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddCtorDecl(const std::string& typeName)
    {
        AddFormatLine("{}();", typeName);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddVirtualDtorDecl(const std::string& typeName)
    {
        AddFormatLine("virtual ~{}();", typeName);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddCtorDef(const std::string& typeName)
    {
        AddFormatLine("{}::{}()", typeName, typeName);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddDtorDef(const std::string& typeName)
    {
        AddFormatLine("{}::~{}()", typeName, typeName);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddMethodDecl(const std::string& methodName, const std::string& ret,
        const std::list<std::string>& args, const std::string& modification)
    {
        std::string argsStr;

        int i = 0;
        for (auto& arg : args) {
            argsStr += fmt::format("{}", arg);

            if (i < args.size() - 1) {
                argsStr += ", ";
            }

            i++;
        }

        AddFormatLine("{} {}({}){};", ret, methodName, argsStr, modification);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddMethodDef(const std::string& typeName, const std::string& methodName, const std::string& ret,
        const std::list<std::string>& args)
    {
        std::string argsStr;

        int i = 0;
        for (auto& arg : args) {
            argsStr += fmt::format("{}", arg);

            if (i < args.size() - 1) {
                argsStr += ", ";
            }

            i++;
        }

        if (typeName.size()) {
            AddFormatLine("{} {}::{}({})", ret, typeName, methodName, argsStr);
        } else {
            AddFormatLine("{} {}({})", ret, methodName, argsStr);
        }
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddFuncDef(const std::string& funcName, const std::string& ret,
        const std::list<std::string>& args)
    {
        AddMethodDef("", funcName, ret, args);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddRet(const std::string& retStr)
    {
        std::string returnedValue = (retStr.size() == 0) ? "" : " " + retStr;

        AddFormatLine("return{};", returnedValue);
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddLongLine()
    {
        AddLine("//--------------------------------------------------------------------------------------------------");
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::AddTemplateType(const std::string& type, const std::string& typeName, const std::list<std::string>& templateArgs,
        const std::list<std::string>& inheritances)
    {
        if (templateArgs.size() > 0) {
            std::string templateArgsAcc = "template <";
            int i = 0;
            for (auto& templateArg : templateArgs) {
                templateArgsAcc += fmt::format("{}", templateArg);
                if (i < templateArgs.size() - 1) {
                    templateArgsAcc += ", ";
                }

                i++;
            }

            templateArgsAcc += ">";

            AddLine(templateArgsAcc);
        }

        std::string inheritancesAcc;
        int i = 0;
        for (auto& inheritance : inheritances) {
            inheritancesAcc += fmt::format("{}", inheritance);
            if (i < inheritances.size() - 1) {
                inheritancesAcc += ", ";
            }

            i++;
        }

        if (inheritancesAcc.size()) {
            AddFormatLine("{} {} : {}", type, typeName, inheritancesAcc);
        } else {
            AddFormatLine("{} {}", type, typeName);
        }
    }
    //--------------------------------------------------------------------------------------------------
}