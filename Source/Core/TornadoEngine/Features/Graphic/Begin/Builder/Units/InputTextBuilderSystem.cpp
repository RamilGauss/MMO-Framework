/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputTextBuilderSystem.h"

#include <ImGuiWidgets/include/InputText.h>

#include "Components/Gui/Properties/InputTextValueComponent.h"
#include "Components/Gui/Properties/TitleComponent.h"

#include "Components/Meta/PrefabOriginalGuidComponent.h"
#include "Components/Meta/SceneOriginalGuidComponent.h"

#include "Modules/Common/Modules.h"
#include "Modules/Resources/Common/HandlerCallCollector.h"

#include "Features/Graphic/Begin/Builder/Helpers/HandlerLinkHelper.h"
#include "Features/Graphic/Begin/Builder/Helpers/UnitBuilderHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TInputTextBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TInputTextComponent* pInputTextComponent)
{
    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupWidget(entMng, eid, pInputTextComponent->value);

    auto text = GetEntMng()->ViewComponent<TInputTextValueComponent>(eid)->value;
    pInputTextComponent->value->SetInputTextValue(text);

    pInputTextComponent->value->mOnTextEditCB.Register((void*)pInputTextComponent, 
        [eid, entMng, pInputTextComponent](nsImGuiWidgets::TInputText* pInputText)
    {
        TInputTextValueComponent inputTextValueComponent;
        inputTextValueComponent.value = pInputText->GetInputTextValue();
        entMng->SetComponent(eid, inputTextValueComponent);
    });
}
