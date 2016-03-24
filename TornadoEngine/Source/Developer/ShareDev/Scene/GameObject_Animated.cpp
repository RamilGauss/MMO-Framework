/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameObject_Animated.h"

TGameObject_Animated::TGameObject_Animated() : 
TGameObject(GetType())
{

}
//---------------------------------------------------------------------------
TGameObject_Animated::~TGameObject_Animated()
{

}
//---------------------------------------------------------------------------
std::string TGameObject_Animated::GetType()
{
  return "Animated";
}
//---------------------------------------------------------------------------
void TGameObject_Animated::SetInternalState(TMapStrStr& mapStrStr)
{

}
//---------------------------------------------------------------------------
bool TGameObject_Animated::GetInternalState(TMapStrStr& mapStrStr)
{
  return false;
}
//---------------------------------------------------------------------------
