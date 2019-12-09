/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IScenario.h"
#include "ContextScRecommutationClient.h"

#include "ScRecommutationClient_ClientImpl.h"
#include "ScRecommutationClient_MasterImpl.h"
#include "ScRecommutationClient_SlaveImpl.h"

namespace nsMMOEngine
{
  struct TDescRequestConnectForRecipient;

  class TScenarioRecommutationClient : public IScenario
  {
    // по ключу дать контекст, с учетом Донор или Реципиент
    TCallBackRegistrator2<unsigned int, bool> mCBNeedContextByClientKeyForSlave;
    // по сессии дать контекст, с учетом Донор или Реципиент
    TCallBackRegistrator2<unsigned int, bool> mCBNeedContextByClientSessionForSlave;
    // на каком Slave находится Клиент? назначить сессию через Context()->SetSessionDonor()
    TCallBackRegistrator1<IScenario*> mCBNeedSessionDonorByClientKey;
    // при вызове DelayBegin или при (Begin()==true)
    // сценарий активировался и начался обмен пакетами
    // это нужно учесть в статистике
    TCallBackRegistrator1<IScenario*>   mCBActivate;
    // если с Донором разорвется соединение, то Мастер сообщит о разрыве связи с Клиентом на Реципиенте
    // и он должен уничтожить информацию о Клиенте
    TCallBackRegistrator1<unsigned int> mCBDisconnectByClientKey;

    // по структуре, описывающей запрос на соединение со стороны Клиента
    TCallBackRegistrator1<TDescRequestConnectForRecipient*> mCBNeedContextByRequestForRecipient;
    // время ожидания ответа от Клиента на Slave истекло
    TCallBackRegistrator1<unsigned int> mCBTimeClientElapsed;

    TScRecommutationClient_ClientImpl mClient;
    TScRecommutationClient_SlaveImpl  mSlave;// Donor/Recipient
    TScRecommutationClient_MasterImpl mMaster;

    TBaseScRecommutationClient*       mCurBehavior;
  public:
    enum eTypeCallBack
    {
      eNeedContextByClientKeyForSlave = IScenario::eCountCallBack,
      eNeedContextByClientSessionForSlave,
      eNeedSessionDonor,
      eEventActivate,
      eEventDisconnectClient,
      eEventTimeClientElapsed,
      eNeedContextByRequestForRecipient,
    };
  public:
    typedef enum
    {
      eClient,
      eSlave,
      eMaster,
    }eBehavior;

    TScenarioRecommutationClient();
    virtual ~TScenarioRecommutationClient();

    void SetBehavior( eBehavior v );
    virtual void Recv( TDescRecvSession* pDesc );
  public:
    void Start( unsigned int recipientSessionID, unsigned int clientKey );

    void SaveContext( void* data, int size );

    void DisconnectClient();

    void DisconnectFromClient( unsigned char subNet );

    void SetClientLoginPassword( std::string& login, std::string& password );

  protected:
    virtual void Work();
    virtual void DelayBegin();
  };
}
