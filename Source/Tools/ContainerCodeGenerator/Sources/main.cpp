/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <locale.h>

#include "BL_Debug.h"
#include "ContainerCodeGeneratorLib/Sources/CoreContainerCodeGenerator.h"
#include "ContainerCodeGeneratorLib/Sources/ProjectContainerCodeGenerator.h"

void PrintUsage(char* argv[])
{
    printf("usage: %s [\"core\"|\"project\"] [filePath]", argv[0]);
}

int main(int argc, char* argv[])
{
    const char* sLocale = setlocale(LC_CTYPE, "");
    sLocale = setlocale(LC_CTYPE, sLocale);
    if (sLocale == nullptr) {
        BL_FIX_BUG();
        return -1;
    }

    if (argc != 3) {
        PrintUsage(argv);
        return -2;
    }

    std::string generatorType = argv[1];
    std::string filePath = argv[2];

    nsContainerCodeGenerator::TContainerCodeGenerator* ccg = nullptr;
    if (generatorType == "core") {
        ccg = new nsContainerCodeGenerator::TCoreContainerCodeGenerator();
    } else if (generatorType == "project") {
        ccg = new nsContainerCodeGenerator::TProjectContainerCodeGenerator();
    } else {
        PrintUsage(argv);
        return -3;
    }
    auto result = static_cast<int>(ccg->Generate(filePath));
    delete ccg;

    return result;
}