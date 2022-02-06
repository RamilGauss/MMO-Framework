/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SystemConveyerContainer.h"

using namespace nsECSFramework;

void TSystemConveyerContainer::AddSystem(TSystem* pSystem)
{
    mSystems.insert(pSystem);
}
//-------------------------------------------------------------------------------------------
void TSystemConveyerContainer::RemoveSystem(TSystem* pSystem)
{
    mSystems.erase(pSystem);
}
//-------------------------------------------------------------------------------------------
const std::set<TSystem*>& TSystemConveyerContainer::GetSystems() const
{
    return mSystems;
}
//-------------------------------------------------------------------------------------------