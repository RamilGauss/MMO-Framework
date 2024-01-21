/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CameraUpdaterToModuleSystem.h"

#include "Components/Graphic/CameraComponent.h"
#include "Components/Graphic/CameraWindowSizeComponent.h"
#include "Components/Graphic/CameraWindowPositionComponent.h"

#include "Modules/Common/Modules.h"
#include "Modules/Implementations/GraphicEngineModule.h"

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
