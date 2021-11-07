/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <fmt/core.h>

#include "MyFeature.h"

using namespace nsECSFramework;

TEntityManager entMng;

TFeature mainFeature;

TMyFeature myFeature;

int main()
{
    TNameComponent nameComponent;
    nameComponent.name = "asda";
    entMng.GetByUnique<TNameComponent>(nameComponent);
    entMng.GetByValue<TNameComponent>(nameComponent);


    entMng.Setup();
    printf("\n");

    mainFeature.SetEntMng(&entMng);

    mainFeature.Add(&myFeature);

    while (true) {
        mainFeature.Execute();
    }

    return 0;
}

