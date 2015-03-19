/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleDev.h"
#include "ListModules.h"

using namespace std;

TModuleDev::TModuleDev()
{
  mID   = nsListModules::Undef;
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
void TModuleDev::GetName(const char* name)
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
        Input(pCInput->GetPtr(), pCInput->GetSize());
      }
    }
  }
}
//---------------------------------------------------------------------------------
void TModuleDev::OutputFromModules()
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
void TModuleDev::Input(void* p, int size)
{

}
//---------------------------------------------------------------------------------
bool TModuleDev::Output(void* p, int size)
{
  return true;
}
//---------------------------------------------------------------------------------
