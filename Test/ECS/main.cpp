/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MyFeature.h"

#include "EntityManager.h"

using namespace nsECSFramework;

size_t tabCount = 0;

void ShowSystem(TSystem* pSystem)
{
    auto name = pSystem->GetTypeName();
    auto tab = std::string(tabCount * 4, ' ');

    if (pSystem->IsFeature()) {
        printf("%s[%s", tab.c_str(), name.c_str());

        auto pFeature = dynamic_cast<TFeature*>(pSystem);
        auto systems = pFeature->GetSystems();

        if (systems.size() > 0) {
            printf(":(%d)]\n", (int)systems.size());
        } else {
            printf("]\n");
        }

        tabCount++;
        for (auto system : systems) {
            ShowSystem(system);
        }
        tabCount--;
    } else {
        printf("%s%s\n", tab.c_str(), name.c_str());
    }
}

void ShowConveyorTree(std::list<TSystem*> topSystems)
{
    printf("Logic conveyor:\n");
    for (auto pSystem : topSystems) {
        ShowSystem(pSystem);
    }
}

void ShowEntities()
{

}

int main()
{
    const char* sLocale = setlocale(LC_CTYPE, "");
    sLocale = setlocale(LC_CTYPE, sLocale);
    if (sLocale == nullptr) {
        BL_FIX_BUG();
    }

    auto entMng = new TEntityManager("Test");
    auto mainFeature = new TFeature();
    auto myFeature = new TMyFeature();

    entMng->Setup();
    printf("\n");

    mainFeature->SetEntMng(entMng);
    // Construct tree
    mainFeature->Add(myFeature);

    auto topSystems = entMng->GetTopSystems();

    ShowConveyorTree(topSystems);

    for (int i = 0; i < 100; i++) {
        mainFeature->Execute();

        TNameComponent nameComponent;
        nameComponent.name = "1";

        auto hasEids = entMng->GetByHasCopy<TNameComponent>();
        auto nameEid = entMng->GetByUnique(nameComponent);
        //auto copyEids = entMng->GetByValueCopy(nameComponent);
    }

    mainFeature->Clear();

    delete mainFeature;
    delete myFeature;
    delete entMng;

    return 0;
}

