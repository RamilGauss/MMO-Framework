/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/MenuNode.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/PropertyManager/PropertyManager.h"

#include "TornadoEngine/Features/Graphic/Begin/Maker/Units/MenuNodeMakerSystem.h"

using namespace nsGraphicWrapper;

void TMenuNodeMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pMenuNodeComponent)
{
    auto pMenuNode = new nsImGuiWidgets::TMenuNode();
    pMenuNodeComponent->value = pMenuNode;

    nsTornadoEngine::Modules()->PropertyMng()->SetupProperties(GetEntMng(), eid, pMenuNode);
}
