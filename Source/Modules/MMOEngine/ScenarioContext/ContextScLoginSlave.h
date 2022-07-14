/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IScenarioContext.h"
#include "BreakPacket.h"
#include "ShareMisc.h"

namespace nsMMOEngine
{
    // сценарии, содержащиеся в контейнере взаимно блокируются
    class TContextScLoginSlave : public IScenarioContext
    {
        unsigned int mTimeWaitAnswerFromMaster;
        //bool flgConnectToMaster;
    public:
        TContextScLoginSlave();
        virtual ~TContextScLoginSlave();

        //void SetConnect( bool v );
        //bool IsConnect();

        unsigned int GetTimeWait();
        void SetTimeWait(unsigned int v);
    private:
    };
}
