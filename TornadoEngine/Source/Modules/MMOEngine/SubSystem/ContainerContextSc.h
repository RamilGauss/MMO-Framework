/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CONTAINER_CONTEXT_SC_H
#define CONTAINER_CONTEXT_SC_H

#include "ScContextManager.h"
#include <list>

#include "ContextScDisconnectClient.h"
#include "ContextScFlow.h"
#include "ContextScLoginClient.h"
#include "ContextScLoginSlave.h"
#include "ContextScLoginMaster.h"
#include "ContextScRecommutationClient.h"
#include "ContextScSynchroSlave.h"
#include "ContextScSendToClient.h"

namespace nsMMOEngine
{
  // сценарии, содержащиеся в контейнере взаимно блокируются
  class TContainerContextSc
  {
    typedef std::list<IScenarioContext*> TListPtr;
    TListPtr mListContext;
  
    unsigned int mID_Session;
  protected:
    TScContextManager* mManagerContextSc;
  public:
    TContextScDisconnectClient    mDisClient;
    TContextScFlow                mFlow;
    TContextScLoginClient         mLoginClient;
    TContextScLoginSlave          mLoginSlave;
    TContextScLoginMaster         mLoginMaster;
    TContextScRecommutationClient mRcm;
    TContextScSynchroSlave        mSynchroSlave;
    TContextScSendToClient        mSendToClient;

    TContainerContextSc();

    void SetMCSc(TScContextManager* pMCSc);
    TScContextManager* GetMCSc();

    void SetID_Session(unsigned int id_session);
    unsigned int GetID_Session();
    void SetMS(TSessionManager* pMS);
    void SetSE(TSrcEvent* pSE);
    void SetUserPtr(void* p);

    bool IsRcmActive();
    bool IsLoginClientActive();
  };
}  
#endif