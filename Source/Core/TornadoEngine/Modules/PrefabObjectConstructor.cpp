/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PrefabObjectConstructor.h"

using namespace nsTornadoEngine;

void TPrefabObjectConstructor::ClearAll()
{

}
//-----------------------------------------------------------------------------------------------------
nsECSFramework::TEntityID TPrefabObjectConstructor::Instance(const std::string& prefabGuid)
{
    return nsECSFramework::NONE;
}
//-----------------------------------------------------------------------------------------------------
bool TPrefabObjectConstructor::Attach(nsECSFramework::TEntityID eid, const std::string& objectGuid, const std::string& prefabGuid)
{
    return false;
}
//-----------------------------------------------------------------------------------------------------
