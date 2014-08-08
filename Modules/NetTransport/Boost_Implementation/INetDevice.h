/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef INetDeviceH
#define INetDeviceH

#include "ShareMisc.h"

class INetDevice
{
protected:
  TIP_Port mIP_Port;
public:

  INetDevice(){};
  virtual ~INetDevice(){};

  virtual bool Open( unsigned short port, unsigned char numNetWork = 0 ) = 0;
  virtual void Close() = 0;

	virtual bool SetRecvBuffer(unsigned int size) = 0;
	virtual bool SetSendBuffer(unsigned int size) = 0;

  TIP_Port* GetIP_Port(){return &mIP_Port;}
  void SetIP_Port(TIP_Port& ip_port){mIP_Port = ip_port;}
};


#endif