/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InputTextBuilderSystem.h"
#include "InputTextValueComponent.h"

#include <ImGuiWidgets/include/InputText.h>

#include "UnitBuilderHelper.h"

#include "TitleComponent.h"

#include "PrefabOriginalGuidComponent.h"
#include "SceneOriginalGuidComponent.h"

#include "Modules.h"
#include "HandlerCallCollector.h"

#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

// Prefab or scene
void TInputTextBuilderSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TInputTextComponent* pInputTextComponent)
{
    auto entMng = GetEntMng();

    TUnitBuilderHelper::SetupWidget(entMng, eid, pInputTextComponent->value);

    auto text = GetEntMng()->ViewComponent<TInputTextValueComponent>(eid)->value;
    pInputTextComponent->value->SetText(text);

    pInputTextComponent->value->mOnTextEditCB.Register((void*)pInputTextComponent, 
        [eid, entMng, pInputTextComponent](nsImGuiWidgets::TInputText* pInputText)
    {
        TInputTextValueComponent inputTextValueComponent;
        inputTextValueComponent.value = pInputText->GetText();
        entMng->SetComponent(eid, inputTextValueComponent, false);
    });
}
