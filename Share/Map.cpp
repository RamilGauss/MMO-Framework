/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "Map.h"

TMap::TMap()
{
  mID = 0;
}
//-------------------------------------------------------------
TMap::~TMap()
{

}
//-------------------------------------------------------------
unsigned short TMap::GetID()
{
  return mID;
}
//-------------------------------------------------------------
void TMap::SetID(unsigned short val)
{
  mID = val;
}
//-------------------------------------------------------------
//-------------------------------------------------------------
