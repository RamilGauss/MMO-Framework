/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameObject_Skybox.h"

TGameObject_Skybox::TGameObject_Skybox() : 
TGameObject(GetType())
{

}
//---------------------------------------------------------------------------
TGameObject_Skybox::~TGameObject_Skybox()
{

}
//---------------------------------------------------------------------------
std::string TGameObject_Skybox::GetType()
{
  return "Skybox";
}
//---------------------------------------------------------------------------
void TGameObject_Skybox::SetInternalState(TMapStrStr& mapStrStr)
{

}
//---------------------------------------------------------------------------
bool TGameObject_Skybox::GetInternalState(TMapStrStr& mapStrStr)
{
  return false;
}
//---------------------------------------------------------------------------
