/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "UnitBuilderHelper.h"

#include "GuidComponent.h"
#include "ParentGuidComponent.h"
#include "PositionComponent.h"
#include "SizeComponent.h"
#include "TitleComponent.h"

#include "MainWindowComponent.h"
#include "WindowComponent.h"
#include "DialogComponent.h"
#include "FrameComponent.h"

using namespace nsGraphicWrapper;

void TUnitBuilderHelper::SetupButton(nsECSFramework::TEntityManager* entMng,
    nsECSFramework::TEntityID eid, const nsGuiWrapper::TButtonComponent* pButtonComponent)
{
    auto posComponent = entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid);
    pButtonComponent->value->SetPos({(float) posComponent->x,(float) posComponent->y});

    auto sizeComponent = entMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid);
    pButtonComponent->value->SetSize({(float) sizeComponent->x,(float) sizeComponent->y});

    auto parentGuid = entMng->ViewComponent<nsCommonWrapper::TParentGuidComponent>(eid)->value;

    nsCommonWrapper::TGuidComponent guidComponent;
    guidComponent.value = parentGuid;
    auto parentEid = entMng->GetByUnique(guidComponent);
    if (parentEid == nsECSFramework::NONE) {
        return;
    }

    AddWidgetToParent(entMng, parentEid, pButtonComponent->value);
}
//-----------------------------------------------------------------------------------------------------------------------
void TUnitBuilderHelper::AddWidgetToParent(nsECSFramework::TEntityManager* entMng, nsECSFramework::TEntityID parentEid,
    nsImGuiWidgets::TWidget* pWidget)
{
    auto isFrame = entMng->HasComponent<nsGuiWrapper::TFrameComponent>(parentEid);
    if (isFrame) {
        auto pFrameComponent = entMng->ViewComponent<nsGuiWrapper::TFrameComponent>(parentEid);
        pFrameComponent->value->Add(pWidget);
        return;
    }
    auto isDialog = entMng->HasComponent<nsGuiWrapper::TDialogComponent>(parentEid);
    if (isDialog) {
        auto pDialogComponent = entMng->ViewComponent<nsGuiWrapper::TDialogComponent>(parentEid);
        pDialogComponent->value->Add(pWidget);
        return;
    }
    auto isWindow = entMng->HasComponent<nsGuiWrapper::TWindowComponent>(parentEid);
    if (isWindow) {
        auto pWindowComponent = entMng->ViewComponent<nsGuiWrapper::TWindowComponent>(parentEid);
        pWindowComponent->value->Add(pWidget);
        return;
    }
    auto isMainWindow = entMng->HasComponent<nsGuiWrapper::TMainWindowComponent>(parentEid);
    if (isMainWindow) {
        auto pMainWindowComponent = entMng->ViewComponent<nsGuiWrapper::TMainWindowComponent>(parentEid);
        pMainWindowComponent->value->Add(pWidget);
        return;
    }

    BL_FIX_BUG();
}
//-----------------------------------------------------------------------------------------------------------------------
