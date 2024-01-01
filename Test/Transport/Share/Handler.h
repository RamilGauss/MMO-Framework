/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include "Base/Common/DataExchange2Thread.h"
#include "Base/Common/ShareMisc.h"
#include "Base/Common/ContainerTypes.h"
#include "MMOEngine/include/INetTransport.h"
#include "Packets.h"

struct THandler
{
  TDataExchange2Thread<TIP_Port> mConnectedList;
  TDataExchange2Thread<TIP_Port> mDisconnectedList;
  TDataExchange2Thread<TContainer> mRecvList;

  void Recv( nsMMOEngine::INetTransport::TDescRecv* p )
  {
    auto pPacket = (TBasePacket*)p->data;
    if ( pPacket->type == TBasePacket::eData )
      return;// пропуск

    TContainer* pPacketContainer = new TContainer();
    pPacketContainer->SetData( p->data, p->dataSize );
    mRecvList.Add( pPacketContainer );
  }
  void Disconnect( TIP_Port* p )
  {
    printf( "Disconnect event from %u\n", p->port );
    TIP_Port* pNew = new TIP_Port;
    *pNew = *p;
    mDisconnectedList.Add( pNew );
  }

  void ConnectFrom( TIP_Port* p )
  {
    printf( "ConnectFrom event from %u\n", p->port );
    TIP_Port* pNew = new TIP_Port;
    *pNew = *p;
    mConnectedList.Add( pNew );
  }
};
