/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IFrameMouseClickHandler.h"
#include "ProjectConfig.h"

namespace nsTornadoEditor
{
    class DllExport TOnMouseClickFileNodeHandler : public nsGuiWrapper::IFrameMouseClickHandler
    {
    public:
        void Handle(nsECSFramework::TEntityID eid, const nsGraphicEngine::TMouseButtonEvent event) override;
    };
}