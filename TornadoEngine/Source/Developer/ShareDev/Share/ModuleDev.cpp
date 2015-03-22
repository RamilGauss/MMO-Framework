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
TModuleDev::~TModuleDev()
{

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
void TModuleDev::InputFromModules()
{
  // пробежка по модулям
  int cntSenders = GetCountSenders();
  for( int iSender = 0 ; iSender < cntSenders ; iSender++ )
  {
    int id_sender = GetID_SenderByIndex(iSender);
    if(id_sender!=-1)
    {
      while(1) 
      {
        TContainer* pCInput = IModule::GetEvent(id_sender);
        if(pCInput==NULL)
          break;
        Input(id_sender, pCInput->GetPtr(), pCInput->GetSize());
      }
    }
  }
}
//---------------------------------------------------------------------------------
void TModuleDev::OutputToModules()
{
  while(1)
  { // модуль создал события
    nsEvent::TEvent* pEvent = TDstEvent::GetEvent();
    if(pEvent==NULL)
      break;

    char* pData = pEvent->pContainer->GetPtr();
    int size    = pEvent->pContainer->GetSize();
    if(Output(pData, size))// обработчик согласен с отправкой наружу
    {
      pEvent->pContainer->Unlink();
      TModuleDev::AddEventWithoutCopy(pData, size);
    }
    delete pEvent;
  }
}
//---------------------------------------------------------------------------------
void TModuleDev::Input(int id_sender, void* p, int size)
{

}
//---------------------------------------------------------------------------------
bool TModuleDev::Output(void* p, int size)
{
  return true;
}
//---------------------------------------------------------------------------------
