/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "World.h"
#include "IConveyerPart.h"

using namespace nsECSFramework;

TWorld::TWorld()
{
    SetEntityManager(new TEntityManager());
}
//--------------------------------------------------------------------------------------
