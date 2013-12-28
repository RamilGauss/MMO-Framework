/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CONTEXT_SC_DISCONECT_SLAVE_H
#define CONTEXT_SC_DISCONECT_SLAVE_H

#include "IContextScenario.h"
#include "BreakPacket.h"
#include "ShareMisc.h"

namespace nsMMOEngine
{
  class TContextScDisconnectSlave : public IContextScenario
	{
	public:
		TContextScDisconnectSlave();
    virtual ~TContextScDisconnectSlave();
  private:
	};
}  
#endif