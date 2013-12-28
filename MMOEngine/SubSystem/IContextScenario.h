/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ICONTEXT_SCENARIO_H
#define ICONTEXT_SCENARIO_H

class TSrcEvent;
namespace nsMMOEngine
{
  class TManagerContextSc;
  class TManagerSession;
  class IScenario;
  class IContextScenario
  {
    void*              mUserPtr;
    unsigned int       mID_Session;
    TManagerContextSc* mManagerContextSc;
    TManagerSession*   mManagerSession;
    TSrcEvent*         mSrcEvent;

    IScenario* mScenario;
  public:
    IContextScenario();
    virtual ~IContextScenario();

    bool Activate();
    void Disactivate();

    void DelayBegin();
    void Work();

    void SetSc(IScenario* pSc);
    IScenario* GetSc();

    void SetID_Session(unsigned int id);
    unsigned int GetID_Session();

    void SetMSc(TManagerContextSc* pMSc);
    TManagerContextSc* GetMSc();

    void SetMS(TManagerSession* pMS);
    TManagerSession* GetMS();

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