/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef ScenarioStressTestClientH
#define ScenarioStressTestClientH

#include "InputCmdTestMMO_Client.h"
#include "MakerNetTransport.h"
#include "BehaviourClient.h"
#include <vector>

class TScenarioStressTestClient
{

    enum
    {
        eWaitForConnect = 1500,
    };

    TInputCmdTestMMO_Client mInputCmd;
    TInputCmdTestMMO_Client::TInput mInputArg;
    TMakerNetTransport mMakerTransport;
    std::vector<TBehaviourClient*> pArrClient;
public:
    void Init(int argc, char** argv);
    void Work();
};


#endif
