/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MMOEngineIScenarioH
#define MMOEngineIScenarioH

#include "SrcEvent.h"

#include "DescRecvSession.h"
#include "CallBackRegistrator.h"

#include "MapCallBack.h"
#include "CryptMITM.h"

namespace nsMMOEngine
{
  class IScenarioContext;
  class TSessionManager;
  struct TDescRecvSession;
  class DllExport IScenario : public TMapCallBack
  {
    TCallBackRegistrator1<unsigned int> mCBNeedContextBySession;
    TCallBackRegistrator1<IScenario*>   mCBEnd;
    // запрос на контекст по ключу клиента
    TCallBackRegistrator1<unsigned int> mCBContextByClientKey;

    unsigned char mType;
  protected:
    IScenarioContext* mCurContext;
  protected:
    TBreakPacket mBP;
    TCryptMITM mCryptMITM;
  public:
    // типы CallBack
    enum
    {
      eContextBySession = 0,
      eEnd,
      eContextByClientKey,
      eCountCallBack,
    };
    IScenario();
    virtual ~IScenario();
    
    void SetContext(IScenarioContext* pCSc);
    IScenarioContext* GetContext();

    unsigned char GetType();
    void SetType(unsigned char type);

    virtual void Recv(TDescRecvSession* pDesc) = 0;
  protected:
    friend class IScenarioContext;
    // если нельзя было начать сценарий сразу, то когда будет такая возможность произойдет этот вызов
    virtual void DelayBegin();
    // отработка своих событий и ожиданий
    virtual void Work();
  public:
    bool Begin();
    void End();
    // запрос на новую сессию, кто зарегистрировался выставит контекст с помощью SetContext()
    void NeedContextBySession(unsigned int id_session);
    void NeedContextByClientKey(unsigned int id_client);
  };
}

#endif
