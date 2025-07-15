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
    class TContextScSynchroSlave : public IScenarioContext
    {
        float mLoadProcent;
    public:
        TContextScSynchroSlave();
        virtual ~TContextScSynchroSlave();

        void SetLoadProcent(float v);
        float GetLoadProcent();
    private:
    };
}
