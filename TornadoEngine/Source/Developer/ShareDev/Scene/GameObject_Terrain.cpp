/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GameObject_Terrain.h"

TGameObject_Terrain::TGameObject_Terrain() : 
TGameObject(GetType())
{

}
//---------------------------------------------------------------------------
TGameObject_Terrain::~TGameObject_Terrain()
{

}
//---------------------------------------------------------------------------
std::string TGameObject_Terrain::GetType()
{
  return "Terrain";
}
//---------------------------------------------------------------------------
void TGameObject_Terrain::SetInternalState(TMapStrStr& mapStrStr)
{

}
//---------------------------------------------------------------------------
bool TGameObject_Terrain::GetInternalState(TMapStrStr& mapStrStr)
{
  return false;
}
//---------------------------------------------------------------------------
