/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/BreakPacket.h"

#include "MMOEngine/SubSystem/IScenarioContext.h"

namespace nsMMOEngine
{
    // сценарии, содержащиеся в контейнере взаимно блокируются
    class TContextScLoginMaster : public IScenarioContext
    {
        unsigned int mTimeWait;
    public:
        TContextScLoginMaster();
        virtual ~TContextScLoginMaster();

        void SetTimeWait(unsigned int v);
        unsigned int GetTimeWait();

    private:
    };
}
