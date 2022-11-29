/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <locale.h>

#include "BL_Debug.h"
#include "ContainerCodeGeneratorLib/Sources/ContainerCodeGenerator.h"

int main(int argc, char* argv[])
{
    const char* sLocale = setlocale(LC_CTYPE, "");
    sLocale = setlocale(LC_CTYPE, sLocale);
    if (sLocale == nullptr) {
        BL_FIX_BUG();
        return 1;
    }

    nsContainerCodeGenerator::TContainerCodeGenerator ccg;
    if (ccg.Init(argc, argv)) {
        ccg.Generate();
    }

    return 0;
}