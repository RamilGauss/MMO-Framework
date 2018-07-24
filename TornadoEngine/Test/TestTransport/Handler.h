/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "DataExchange2Thread.h"
#include "ShareMisc.h"

class THandler
{
  int count_recv;

  nsMMOEngine::INetTransport* mTransport = nullptr;
public:
  TDataExchange2Thread<TIP_Port> mListDisc;

  THandler( nsMMOEngine::INetTransport* pTransport )
  {
    count_recv = 0;
    mTransport = pTransport;
  }

  ~THandler()
  {
    int a = 0;
  }

  void Recv( nsMMOEngine::INetTransport::TDescRecv* p )
  {
    count_recv++;
    printf( "Recv event from %u\n", p->ip_port.port );
    //if( count_recv == 1 )
      //mTransport->Close( p->ip_port.ip, p->ip_port.port );
  }
  void Disconnect( TIP_Port* p )
  {
    printf( "Disconnect event from %u\n", p->port );

    TIP_Port* pNew = new TIP_Port;
    *pNew = *p;
    mListDisc.Add( pNew );
  }

  void ConnectFrom( TIP_Port* p )
  {
    printf( "ConnectFrom event from %u\n", p->port );
  }
};
