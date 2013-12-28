/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ISCENARIO_H
#define ISCENARIO_H

#include "SrcEvent.h"

#include "DescRecvSession.h"
#include "CallBackRegistrator.h"

#include "MapCallBack.h"

namespace nsMMOEngine
{
  class IContextScenario;
	class TManagerSession;
  class IScenario : public TMapCallBack
  {
		TCallBackRegistrator1<unsigned int> mCBNeedContextBySession;
    TCallBackRegistrator1<IScenario*>   mCBEnd;
    // запрос на контекст по ключу клиента
    TCallBackRegistrator1<unsigned int> mCBContextByClientKey;

    unsigned char mType;
  protected:
    IContextScenario* mCurContext;
  public:
    // типы CallBack
    enum
    {
      eContextBySession = 0,
      eEnd,
      eContextByClientKey,
      eCountCallBack,
    };

#if defined( WIN32 )
#pragma pack(push, 1)
#endif
    struct TBaseHeader{char type;char subType;};
#if defined( WIN32 )
#pragma pack(pop)
#endif
    IScenario();
    virtual ~IScenario();
    
    void SetContext(IContextScenario* pCSc);
    IContextScenario* GetContext();

		unsigned char GetType();
		void SetType(unsigned char type);

		virtual void Recv(TDescRecvSession* pDesc) = 0;
  protected:
    friend class IContextScenario;
    // если нельз€ было начать сценарий сразу, то когда будет така€ возможность произойдет этот вызов
    virtual void DelayBegin();
    // отработка своих событий и ожиданий
    virtual void Work();
  public:
    bool Begin();
    void End();
    // запрос на новую сессию, кто зарегистрировалс€ выставит контекст с помощью SetContext()
    void NeedContextBySession(unsigned int id_session);
    void NeedContextByClientKey(unsigned int id_client);
  };
}

#endif
