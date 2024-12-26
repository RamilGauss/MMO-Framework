/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2024_12_26 15:38:39.901
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
