/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "EntityManagerMaster.h"

using namespace nsECSFramework;

void TEntityManagerMaster::AddEntityManager(TEntityManager* pEntMng)
{
    mEntMngs.insert(pEntMng);
}
//--------------------------------------------------------------------------------------
void TEntityManagerMaster::RemoveEntityManager(TEntityManager* pEntMng)
{
    mEntMngs.erase(pEntMng);
}
//--------------------------------------------------------------------------------------
const std::set<TEntityManager*>& TEntityManagerMaster::GetEntityManager() const
{
    return mEntMngs;
}
//--------------------------------------------------------------------------------------