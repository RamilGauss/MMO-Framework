/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/UpdateToModule/TitleUpdaterSystem.h"

#include "TornadoEngine/Components/Gui/Widgets/ButtonComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/DialogComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/InputTextComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/MenuNodeComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/WindowComponent.h"
#include "TornadoEngine/Components/Gui/Widgets/TreeNodeComponent.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;
using namespace std::placeholders;

void TTitleUpdaterSystem::Init()
{
    Add(std::bind(&TTitleUpdaterSystem::SetTitle<TButtonComponent>, this, _1, _2));
    Add(std::bind(&TTitleUpdaterSystem::SetTitle<TDialogComponent>, this, _1, _2));
    Add(std::bind(&TTitleUpdaterSystem::SetTitle<TInputTextComponent>, this, _1, _2));
    Add(std::bind(&TTitleUpdaterSystem::SetTitle<TMenuNodeComponent>, this, _1, _2));
    Add(std::bind(&TTitleUpdaterSystem::SetTitle<TWindowComponent>, this, _1, _2));
    Add(std::bind(&TTitleUpdaterSystem::SetTitle<TTreeNodeComponent>, this, _1, _2));
}
//--------------------------------------------------------------------------------------------------------------------------
void TTitleUpdaterSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTitleComponent* pC)
{
    HandleByPool(eid, pC);
}
//--------------------------------------------------------------------------------------------------------------------------
