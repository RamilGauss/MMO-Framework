/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModuleServerLogicSuperServer_DevH
#define ModuleServerLogicSuperServer_DevH

#include "ModuleServerLogic.h"
#include "BaseEvent.h"
#include "ListMultiThread.h"
#include "SuperServerForm.h"
#include "Events.h"

class TModuleServerLogicSuperServer_Dev : public TModuleServerLogic
{
  TSuperServerForm* mSuperServerForm;

  TListMultiThread<unsigned int> mListSessionAdd;

  TListMultiThread<TSuperServerForm::TDesc> mListID_SessionAdd;
  TListMultiThread<TSuperServerForm::TDesc> mListID_SessionDelete;
public:
  TModuleServerLogicSuperServer_Dev();
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

  void AddMasterQt();
  void DeleteMasterQt();

  void ConnectDown(nsMMOEngine::TEventConnectDown* pEvent);
  void ConnectDownMMOEngine();
  void DisconnectDown(nsMMOEngine::TEventDisconnectDown* pEvent);
};

#endif
