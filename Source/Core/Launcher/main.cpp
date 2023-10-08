/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifdef WIN32
#include <windows.h>
#endif 

#include <string>
#include <vector>
#include <map>
#include <locale.h>

#include "BL_Debug.h"
#include "TimeSliceEngine.h"
#include "ShareMisc.h"
#include "ConverterLocale.h"
#include "ContainerTypes.h"
#include "FileOperation.h"
#include "PathOperations.h"
#include "ProjectConfigurator.h"

#include <fmt/core.h>

using namespace nsTornadoEngine;
using namespace nsBase;

// Назначение: упростить отладку игры разработчику (нет необходимости создавать с десяток
// исполняемых файлов, достаточно написать скрипт)
//-------------------------------------
typedef std::vector<std::string> TVectorStr;
void ViewHowUse();
void IncorrectPathToProject(const std::string& absProjectPath);

//-------------------------------------
#ifdef WIN32
INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR cmdLine, INT)
{
    char** argv = __argv;
    int argc = __argc;
#else
int main(int argc, char** argv)
{
#endif
    // установить текущую кодировку для мультибайтовой конвертации
    const char* sLocale = setlocale(LC_CTYPE/*LC_ALL*/, "");
    sLocale = setlocale(LC_CTYPE, sLocale);
    if (sLocale == nullptr) {
        BL_FIX_BUG();
    }

    SetCurrentPathByFile(argv[0]);

    if (argc == 1)   {
        ViewHowUse();
        return -1;
    }
    //-----------------------------------------------------------------
    auto timeSliceEngine = new TTimeSliceEngine;

    auto currentDir = TPathOperations::GetCurrentDir();
    auto absProjectPath = TPathOperations::CalculatePathBy(currentDir, argv[1]);

    auto projectConfigurator = new TProjectConfigurator();
    auto loadResult = projectConfigurator->LoadProject(absProjectPath);

    if (loadResult) {
        timeSliceEngine->onModuleCreationEndsCb.Register(projectConfigurator, &TProjectConfigurator::Setup);
        timeSliceEngine->Work(projectConfigurator->GetModuleTypes());
    } else {
        IncorrectPathToProject(absProjectPath);
    }
    delete timeSliceEngine;

    projectConfigurator->UnloadProject();

    delete projectConfigurator;

    return 0;
}
//-------------------------------------------------------------------------------
void IncorrectPathToProject(const std::string& absProjectPath)
{
    auto message = fmt::format("Incorrect path to the file project:\n\"{}\"", absProjectPath);
    BL_MessageBug(message.c_str());
}
//-------------------------------------------------------------------------------
void ViewHowUse()
{
    const char* sMsgUtf8_En =
        "Invalid parameter input.\n"
        "Path to the project file in relation to the launcher.\n"
        "For example:\n"
        "Launcher.exe \"..\\Source\\Tools\\TornadoEditor\\Editor.project\"\n";

    // Ввиду того, что весь исходный код я переконвертировал в utf-8.
    const char* sMsgUtf8_Ru =
        "Некорректный ввод параметров.\n"
        "Путь к файлу проекта относительно лаунчера.\n"
        "\n"
        "Например:\n"
        "Launcher.exe \"..\\Source\\Tools\\TornadoEditor\\Editor.project\"\n";

    int ret = 0;
#ifdef WIN32  
    ret = GetSystemDefaultLangID();
#endif
    const char* sMsgUtf8 = (ret == 1049) ? sMsgUtf8_Ru : sMsgUtf8_En;

#ifdef WIN32
    BL_MessageBug_Utf8(sMsgUtf8);
#else
    BL_MessageBug(sMsgUtf8);
#endif
}
//-------------------------------------------------------------------------------
