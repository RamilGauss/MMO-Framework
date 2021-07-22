/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ModulesAccessor.h"

using namespace nsTornadoEngine;

void TModulesAccessor::SetGraphic(TGraphicEngine* newValue)
{
    Modules()->graphic = newValue;
}

void TModulesAccessor::SetPhysic(TPhysicEngine* newValue)
{
    Modules()->physic = newValue;
}

void TModulesAccessor::SetEntMng(TEntityManager* newValue)
{
    Modules()->entMng = newValue;
}

void TModulesAccessor::SetSceneMng(TSceneManager* newValue)
{
    Modules()->sceneMng = newValue;
}

void TModulesAccessor::SetPrefabMng(TPrefabManager* newValue)
{
    Modules()->prefabMng = newValue;
}
