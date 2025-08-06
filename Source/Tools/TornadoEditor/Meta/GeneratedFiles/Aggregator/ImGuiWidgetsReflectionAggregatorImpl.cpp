/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:58.491
#include "ImGuiWidgetsReflectionAggregatorImpl.h"

#include "ImGuiWidgetsDynamicCasterImpl.h"
#include "ImGuiWidgetsRttiImpl.h"

using namespace nsTornadoEditor;

TImGuiWidgetsReflectionAggregatorImpl::TImGuiWidgetsReflectionAggregatorImpl()
{
    mRtti = std::make_shared<TImGuiWidgetsRttiImpl>();
    mDynamicCaster = std::make_shared<TImGuiWidgetsDynamicCasterImpl>();
}
//--------------------------------------------------------------------------------------------------
