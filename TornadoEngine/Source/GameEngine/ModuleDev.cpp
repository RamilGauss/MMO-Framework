/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleDev.h"
#include "PrototypeDev.h"

#include <stddef.h>

TModuleDev::TModuleDev()
{
  mPrototypeDev = NULL;
}
//---------------------------------------------------------------------
TModuleDev::~TModuleDev()
{

}
//---------------------------------------------------------------------
bool TModuleDev::Work()
{
  if(mPrototypeDev)
    return mPrototypeDev->Work();
  return true;
}
//---------------------------------------------------------------------
void TModuleDev::SetPrototypeDev(PrototypeDev* ptr)
{
  mPrototypeDev = ptr;
  mPrototypeDev->SetSrcEvent(this);
}
//---------------------------------------------------------------------
