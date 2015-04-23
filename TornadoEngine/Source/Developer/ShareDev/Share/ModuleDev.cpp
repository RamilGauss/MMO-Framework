/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleDev.h"

using namespace std;

TModuleDev::TModuleDev()
{
  mID   = -1;
  mName = "";
}
//----------------------------------------------------------------------
int TModuleDev::GetID()
{
  return mID;
}
//----------------------------------------------------------------------
string TModuleDev::GetName()
{
  return mName;
}
//----------------------------------------------------------------------
void TModuleDev::SetID(int id)
{
  mID = id;
}
//----------------------------------------------------------------------
void TModuleDev::SetName(const char* name)
{
  mName = name;
}
//----------------------------------------------------------------------
void TModuleDev::InputFromSynchroPoint()
{
  while(1) 
  {
    int id_sender = 0;
    IContainer* pCInput = NULL;
    pCInput = GetEvent(id_sender);
    if(pCInput==NULL)
      break;
    Input(id_sender, pCInput->GetPtr(), pCInput->GetSize());
  }
}
//---------------------------------------------------------------------------------
