/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MasterLogicH
#define MasterLogicH

#include "ModuleServerLogic.h"
#include "BaseEvent.h"
#include "Events.h"

#include "MasterForm.h"

class TMasterLogic : public TModuleServerLogic
{
  TMasterForm* mMasterForm;
    
  unsigned int mCounterClient;

  typedef std::list<unsigned int> TListUint;
  TListUint mListKeyAllClient;

  TListMultiThread<unsigned int> mListSessionAdd;

  TListMultiThread<TMasterForm::TDesc> mListID_SessionAdd;
  TListMultiThread<TMasterForm::TDesc> mListID_SessionDelete;

  TListMultiThread<unsigned int> mListTryLogic;

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

  void ConnectUp(nsMMOEngine::TEventConnectUp* pBE);
  void ConnectDownMMOEngine();

  void DisconnectUp(nsMMOEngine::TEventDisconnectUp* pBE);
  void ConnectUpQt();
  void DisconnectUpQt();
  void AddSlaveQt();
  void DeleteSlaveQt();

  void TryLogin(nsMMOEngine::TEventTryLogin* pEvent);
  void TryLoginMMOEngine();

  void ConnectDown(nsMMOEngine::TEventConnectDown* pEvent);
  void DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent);

public:
  void CreateGroup();
};

#endif
