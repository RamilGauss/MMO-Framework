/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GP_Scenario.h"
#include <stddef.h>

TGP_Scenario::TGP_Scenario()
{
  mPtrScene = NULL;
  mType = 0;
}
//-------------------------------------------------------------------------------
TGP_Scenario::~TGP_Scenario()
{

}
//-------------------------------------------------------------------------------
bool TGP_Scenario::IsBlock()
{
  return false;
}
//-------------------------------------------------------------------------------
int  TGP_Scenario::GetType()
{
  return mType;
}
//-------------------------------------------------------------------------------
void TGP_Scenario::SetType(int type)
{
  mType = type;
}
//-------------------------------------------------------------------------------
