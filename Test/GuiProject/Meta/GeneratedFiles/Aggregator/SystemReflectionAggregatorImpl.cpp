/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "GuiProject/Meta/GeneratedFiles/Aggregator/SystemReflectionAggregatorImpl.h"

#include "GuiProject/Meta/GeneratedFiles/Aggregator/SystemTypeFactoryImpl.h"
#include "GuiProject/Meta/GeneratedFiles/Aggregator/SystemDynamicCasterImpl.h"
#include "GuiProject/Meta/GeneratedFiles/Aggregator/SystemRttiImpl.h"

using namespace nsGuiProject;

TSystemReflectionAggregatorImpl::TSystemReflectionAggregatorImpl()
{
    mTypeFactory = std::make_shared<TSystemTypeFactoryImpl>();
    mDynamicCaster = std::make_shared<TSystemDynamicCasterImpl>();
    mRtti = std::make_shared<TSystemRttiImpl>();
}
//--------------------------------------------------------------------------------------------------
TSystemReflectionAggregatorImpl::~TSystemReflectionAggregatorImpl()
{
}
//--------------------------------------------------------------------------------------------------
