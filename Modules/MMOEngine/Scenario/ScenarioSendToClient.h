/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SCENARIO_SEND_TO_CLIENT_H
#define SCENARIO_SEND_TO_CLIENT_H

#include "IScenario.h"
#include "ContextScSendToClient.h"
#include "MakerScenario.h"

#include <boost/foreach.hpp>

#if defined( TD_WINDOWS )
#pragma pack(push, 1)
#endif

namespace nsMMOEngine
{
  class TScenarioSendToClient : public IScenario
  {
    enum
		{
			eSuperServer,
			eMaster,
			eSlave,
		};
		//-------------------------------------------------
    struct THeader : public IScenario::TBaseHeader
    {
      THeader(){type = TMakerScenario::eSendToClient;id_client=0;}
      unsigned int id_client;
    };
    //==================================================================
    struct THeaderSuperServer : public THeader
    {
      THeaderSuperServer(){subType = eSuperServer;}
    };
    //-------------------------------------------------
    struct THeaderMaster : public THeader
    {
      THeaderMaster(){subType = eMaster;}
    };
    //-------------------------------------------------
		struct THeaderSlave : public THeader
		{
			THeaderSlave(){subType = eSlave;}
		};
		//-------------------------------------------------
  public:
    TScenarioSendToClient();
    virtual ~TScenarioSendToClient();
    
    virtual void Recv(TDescRecvSession* pDesc);
  public:
    void SendFromSuperServer(std::list<unsigned int>& lKey, TBreakPacket bp);
    void SendFromMaster(std::list<unsigned int>& lKey, TBreakPacket bp);
    void SendFromSlave(std::list<unsigned int>& lKey, TBreakPacket bp);
  protected:

    void RecvFromSuperServer(TDescRecvSession* pDesc);
    void RecvFromMaster(TDescRecvSession* pDesc);
    void RecvFromSlave(TDescRecvSession* pDesc);

  protected:
    TContextScSendToClient* Context(){return (TContextScSendToClient*)mCurContext;}
    virtual void DelayBegin();		
	private:
		template <class T>
		void SendAll(std::list<unsigned int>& lKey, TBreakPacket& bp);

		template <class T>
		void Send(unsigned int id_client, TBreakPacket bp);
  };
	//------------------------------------------------------------------------------
	template <class T>
	void TScenarioSendToClient::Send(unsigned int id_client, TBreakPacket bp)
	{
		T h;
		h.id_client = id_client;
		bp.PushFront((char*)&h, sizeof(h));

		unsigned int id_session = Context()->GetID_Session();
		Context()->GetMS()->Send(id_session, bp);
	}
	//------------------------------------------------------------------------------
	template <class T>
	void TScenarioSendToClient::SendAll(std::list<unsigned int>& lKey, TBreakPacket& bp)
	{
		if(bp.GetSize()==0)
			return;// нельз€ передавать нулевые пакеты
		BOOST_FOREACH(unsigned int id_client, lKey)
		{
			NeedContextByClientKey(id_client);
			if(Context())
			{
				if(Begin()==false)
				{
          TBreakPacket bpForSave;
          bpForSave = bp;
					T h;
					h.id_client = id_client;
					bpForSave.PushFront((char*)&h, sizeof(h));
					// пока отослать нельз€, сохранить пакет до момента возможности
					Context()->SaveBreakPacket(bpForSave);
					continue;
				}
				Send<T>(id_client, bp);
				End();
			}
		}
	}
	//-------------------------------------------------------------------
}

#if defined( TD_WINDOWS )
#pragma pack(pop)
#endif

#endif