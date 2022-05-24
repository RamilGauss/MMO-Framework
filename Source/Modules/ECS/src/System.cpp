/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "System.h"

#include <typeinfo>

using namespace nsECSFramework;

void TSystem::SetEntMng(TEntityManager* entMng)
{ 
    mEntMng = entMng;

    mEntMng->AddSystem(this);
}
//-------------------------------------------------------------------------
TEntityManager* TSystem::GetEntMng() 
{ 
    return mEntMng; 
}
//-------------------------------------------------------------------------
TSystem::~TSystem()
{
    mEntMng->RemoveSystem(this);
}
//-------------------------------------------------------------------------
const std::string& TSystem::GetTypeName() const
{
    return typeid(*this).name();
}
//-------------------------------------------------------------------------
