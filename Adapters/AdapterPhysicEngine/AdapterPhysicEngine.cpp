/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterPhysicEngine.h"

AdapterPhysicEngine::AdapterPhysicEngine()
{

}
//------------------------------------------------------------------------
AdapterPhysicEngine::~AdapterPhysicEngine()
{

}
//------------------------------------------------------------------------
void AdapterPhysicEngine::AddObject(IBaseObjectPE* pObject)
{

}
//------------------------------------------------------------------------
void AdapterPhysicEngine::Clear()
{

}
//------------------------------------------------------------------------
void AdapterPhysicEngine::InitState()
{

}
//------------------------------------------------------------------------
void AdapterPhysicEngine::Calc()
{

}
//------------------------------------------------------------------------
PrototypeBaseModule* AdapterPhysicEngine::NewExample()
{
  return new AdapterPhysicEngine;
}
//------------------------------------------------------------------------
void AdapterPhysicEngine::DeleteExample(PrototypeBaseModule* ptr)
{
  delete ptr;
}
//------------------------------------------------------------------------
int AdapterPhysicEngine::GetVersionAdapter()
{
  return 1;
}
//------------------------------------------------------------------------
bool AdapterPhysicEngine::Work()
{
  return true;
}
//------------------------------------------------------------------------
