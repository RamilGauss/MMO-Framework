/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "WindowMakerSystem.h"

#include <ImGuiWidgets/include/Window.h>

#include "TimeSliceEngine/ProjectConfigContainer.h"

#include "SizeComponent.h"
#include "PositionComponent.h"

#include "VisibilityComponent.h"
#include "TitleComponent.h"

#include "AnchorsComponent.h"
#include "MinSizeComponent.h"
#include "MaxSizeComponent.h"
#include "VerticalAlignComponent.h"
#include "HorizontalAlignComponent.h"
#include "MinDistanceToParentComponent.h"
#include "FocusComponent.h"

#include "PaddingComponent.h"
#include "GridComponent.h"
#include "SpacingComponent.h"

using namespace nsGraphicWrapper;

void TWindowMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TWindowComponent* pWindowComponent)
{
    auto pWindow = new nsImGuiWidgets::TWindow();
    pWindowComponent->value = pWindow;

    auto entMng = GetEntMng();

    auto componentReflection = nsTornadoEngine::Project()->mScenePartAggregator->mComponents;
    componentReflection->mEntMng->SetEntityManager(mEntMng);

    auto imGuiWidgetsReflection = nsTornadoEngine::Project()->mScenePartAggregator->mImGuiWidgets;

    {
        int srcRtti;
        componentReflection->mTypeInfo->ConvertNameToType("nsGuiWrapper::TTitleComponent", srcRtti);

        int dstRtti;
        componentReflection->mTypeInfo->ConvertNameToType("nsTornadoEngine::IPropertyOf", dstRtti);

        void* pC = (void*)componentReflection->mEntMng->ViewComponent(eid, srcRtti);

        auto propertyOf = (nsTornadoEngine::IPropertyOf*)componentReflection->mDynamicCaster->Cast(srcRtti, pC, dstRtti);

        int windowRtti;
        imGuiWidgetsReflection->mTypeInfo->ConvertNameToType("nsImGuiWidgets::TWindow", windowRtti);
        int targetRtti;
        imGuiWidgetsReflection->mTypeInfo->ConvertNameToType("nsImGuiWidgets::TTitle", targetRtti);
        auto targetPtr = imGuiWidgetsReflection->mDynamicCaster->Cast(windowRtti, pWindow, targetRtti);

        propertyOf->SetOwner(targetPtr);
    }



    entMng->ViewComponent<nsGuiWrapper::TTitleComponent>(eid)->SetOwner(pWindow);
    entMng->ViewComponent<nsGuiWrapper::TVisibilityComponent>(eid)->SetOwner(pWindow);
    entMng->ViewComponent<nsGuiWrapper::TSizeComponent>(eid)->SetOwner(pWindow);
    entMng->ViewComponent<nsGuiWrapper::TPositionComponent>(eid)->SetOwner(pWindow);

    entMng->ViewComponent<nsGuiWrapper::TAnchorsComponent>(eid)->SetOwner(pWindow);
    entMng->ViewComponent<nsGuiWrapper::TMinSizeComponent>(eid)->SetOwner(pWindow);
    entMng->ViewComponent<nsGuiWrapper::TMaxSizeComponent>(eid)->SetOwner(pWindow);
    entMng->ViewComponent<nsGuiWrapper::TVerticalAlignComponent>(eid)->SetOwner(pWindow);
    entMng->ViewComponent<nsGuiWrapper::THorizontalAlignComponent>(eid)->SetOwner(pWindow);
    entMng->ViewComponent<nsGuiWrapper::TMinDistanceToParentComponent>(eid)->SetOwner(pWindow);
    entMng->ViewComponent<nsGuiWrapper::TFocusComponent>(eid)->SetOwner(pWindow);

    entMng->ViewComponent<nsGuiWrapper::TPaddingComponent>(eid)->SetOwner(pWindow);
    entMng->ViewComponent<nsGuiWrapper::TGridComponent>(eid)->SetOwner(pWindow);
    entMng->ViewComponent<nsGuiWrapper::TSpacingComponent>(eid)->SetOwner(pWindow);

    entMng->ViewComponent<nsGuiWrapper::TGridComponent>(eid)->SetOwner(pWindow);
}
