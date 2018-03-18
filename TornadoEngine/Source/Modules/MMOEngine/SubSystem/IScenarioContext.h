/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MMOEngineIScenarioContextH
#define MMOEngineIScenarioContextH

#include "BreakPacket.h"

class TSrcEvent;
namespace nsMMOEngine
{
  class TScContextManager;
  class TSessionManager;
  class IScenario;
  class IScenarioContext
  {
    void*              mUserPtr;
    unsigned int       mID_Session;
    TScContextManager* mManagerContextSc;
    TSessionManager*   mSessionManager;
    TSrcEvent*         mSrcEvent;

    IScenario* mScenario;
  protected:
    TBreakPacket mBP;
  public:
    IScenarioContext();
    virtual ~IScenarioContext();

    bool Activate();
    void Disactivate();

    void DelayBegin();
    void Work();

    void SetSc(IScenario* pSc);
    IScenario* GetSc();

    void SetID_Session(unsigned int id);
    unsigned int GetID_Session();

    void SetMSc(TScContextManager* pMSc);
    TScContextManager* GetMSc();

    void SetMS(TSessionManager* pMS);
    TSessionManager* GetMS();

    void SetSE(TSrcEvent* pMS);
    TSrcEvent* GetSE();

    void SetUserPtr(void* p);
    void* GetUserPtr();

    // можно ли сейчас удалить
    bool CanDelete();
    // удалить контекст позже, после дезактивации
    void DeleteLater();
    // поставили ли на удаление позже
    bool IsSetDeleteLater();
  protected:
  };
}

#endif