/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/BreakPacket.h"
#include "Base/Common/ShareMisc.h"

#include "MMOEngine/SubSystem/IScenarioContext.h"

namespace nsMMOEngine
{
    class TContextScDisconnectClient : public IScenarioContext
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