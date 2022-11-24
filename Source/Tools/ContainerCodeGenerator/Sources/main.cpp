/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <iostream>
#include <string>
#include <list>
#include <set>
#include <filesystem>

// Автоматизация
// Управляющий над кодогенератором для нужд ядра и проекта в редакторе.
// Настраивает задания для генератора, хранит изначальные настройки.
// В итоге утилита должна сгенерировать агрегатор для ядра.

namespace nsContainerCodeGenerator
{
    struct TGeneratedClass
    {
        std::string directoryPath;

        std::string exportDeclaration;
        std::string fileName;
        std::string typeName;
        std::string nameSpace;
    };

    struct TTargetForParsing
    {
        std::list<std::string> directories;
    };

    struct TComponentConfig : TGeneratedClass, TTargetForParsing
    {
        std::string inheritance;
    };

    struct THandlerConfig : TGeneratedClass, TTargetForParsing
    {
        std::string inheritance;
    };

    struct TSystemConfig : TGeneratedClass, TTargetForParsing
    {
        std::list<std::string> inheritances;
    };

    struct TCoreConfig
    {
        TComponentConfig componentConfig;
        THandlerConfig handlerConfig;
        TSystemConfig systemConfig;
    };

    struct TProjectConfig
    {
        TComponentConfig componentConfig;
        THandlerConfig handlerConfig;
        TSystemConfig systemConfig;
    };

    struct TConfig
    {
        TCoreConfig coreConfig;
        TProjectConfig projectConfig;

        TGeneratedClass targetClass;
    };
}

int main(int argc, char* argv[])
{
    const char* sLocale = setlocale(LC_CTYPE, "");
    sLocale = setlocale(LC_CTYPE, sLocale);
    if (sLocale == nullptr) {
        //BL_FIX_BUG();
    }

    return 0;
}