/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifdef WIN32
#include <windows.h>
#include <atlconv.h>
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

using namespace std;
using namespace nsTornadoEngine;
using namespace nsBase;

// Назначение: упростить отладку игры разработчику (нет необходимости создавать с десяток
// исполняемых файлов, достаточно написать скрипт)
//-------------------------------------
typedef vector<string> TVectorStr;
void ViewHowUse();
bool GetArgvArgcConsole(int argc, char** argv, TVectorStr& vec_argv);
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

    TVectorStr vec_argv;
    bool resGet = GetArgvArgcConsole(argc, argv, vec_argv);

    if (argc == 1)   {
        ViewHowUse();
        return -1;
    }
    //-----------------------------------------------------------------  
    auto projectAbsPath = TPathOperations::CalculatePathBy(argv[0], argv[1]);

    auto pTimeSliceEngine = new TTimeSliceEngine;
    pTimeSliceEngine->Work(projectAbsPath);
    delete pTimeSliceEngine;
    return 0;
}
//-------------------------------------------------------------------------------
bool GetArgvArgcConsole(int argc, char** argv, TVectorStr & argsVec)
{
    for (int i = 0; i < argc; i++) {
        argsVec.push_back(string(argv[i]));
    }
    return bool(argc > 0);
}
//-------------------------------------------------------------------------------
void ViewHowUse()
{
    char* sMsgUtf8_En =
        "Invalid parameter input.\n"
        "Path to project file.\n"
        "For example:\n"
        "Launcher.exe \"../MyPath/MyGame.project\"\n";

    // Ввиду того, что весь исходный код я переконвертировал в utf-8.
    char* sMsgUtf8_Ru =
        "Некорректный ввод параметров.\n"
        "Путь к файлу проекта.\n"
        "\n"
        "Например:\n"
        "Launcher.exe \"../MyPath/MyGame.project\"\n";

    int ret = 0;
#ifdef WIN32  
    ret = GetSystemDefaultLangID();
#endif
    char* sMsgUtf8 = (ret == 1049) ? sMsgUtf8_Ru : sMsgUtf8_En;

#ifdef WIN32
    BL_MessageBug_Utf8(sMsgUtf8);
#else
    BL_MessageBug(sMsgUtf8);
#endif
}
//-------------------------------------------------------------------------------
