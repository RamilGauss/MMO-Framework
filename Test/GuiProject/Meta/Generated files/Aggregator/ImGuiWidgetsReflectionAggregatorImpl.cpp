/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_11_12 13:46:49.565
	
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
