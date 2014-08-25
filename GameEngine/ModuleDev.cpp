/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleDev.h"
#include "PrototypeDev.h"

#include <stddef.h>

ModuleDev::ModuleDev()
{
  mPrototypeDev = NULL;
}
//---------------------------------------------------------------------
ModuleDev::~ModuleDev()
{

}
//---------------------------------------------------------------------
bool ModuleDev::Work()
{
  if(mPrototypeDev)
    return mPrototypeDev->Work();
  return true;//### 
}
//---------------------------------------------------------------------
void ModuleDev::SetPrototypeDev(PrototypeDev* ptr)
{
  mPrototypeDev = ptr;
  mPrototypeDev->SetSrcEvent(this);
}
//---------------------------------------------------------------------
