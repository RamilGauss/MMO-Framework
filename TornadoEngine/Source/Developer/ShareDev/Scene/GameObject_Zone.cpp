/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameObject_Zone.h"

TGameObject_Zone::TGameObject_Zone() : 
TGameObject(GetType())
{

}
//---------------------------------------------------------------------------
TGameObject_Zone::~TGameObject_Zone()
{

}
//---------------------------------------------------------------------------
std::string TGameObject_Zone::GetType()
{
  return "Zone";
}
//---------------------------------------------------------------------------
void TGameObject_Zone::SetInternalState(TMapStrStr& mapStrStr)
{

}
//---------------------------------------------------------------------------
bool TGameObject_Zone::GetInternalState(TMapStrStr& mapStrStr)
{
  return false;
}
//---------------------------------------------------------------------------
