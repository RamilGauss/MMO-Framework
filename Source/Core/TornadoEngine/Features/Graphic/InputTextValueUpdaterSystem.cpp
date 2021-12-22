/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputTextValueUpdaterSystem.h"
#include "InputTextComponent.h"

using namespace nsGraphicWrapper;

void TInputTextValueUpdaterSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TInputTextValueComponent* pC)
{
    GetEntMng()->ViewComponent<nsGuiWrapper::TInputTextComponent>(eid)->value->SetText(pC->value);
}
