/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SuperServerLogicH
#define SuperServerLogicH

#include "ModuleServerLogic.h"
#include "BaseEvent.h"
//#include "SuperServerForm.h"
#include "Events.h"

class TSuperServerLogic : public TModuleServerLogic
{
  //TSuperServerForm* mSuperServerForm;

  typedef enum{eAdd,eDelete}TypeEvent;
  struct TSessionOperation
  {
    //TSuperServerForm::TDesc desc;
    TypeEvent typeEvent;
  };
  TDataExchange2Thread<TSessionOperation> mListMasterSessionOperation;
public:
  TSuperServerLogic();
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
  void OpenPort();

  void OperationSessionQt();

  void ConnectDown(nsMMOEngine::TEventConnectDown* pEvent);
  void ConnectDownMMOEngine();
  void DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent);
};

#endif
