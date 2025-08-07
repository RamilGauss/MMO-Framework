/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "SystemReflectionAggregatorImpl.h"

#include "SystemTypeFactoryImpl.h"
#include "SystemDynamicCasterImpl.h"
#include "SystemRttiImpl.h"

using namespace nsTornadoEditor;

TSystemReflectionAggregatorImpl::TSystemReflectionAggregatorImpl()
{
    mTypeFactory = std::make_shared<TSystemTypeFactoryImpl>();
    mDynamicCaster = std::make_shared<TSystemDynamicCasterImpl>();
    mRtti = std::make_shared<TSystemRttiImpl>();
}
//--------------------------------------------------------------------------------------------------
