/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SlaveLogicH
#define SlaveLogicH

#include "ModuleServerLogic.h"
#include "BaseEvent.h"
#include "Events.h"
//#include "SlaveForm.h"

class TSlaveLogic : public TModuleServerLogic
{
  //TSlaveForm* mSlaveForm;

  enum
  {
    eCycleTime = 100,
  };

  typedef enum{eAdd,eDelete}TypeEvent;
  struct TSessionOperation
  {
    //TSlaveForm::TDesc desc;
    TypeEvent typeEvent;
  };
  TDataExchange2Thread<TSessionOperation> mListClientSessionOperation;
public:
  TSlaveLogic();
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
  void StartTimer();
  void InitForms();
  void ConnectToMaster();

  void ConnectUpQt();
  void DisconnectUpQt();
  void OperationSessionQt();

  void SaveContextClientMMOEngine(unsigned int* pID);

  void ConnectUp(nsMMOEngine::TEventConnectUp* pBE);
  void DisconnectUp(nsMMOEngine::TEventDisconnectUp* pBE);

  void ConnectDown(nsMMOEngine::TEventConnectDown* pEvent);
  void DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent);

  void SaveContextClient(nsMMOEngine::TEventSaveContext* pEvent);
  void RestoreContextClient(nsMMOEngine::TEventRestoreContext* pEvent);

  void InitMMOSlave();
  void BeginWorkMMOSlave();
};

#endif
