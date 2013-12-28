/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CONTEXT_SC_SYNCHRO_SLAVE_H
#define CONTEXT_SC_SYNCHRO_SLAVE_H

#include "IContextScenario.h"
#include "BreakPacket.h"

namespace nsMMOEngine
{
  // сценарии, содержащиеся в контейнере взаимно блокируются
  class TContextScSynchroSlave : public IContextScenario
	{
    unsigned char mLoadProcent;
	public:
		TContextScSynchroSlave();
    virtual ~TContextScSynchroSlave();

    void SetLoadProcent(unsigned char v);
    unsigned char GetLoadProcent();
  private:
	};
}  
#endif