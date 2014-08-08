/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef INetControl_H
#define INetControl_H

#include <list>

#include "GCS.h"

#include "BreakPacket.h"
#include "CallBackRegistrator.h"
#include "INetTransport.h"

class TNetTransport_Boost;

class INetControl
{
public:
  enum{
    eSystemSizeForRecvBuffer_Socket = 2000000, // байт
    eSystemSizeForSendBuffer_Socket = 2000000, // байт
  };

  INetControl();
  virtual ~INetControl();
  
  // TNetTransport_XXX
  virtual void Init() = 0;
  virtual bool Open( unsigned short port, unsigned char numNetWork = 0) = 0;
  virtual bool Connect(unsigned int ip, unsigned short port) = 0;              // blocking
  virtual void Send(unsigned int ip, unsigned short port, TBreakPacket bp) = 0;
	virtual void Close() = 0;

  virtual char* GetBuffer(){return NULL;}
  virtual int   GetSize(){return 0;}

  static void SetNetBoost(TNetTransport_Boost* pTB);
  static TCallBackRegistrator1<INetTransport::TDescRecv*>* GetCallbackRecv();
  static TCallBackRegistrator1<TIP_Port* >* GetCallbackDisconnect();
protected:
  static TNetTransport_Boost* GetNetBoost();

  void NotifyRecv(INetTransport::TDescRecv* p);
	void NotifyDisconnect(TIP_Port* p);
};

#endif