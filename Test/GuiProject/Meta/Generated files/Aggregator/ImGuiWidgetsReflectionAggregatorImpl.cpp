/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2024_11_28 13:52:42.149
#include "ImGuiWidgetsReflectionAggregatorImpl.h"

#include "ImGuiWidgetsDynamicCasterImpl.h"
#include "ImGuiWidgetsRttiImpl.h"

using namespace nsTornadoEditor;

TImGuiWidgetsReflectionAggregatorImpl::TImGuiWidgetsReflectionAggregatorImpl()
{
    mRtti = new TImGuiWidgetsRttiImpl();
    mDynamicCaster = new TImGuiWidgetsDynamicCasterImpl();
}
//--------------------------------------------------------------------------------------------------
TImGuiWidgetsReflectionAggregatorImpl::~TImGuiWidgetsReflectionAggregatorImpl()
{
    delete mRtti;
    delete mDynamicCaster;
}
//--------------------------------------------------------------------------------------------------
