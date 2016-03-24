/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameObject_Sound.h"

TGameObject_Sound::TGameObject_Sound() : 
TGameObject(GetType())
{

}
//---------------------------------------------------------------------------
TGameObject_Sound::~TGameObject_Sound()
{

}
//---------------------------------------------------------------------------
std::string TGameObject_Sound::GetType()
{
  return "Sound";
}
//---------------------------------------------------------------------------
void TGameObject_Sound::SetInternalState(TMapStrStr& mapStrStr)
{

}
//---------------------------------------------------------------------------
bool TGameObject_Sound::GetInternalState(TMapStrStr& mapStrStr)
{
  return false;
}
//---------------------------------------------------------------------------
