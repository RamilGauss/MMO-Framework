/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <list>
#include <map>

#include <fmt/core.h>

#include "TypeDef.h"

namespace nsBase
{
    class DllExport TTextGenerator
    {
        std::string& mContent;

        int mTabCount = 0;
    public:
        TTextGenerator(std::string& content);

        void IncrementTabs();
        void DecrementTabs();

        void SetTabs(int value);

        void AddTabs(int count);

        void Add(const std::list<std::string>& strList);

        void Add(const std::string& str);

        template<typename ... Args>
        void AddFormat(const char* format, Args && ... args);

        void AddLine(const std::string& str);

        template<typename ... Args>
        void AddFormatLine(const char* format, Args && ... args)
        {
            AddLine(fmt::format(format, std::forward<Args>(args)...));
        }

        void AddEmpty();

        void AddPragmaOnce();

        void AddInclude(const std::string& str);
        void AddStdInclude(const std::string& str);

        void AddNamespace(const std::string& str);
        void AddUsingNamespace(const std::string& str);

        void AddLeft();
        void AddRight(bool semiColon = false);

        void AddClass(const std::string& typeName, const std::list<std::string>& inheritances = {});

        void AddTemplateClass(const std::string& typeName, const std::list<std::string>& templateArgs,
            const std::list<std::string>& inheritances = {});

        void AddStruct(const std::string& typeName, const std::list<std::string>& inheritances = {});

        void AddTemplateStruct(const std::string& typeName, const std::list<std::string>& templateArgs,
            const std::list<std::string>& inheritances = {});

        void AddCtorDecl(const std::string& typeName);
        void AddVirtualDtorDecl(const std::string& typeName);

        void AddCtorDef(const std::string& typeName);
        void AddDtorDef(const std::string& typeName);

        void AddMethodDecl(const std::string& methodName, const std::string& ret,
            const std::list<std::string>& args = {}, const std::string& modification = "");

        void AddMethodDef(const std::string& typeName, const std::string& methodName, const std::string& ret,
            const std::list<std::string>& args = {});

        void AddFuncDef(const std::string& funcName, const std::string& ret,
            const std::list<std::string>& args = {});

        void AddRet(const std::string& retStr);

        void AddLongLine();

        void AddFormatted(const std::list<std::string>& lines, const std::map<std::string, std::string>& namedArgs);

    protected:
        void AddTemplateType(const std::string& type, const std::string& typeName, const std::list<std::string>& templateArgs,
            const std::list<std::string>& inheritances = {});
    };
}