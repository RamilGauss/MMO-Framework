/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include "CallBackRegistrator.h"

namespace nsMMOEngine
{
  class IScenarioContext;
  class TScContextManager
  {
    typedef std::list<IScenarioContext*> TListPtr;
    typedef TListPtr::iterator TListPtrIt;

    TListPtr   mListWaitActivation;
    IScenarioContext* mPtrActiveContextSc;// активный на данный момент 

    TCallBackRegistrator1<TScContextManager*> mCallBackActivateEvent;
    TCallBackRegistrator1<TScContextManager*> mCallBackDisactivateEvent;
  public:
    TScContextManager();
    ~TScContextManager();

    // для обработки внутренних событий
    void Work();

    bool Activate( IScenarioContext* pCSc );
    void Deactivate();

    IScenarioContext* GetActive();

  protected:
    friend class TManagerManagerContextSc;

    bool IsActive();
    TCallBackRegistrator1<TScContextManager*>* GetCallBackActivate();
    TCallBackRegistrator1<TScContextManager*>* GetCallBackDisactivate();
  private:
    void NotifyActiveEvent();
    void NotifyDisactiveEvent();
  };
}
