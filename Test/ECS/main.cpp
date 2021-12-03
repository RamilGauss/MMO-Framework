/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <fmt/core.h>

#include "MyFeature.h"

using namespace nsECSFramework;

int main()
{
    auto entMng = new TEntityManager();
    auto mainFeature = new TFeature();
    auto myFeature = new TMyFeature();

    TNameComponent nameComponent;
    nameComponent.name = "simple name";
    entMng->GetByUnique(nameComponent);
    entMng->GetByValueCopy(nameComponent);

    entMng->Setup();
    printf("\n");

    mainFeature->SetEntMng(entMng);
    // Construct tree
    mainFeature->Add(myFeature);

    for (int i = 0; i < 100; i++) {
        mainFeature->Execute();
    }

    mainFeature->Clear();

    delete mainFeature;
    delete myFeature;
    delete entMng;

    return 0;
}

