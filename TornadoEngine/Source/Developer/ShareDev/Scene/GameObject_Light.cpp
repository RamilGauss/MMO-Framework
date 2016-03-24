/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameObject_Light.h"

TGameObject_Light::TGameObject_Light() : 
TGameObject(GetType())
{

}
//---------------------------------------------------------------------------
TGameObject_Light::~TGameObject_Light()
{

}
//---------------------------------------------------------------------------
std::string TGameObject_Light::GetType()
{
  return "Light";
}
//---------------------------------------------------------------------------
void TGameObject_Light::SetInternalState(TMapStrStr& mapStrStr)
{

}
//---------------------------------------------------------------------------
bool TGameObject_Light::GetInternalState(TMapStrStr& mapStrStr)
{
  return false;
}
//---------------------------------------------------------------------------
