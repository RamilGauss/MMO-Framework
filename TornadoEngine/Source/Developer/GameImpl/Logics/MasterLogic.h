/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ModuleServerLogic.h"
#include "MMOEngine/include/BaseEvent.h"
#include "MMOEngine/include/Events.h"

//#include "MasterForm.h"

class TMasterLogic : public TModuleServerLogic
{
  //TMasterForm* mMasterForm;
    
  unsigned int mCounterClient;

  typedef std::list<unsigned int> TListUint;
  TListUint mListKeyAllClient;

  typedef enum{eAdd,eDelete}TypeEvent;
  struct TSessionOperation
  {
    //TMasterForm::TDesc desc;
    TypeEvent typeEvent;
  };
  TDataExchange2Thread<TSessionOperation> mListSlaveSessionOperation;
public:
  TMasterLogic();
  virtual void InitLog();

  virtual void StartEvent();
  virtual void StopEvent();
protected:
  virtual bool WorkServer();
  virtual void EndWork();

  virtual void Input(int id, void* p, int size);
private:
  void HandleFromMMOEngine(nsMMOEngine::TBaseEvent* pBE);

private:
  void InitForms();
  
  void ConnectToSuperServer();

  void ConnectUp(nsMMOEngine::TConnectUpEvent* pBE);

  void DisconnectUp(nsMMOEngine::TDisconnectUpEvent* pBE);
  void ConnectUpQt();
  void DisconnectUpQt();
  void OperationSessionQt();

  void TryLogin(nsMMOEngine::TTryLoginEvent* pEvent);
  void TryLoginMMOEngine(unsigned int* pID);

  void ConnectDown(nsMMOEngine::TConnectDownEvent* pEvent);
  void DisconnectDown(nsMMOEngine::TDisconnectDownEvent* pEvent);

public:
  void CreateGroup();
};
