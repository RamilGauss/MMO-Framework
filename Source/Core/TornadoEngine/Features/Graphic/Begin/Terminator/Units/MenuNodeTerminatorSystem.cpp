/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/MenuNode.h"

#include "TornadoEngine/Components/Meta/GuidComponent.h"
#include "TornadoEngine/Components/Meta/ParentGuidComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/FrameComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/WindowComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/FrameComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/DialogComponent.h"

#include "TornadoEngine/Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"
#include "TornadoEngine/Features/Graphic/Begin/Terminator/Units/MenuNodeTerminatorSystem.h"

using namespace nsGraphicWrapper;

void TMenuNodeTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pMenuNodeComponent)
{
    TUnitBuilderHelper::UnlinkMenuNode(GetEntMng(), eid, pMenuNodeComponent->value);

    delete pMenuNodeComponent->value;
    pMenuNodeComponent->value = nullptr;
}
