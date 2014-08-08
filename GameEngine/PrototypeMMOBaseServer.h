/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeMMOBaseServerH
#define PrototypeMMOBaseServerH

#include "PrototypeMMOBase.h"

class DllExport PrototypeMMOBaseServer : public PrototypeMMOBase
{
public:
  PrototypeMMOBaseServer();
  virtual ~PrototypeMMOBaseServer();
  // проверить на доверие сессию
  virtual bool IsSessionSecurity(unsigned int id_session, void* crypt, int size_crypt, 
    void* login_password, int size_login_password) = 0;
  // this method will be realize in future
  virtual void DisconnectByKeyClient(unsigned int id_client) = 0;
  // всегда с гарантией доставки, т.к. тогда не имеет смысла так долго пересылать (слишком много затрат сил, а гарантии нет?)
  virtual void SendByClientKey(std::list<unsigned int>& l, TBreakPacket bp) = 0;

  virtual void SendDown(unsigned int id_session, TBreakPacket bp, bool check = true) = 0;
  virtual int  GetCountDown() = 0;
  virtual bool GetDescDown(int index, void* pDesc, int& sizeDesc) = 0;
};

#endif
