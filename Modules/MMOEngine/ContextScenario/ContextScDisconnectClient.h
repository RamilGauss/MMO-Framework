/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CONTEXT_SC_DISCONECT_CLIENT_H
#define CONTEXT_SC_DISCONECT_CLIENT_H

#include "IContextScenario.h"
#include "BreakPacket.h"
#include "ShareMisc.h"

namespace nsMMOEngine
{
  class TContextScDisconnectClient : public IContextScenario
	{
    unsigned int mIDClient;
	public:
		TContextScDisconnectClient();
    virtual ~TContextScDisconnectClient();

    unsigned int GetIDClient();
    void SetIDClient(unsigned int val);
  private:
	};
}  
#endif