/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SC_RECOMMUTATION_CLIENT_CLIENT_IMPL_H
#define SC_RECOMMUTATION_CLIENT_CLIENT_IMPL_H

#include "BaseScRecommutationClient.h"

namespace nsMMOEngine
{
  class TScRecommutationClient_ClientImpl : public TBaseScRecommutationClient
  {
  protected:
    enum
    {
      eTimeWait = 10000,
    };

  public:
	  TScRecommutationClient_ClientImpl(IScenario* pSc);

    virtual void Work(unsigned int time_ms);

    void DisconnectClient(unsigned char subNet);
  protected:
    virtual void RecvInherit(TDescRecvSession* pDesc);

  private:
    void RecvFromSlaveDonor(TDescRecvSession* pDesc);
    void RecvFromSlaveRecipient(TDescRecvSession* pDesc);
  private:
    void BeginClient(TDescRecvSession* pDesc);
    void InfoRecipientToClient(TDescRecvSession* pDesc);
    void CheckRequestConnect(TDescRecvSession* pDesc);
  private:
  };
}
#endif
