/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CONTEXT_SC_LOGIN_SLAVE_H
#define CONTEXT_SC_LOGIN_SLAVE_H

#include "IContextScenario.h"
#include "BreakPacket.h"
#include "ShareMisc.h"

namespace nsMMOEngine
{
  // сценарии, содержащиеся в контейнере взаимно блокируются
  class TContextScLoginSlave : public IContextScenario
	{
    unsigned int mTimeWaitAnswerFromMaster;
    bool flgConnectToMaster;
	public:
		TContextScLoginSlave();
    virtual ~TContextScLoginSlave();

    void SetConnect(bool v);
    bool IsConnect();

    unsigned int GetTimeWait();
    void SetTimeWait(unsigned int v);
  private:
	};
}  
#endif