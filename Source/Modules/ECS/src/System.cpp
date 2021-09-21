/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "System.h"

using namespace nsECSFramework;

void TSystem::SetEntMng(TEntityManager* entMng)
{ 
    mEntMng = entMng; 
}
//-------------------------------------------------------------------------
TEntityManager* TSystem::GetEntMng() 
{ 
    return mEntMng; 
}
//-------------------------------------------------------------------------