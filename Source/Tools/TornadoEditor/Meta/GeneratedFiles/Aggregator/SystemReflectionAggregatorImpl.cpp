/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:58.491
#include "SystemReflectionAggregatorImpl.h"

#include "SystemTypeFactoryImpl.h"
#include "SystemDynamicCasterImpl.h"
#include "SystemRttiImpl.h"

using namespace nsTornadoEditor;

TSystemReflectionAggregatorImpl::TSystemReflectionAggregatorImpl()
{
    mTypeFactory = new TSystemTypeFactoryImpl();
    mDynamicCaster = new TSystemDynamicCasterImpl();
    mRtti = new TSystemRttiImpl();
}
//--------------------------------------------------------------------------------------------------
TSystemReflectionAggregatorImpl::~TSystemReflectionAggregatorImpl()
{
    delete mTypeFactory;
    delete mDynamicCaster;
    delete mRtti;
}
//--------------------------------------------------------------------------------------------------
