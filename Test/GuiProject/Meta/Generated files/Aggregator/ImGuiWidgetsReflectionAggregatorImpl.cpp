/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_10_08 13:49:45.902
	
#include "ImGuiWidgetsReflectionAggregatorImpl.h"

#include "ImGuiWidgetsDynamicCasterImpl.h"
#include "ImGuiWidgetsTypeInfoImpl.h"

using namespace nsTornadoEditor;

TImGuiWidgetsReflectionAggregatorImpl::TImGuiWidgetsReflectionAggregatorImpl()
{
    mTypeInfo = new TImGuiWidgetsTypeInfoImpl();
    mDynamicCaster = new TImGuiWidgetsDynamicCasterImpl();
}
//--------------------------------------------------------------------------------------------------
TImGuiWidgetsReflectionAggregatorImpl::~TImGuiWidgetsReflectionAggregatorImpl()
{
    delete mTypeInfo;
    delete mDynamicCaster;
}
//--------------------------------------------------------------------------------------------------
