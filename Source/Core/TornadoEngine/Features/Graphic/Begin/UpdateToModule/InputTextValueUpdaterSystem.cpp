/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/UpdateToModule/InputTextValueUpdaterSystem.h"
#include "TornadoEngine/Components/Gui/Widgets/InputTextComponent.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;
using namespace std::placeholders;

void TInputTextValueUpdaterSystem::Init()
{
    Add(std::bind(&TInputTextValueUpdaterSystem::SetInputTextValue<TInputTextComponent>, this, _1, _2));
}
//--------------------------------------------------------------------------------------------------------------------------
void TInputTextValueUpdaterSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TInputTextValueComponent* pC)
{
    HandleByPool(eid, pC);
}
//--------------------------------------------------------------------------------------------------------------------------
