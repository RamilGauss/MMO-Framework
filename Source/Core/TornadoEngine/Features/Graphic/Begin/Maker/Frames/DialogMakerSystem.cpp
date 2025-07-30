/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/Dialog.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/PropertyManager/PropertyManager.h"

#include "TornadoEngine/Features/Graphic/Begin/Maker/Frames/DialogMakerSystem.h"

using namespace nsGraphicWrapper;

void TDialogMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogComponent* pDialogComponent)
{
    auto pDialog = new nsImGuiWidgets::TDialog();
    pDialogComponent->value = pDialog;

    nsTornadoEngine::Modules()->PropertyMng()->SetupProperties(GetEntMng(), eid, pDialog);
}
