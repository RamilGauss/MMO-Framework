/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PositionUpdaterSystem.h"

#include "Components/Gui/Widgets/ButtonComponent.h"
#include "Components/Gui/Widgets/DialogComponent.h"
#include "Components/Gui/Widgets/FrameComponent.h"
#include "Components/Gui/Widgets/InputTextComponent.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;
using namespace std::placeholders;

void TPositionUpdaterSystem::Init()
{
    Add(std::bind(&TPositionUpdaterSystem::SetInputTextValue<TButtonComponent>, this, _1, _2));
    Add(std::bind(&TPositionUpdaterSystem::SetInputTextValue<TDialogComponent>, this, _1, _2));
    Add(std::bind(&TPositionUpdaterSystem::SetInputTextValue<TFrameComponent>, this, _1, _2));
    Add(std::bind(&TPositionUpdaterSystem::SetInputTextValue<TInputTextComponent>, this, _1, _2));
}
//--------------------------------------------------------------------------------------------------------------------------
void TPositionUpdaterSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TPositionComponent* pC)
{
    HandleByPool(eid, pC);
}
//--------------------------------------------------------------------------------------------------------------------------
