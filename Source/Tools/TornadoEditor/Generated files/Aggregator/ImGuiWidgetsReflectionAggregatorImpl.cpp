/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_03_30 15:33:35.569
	
#include "ImGuiWidgetsReflectionAggregatorImpl.h"

#include "ImGuiWidgetsTypeInfoImpl.h"
#include "ImGuiWidgetsDynamicCasterImpl.h"

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