/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_09_05 10:11:15.980
	
#include "SystemReflectionAggregatorImpl.h"

#include "SystemTypeFactoryImpl.h"
#include "SystemDynamicCasterImpl.h"
#include "SystemTypeInformationImpl.h"

using namespace nsTornadoEditor;

TSystemReflectionAggregatorImpl::TSystemReflectionAggregatorImpl()
{
    mTypeFactory = new TSystemTypeFactoryImpl();
    mDynamicCaster = new TSystemDynamicCasterImpl();
    mTypeInfo = new TSystemTypeInformationImpl();
}
//--------------------------------------------------------------------------------------------------
TSystemReflectionAggregatorImpl::~TSystemReflectionAggregatorImpl()
{
    delete mTypeFactory;
    delete mDynamicCaster;
    delete mTypeInfo;
}
//--------------------------------------------------------------------------------------------------
