/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#define _USE_MATH_DEFINES

#include <cmath>

#include "IActor.h"


IActor::IActor()
{
  pRoom      = NULL;
  mID_Client = -1;
}
//------------------------------------------------------------------------
IActor::~IActor()
{

}
//------------------------------------------------------------------------
void IActor::SetType(unsigned int id)
{

}
//------------------------------------------------------------------------
unsigned int IActor::GetType()
{
  return 0;
}
//------------------------------------------------------------------------
