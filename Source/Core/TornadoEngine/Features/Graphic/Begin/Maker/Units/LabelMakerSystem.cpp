/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "LabelMakerSystem.h"

#include <ImGuiWidgets/include/Label.h>

using namespace nsGraphicWrapper;

void TLabelMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TLabelComponent* pLabelComponent)
{
    pLabelComponent->value = new nsImGuiWidgets::TLabel();
}
