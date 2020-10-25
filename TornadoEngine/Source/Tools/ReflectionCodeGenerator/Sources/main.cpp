/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fmt/core.h>

#include "SingletonManager.h"
#include "Config.h"
#include "TokenInfoManager.h"
#include "TokenInfo.h"
#include "Parser.h"
#include "ConfigContainer.h"
#include "Requirements.h"
#include "readerwriterqueue.h"
#include "TypeManager.h"
#include "CodeGeneratorFusion.h"
#include "MemberTypeExtendedInfoAnalyzer.h"
#include "SetupConfig.h"
#include "ProgramInfo.h"
#include "HiTimer.h"
#include "JsonSerializer.h"
#include "BL_Debug.h"

using namespace nsReflectionCodeGenerator;

//---------------------------------------------------------------------------------------
void ShowTitle()
{
    fmt::print("{} version {}, build {}, info {}\n",
        nsProgramInfo::NAME, nsProgramInfo::VERSION, nsProgramInfo::COUNTER_BUILD, nsProgramInfo::INFO);
}
//---------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    const char* sLocale = setlocale(LC_CTYPE, "");
    sLocale = setlocale(LC_CTYPE, sLocale);
    if ( sLocale == nullptr ) {
        BL_FIX_BUG();
    }

    try {
        ShowTitle();

        TSetupConfig setupConfig;
        if ( setupConfig.Work() == false )
            return 1;

        TParser parser;
        parser.Work();

        // дополнить расширенной информацией
        TMemberTypeExtendedInfoAnalyzer analyzer;
        analyzer.Work();

        TCodeGeneratorFusion cgFusion;
        cgFusion.Work();
    }
    catch ( std::exception& ex ) {
        printf("exception: %s\n", ex.what());
        return 1;
    }
    return 0;
}