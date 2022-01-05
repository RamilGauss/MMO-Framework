/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "OnMouseClickFileNodeHandler.h"

using namespace nsTornadoEditor;

void TOnMouseClickFileNodeHandler::Handle(nsECSFramework::TEntityID eid, const nsGraphicEngine::TMouseButtonEvent event)
{
    if (event.clicks != 2) {
        return;
    }

    if (event.button != nsGraphicEngine::MouseButton::LEFT) {
        return;
    }

    //TODO: open scene or prefab editing window
}