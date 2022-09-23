/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DialogMakerSystem.h"

#include <ImGuiWidgets/include/Dialog.h>

using namespace nsGraphicWrapper;

void TDialogMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogComponent* pDialogComponent)
{
    pDialogComponent->value = new nsImGuiWidgets::TDialog();
}
