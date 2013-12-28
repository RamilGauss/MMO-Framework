/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BASE_SC_RECOMMUTATION_CLIENT_STRUCT_H
#define BASE_SC_RECOMMUTATION_CLIENT_STRUCT_H

#include "IScenario.h"
#include "DescRecvSession.h"
#include <time.h>

#ifdef WIN32
#pragma pack(push, 1)
#endif

namespace nsMMOEngine
{
  struct TDescRequestConnectForRecipient
  {
    unsigned int key;
    unsigned int random_num;
    unsigned int id_session;
    TDescRequestConnectForRecipient()
    {
      key        = 0;
      random_num = 0;
      id_session = 0;
    }
    void Generate()
    {
      srand( (unsigned)time( NULL ) );
      short* pShort = (short*)&random_num;
      pShort[0] = rand();
      pShort[1] = rand();
    }
  };

  namespace nsRecommutationClientStruct
  {
    enum
    {
      eBeginDonor,
      eBeginClient,
      eCheckBeginClient,
      eCheckBeginDonor,
      eBeginRecipient,
      eCheckBeginRecipient,
      eInfoRecipientToDonor,
      eInfoRecipientToClient,
      eCheckInfoRecipient,
      eRequestConnect,
      eCheckRequestConnect,
      eClientConnect,
      //-------------------------
      eDisconnectClient,
    };
    enum
    {
      eClient,
      eSlaveDonor,
      eSlaveRecipient,
      eMaster,
    };
    //-------------------------------------------------
    struct THeader : public IScenario::TBaseHeader
    {
      THeader();
      unsigned char from;
      unsigned int  id_client;
    };
	  //-------------------------------------------------
    struct THeaderC  : public THeader{ THeaderC (){from=eClient;}};
    struct THeaderM  : public THeader{ THeaderM (){from=eMaster;}};
    struct THeaderSD : public THeader{ THeaderSD (){from=eSlaveDonor;}};
    struct THeaderSR : public THeader{ THeaderSR (){from=eSlaveRecipient;}};
    //-------------------------------------------------
	  struct THeaderBeginDonor : THeaderM
	  {
      THeaderBeginDonor();
	  };
	  //-------------------------------------------------
    struct THeaderBeginClient : THeaderSD
    {
      THeaderBeginClient();
    };
    //-------------------------------------------------
    struct THeaderCheckBeginClient : THeaderC
    {
      THeaderCheckBeginClient();
    };
    //-------------------------------------------------
    struct THeaderCheckBeginDonor : THeaderSD
    {
      THeaderCheckBeginDonor();
    };
    //-------------------------------------------------
    struct THeaderBeginRecipient : THeaderM
    {
      THeaderBeginRecipient();
      unsigned int random_num;
    };
    //-------------------------------------------------
    struct THeaderCheckBeginRecipient : THeaderSR
    {
      THeaderCheckBeginRecipient();
    };
    //-------------------------------------------------
    struct THeaderInfoRecipientToDonor : THeaderM
    {
      THeaderInfoRecipientToDonor();
      TIP_Port ip_port_recipient;
      unsigned int random_num;
    };
    //-------------------------------------------------
    struct THeaderInfoRecipientToClient : THeaderSD
    {
      THeaderInfoRecipientToClient();
      TIP_Port ip_port_recipient;
      unsigned int random_num;
    };
    //-------------------------------------------------
    struct THeaderCheckInfoRecipient : THeaderC
    {
      THeaderCheckInfoRecipient();
    };
    //-------------------------------------------------
    struct THeaderRequestConnect : THeaderC
    {
      THeaderRequestConnect();
      unsigned int random_num;
    };
    //-------------------------------------------------
    struct THeaderCheckRequestConnect : THeaderSR
    {
      THeaderCheckRequestConnect();
    };
    //-------------------------------------------------
    struct THeaderClientConnect : THeaderSR
    {
      THeaderClientConnect();
    };
    //-------------------------------------------------
    //-------------------------------------------------
    struct THeaderDisconnectClient : THeaderM
    {
      THeaderDisconnectClient();
    };
    //-------------------------------------------------
  }
}

#ifdef WIN32
#pragma pack(pop)
#endif

#endif
