/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "MMOEngine/SubSystem/BaseMasterLogic.h"

namespace nsMMOEngine
{
    class IScenario;
    class TRCMLogic : public TBaseMasterLogic
    {
    public:
        TRCMLogic(TBase* p);

        void EndRcm(IScenario* pSc);
        void NeedContextByClientKeyRcm(unsigned int clientKey);
        void NeedSlaveSessionDonorRcm(IScenario* pSc);
        void EventActivateRcm(IScenario* pSc);
    };
}
