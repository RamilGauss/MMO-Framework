/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnRemoveInstantReactiveSystem.h"

#include "TornadoEngine/Components/Graphic/TextureFromFileComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TTextureTerminatorSystem :
        public nsECSFramework::TOnRemoveInstantReactiveSystem<nsGraphicWrapper::TTextureFromFileComponent, TTextureTerminatorSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGraphicWrapper::TTextureFromFileComponent* pC);
    };
}