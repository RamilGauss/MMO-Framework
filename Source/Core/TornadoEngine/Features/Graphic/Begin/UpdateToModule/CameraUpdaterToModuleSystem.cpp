/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/UpdateToModule/CameraUpdaterToModuleSystem.h"

#include "TornadoEngine/Components/Graphic/CameraComponent.h"
#include "TornadoEngine/Components/Graphic/CameraWindowSizeComponent.h"
#include "TornadoEngine/Components/Graphic/CameraWindowPositionComponent.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Implementations/GraphicEngineModule.h"

using namespace nsGraphicWrapper;

void TCameraUpdaterToModuleSystem::Execute()
{
    auto pGE = nsTornadoEngine::Modules()->G()->GetGE();
    auto width = pGE->GetWidth();
    auto height = pGE->GetHeight();

    auto cameraEids = GetEntMng()->GetByHasCopy<TCameraComponent>();

    for (auto& eid : cameraEids) {
        auto pCamera = GetEntMng()->ViewComponent<TCameraComponent>(eid)->value;

        auto pWinPosComponent = GetEntMng()->ViewComponent<TCameraWindowPositionComponent>(eid);
        auto pWinSizeComponent = GetEntMng()->ViewComponent<TCameraWindowSizeComponent>(eid);

        auto x = pWinPosComponent->x * width;
        auto y = pWinPosComponent->y * height;

        auto w = pWinSizeComponent->x * width;
        auto h = pWinSizeComponent->y * height;

        pCamera->SetWindowPosition({x, y});
        pCamera->SetWindowSize({w, h});
    }
}
