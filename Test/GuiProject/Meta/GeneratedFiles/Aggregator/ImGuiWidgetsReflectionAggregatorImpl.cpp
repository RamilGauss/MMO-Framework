/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "GuiProject/Meta/GeneratedFiles/Aggregator/ImGuiWidgetsReflectionAggregatorImpl.h"

#include "GuiProject/Meta/GeneratedFiles/Aggregator/ImGuiWidgetsDynamicCasterImpl.h"
#include "GuiProject/Meta/GeneratedFiles/Aggregator/ImGuiWidgetsRttiImpl.h"

using namespace nsGuiProject;

TImGuiWidgetsReflectionAggregatorImpl::TImGuiWidgetsReflectionAggregatorImpl()
{
    mRtti = std::make_shared<TImGuiWidgetsRttiImpl>();
    mDynamicCaster = std::make_shared<TImGuiWidgetsDynamicCasterImpl>();
}
//--------------------------------------------------------------------------------------------------
TImGuiWidgetsReflectionAggregatorImpl::~TImGuiWidgetsReflectionAggregatorImpl()
{
}
//--------------------------------------------------------------------------------------------------
