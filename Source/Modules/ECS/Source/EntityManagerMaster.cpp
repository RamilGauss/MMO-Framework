/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <algorithm>

#include "EntityManagerMaster.h"

using namespace nsECSFramework;

void TEntityManagerMaster::AddEntityManager(TEntityManager* pEntMng)
{
    mEntMngs.push_back(pEntMng);
}
//--------------------------------------------------------------------------------------
void TEntityManagerMaster::RemoveEntityManager(TEntityManager* pEntMng)
{
    auto it = std::remove_if(mEntMngs.begin(), mEntMngs.end(), 
        [pEntMng](const TEntityManager* p) {return p == pEntMng; });

    mEntMngs.erase(it, mEntMngs.end());
}
//--------------------------------------------------------------------------------------
const std::vector<TEntityManager*>& TEntityManagerMaster::GetEntityManager() const
{
    return mEntMngs;
}
//--------------------------------------------------------------------------------------