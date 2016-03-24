/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameObject_Model.h"

TGameObject_Model::TGameObject_Model() : 
TGameObject(GetType())
{

}
//---------------------------------------------------------------------------
TGameObject_Model::~TGameObject_Model()
{

}
//---------------------------------------------------------------------------
std::string TGameObject_Model::GetType()
{
  return "Model";
}
//---------------------------------------------------------------------------
void TGameObject_Model::SetInternalState(TMapStrStr& mapStrStr)
{

}
//---------------------------------------------------------------------------
bool TGameObject_Model::GetInternalState(TMapStrStr& mapStrStr)
{
  return false;
}
//---------------------------------------------------------------------------
