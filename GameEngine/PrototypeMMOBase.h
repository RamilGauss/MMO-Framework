/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeMMOBaseH
#define PrototypeMMOBaseH

#include "PrototypeBaseModule.h"
#include "PrototypeMMOStructs.h"
#include "ShareMisc.h"
#include "BreakPacket.h"

#define MMO_INVALID_HANDLE_SESSION 0

class DllExport PrototypeMMOBase : public PrototypeBaseModule
{
public:
  PrototypeMMOBase();
  virtual ~PrototypeMMOBase();

  virtual bool Open(PrototypeMMODescOpen* pDesc, int count = 1) = 0;
  virtual void DisconnectUp() = 0;
  virtual void SendUp(TBreakPacket bp, bool check = true) = 0;
  virtual bool IsConnectUp() = 0;
  virtual bool IsConnect(unsigned int id) = 0;
  virtual void SetLoad(int procent) = 0;
  virtual void SetTimeLiveSession(unsigned int time_ms) = 0;
  virtual bool GetInfoSession(unsigned int id_session, TIP_Port& ip_port) = 0;
  //===========================================================================
	virtual int GetVersionPrototype();
};

#endif
