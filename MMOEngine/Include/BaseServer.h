/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BASESERVER_H
#define BASESERVER_H

#include "Base.h"

namespace nsMMOEngine
{
  class MMO_ENGINE_EI TBaseServer : public TBase
  {

  public:
    TBaseServer();
    virtual ~TBaseServer();
    
    // this method will be realize in future
    virtual void DisconnectByKeyClient(unsigned int id_client);// = 0;

		// всегда с гарантией доставки, т.к. тогда не имеет смысла так долго пересылать (слишком много затрат сил, а гарантии нет?)
    virtual void SendByClientKey(std::list<unsigned int>& l, TBreakPacket bp) = 0;

    virtual void SendDown(unsigned int id_session, TBreakPacket bp, bool check = true) = 0;
    virtual int  GetCountDown() = 0;
    virtual bool GetDescDown(int index, void* pDesc, int& sizeDesc) = 0;

	protected:

	private:

  };
}

#endif