/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
I
#include <string>

#include "TornadoEngine/Handlers/Common/IGlobalHandler.h"

#include "ECS/Include/Config.h"

namespace nsLogicWrapper
{
    class DllExport ISceneInstantiationCompletionHandler : public nsTornadoEngine::IGlobalHandler
    {
    public:
        virtual void Handle(nsECSFramework::TEntityID eid, const std::string& sceneIstanceGuid, const std::string& tag) = 0;
    };
}
