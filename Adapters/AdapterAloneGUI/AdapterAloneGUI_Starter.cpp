/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterAloneGUI_Starter.h"
#include "PrototypeAloneGUI_Dev.h"

AdapterAloneGUI_Starter::AdapterAloneGUI_Starter()
{
  mDevGUI = NULL;
}
//----------------------------------------------------------------------------
AdapterAloneGUI_Starter::~AdapterAloneGUI_Starter()
{
  if(mDevGUI)
    mDevGUI->Stop();
  mDevGUI = NULL;
}
//----------------------------------------------------------------------------
void AdapterAloneGUI_Starter::SetDev(PrototypeAloneGUI_Dev* pDev)
{
  if(mDevGUI||pDev==NULL)
  {
    BL_FIX_BUG();
    return;
  }
  mDevGUI = pDev;
  mDevGUI->Start();
}
//----------------------------------------------------------------------------
PrototypeBaseModule* AdapterAloneGUI_Starter::NewExample()
{
  return new AdapterAloneGUI_Starter;
}
//----------------------------------------------------------------------------
void AdapterAloneGUI_Starter::DeleteExample(PrototypeBaseModule* ptr)
{
  delete ptr;
}
//----------------------------------------------------------------------------
int AdapterAloneGUI_Starter::GetVersionAdapter()
{
  return 1;
}
//----------------------------------------------------------------------------
bool AdapterAloneGUI_Starter::Work()
{
  return true;
}
//----------------------------------------------------------------------------
