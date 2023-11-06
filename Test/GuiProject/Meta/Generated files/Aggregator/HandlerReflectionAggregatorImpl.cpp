/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_11_06 17:11:52.315
	
#include "HandlerReflectionAggregatorImpl.h"

#include "HandlerTypeFactoryImpl.h"
#include "HandlerTypeInformationImpl.h"
#include "HandlerRttiImpl.h"

using namespace nsTornadoEditor;

THandlerReflectionAggregatorImpl::THandlerReflectionAggregatorImpl()
{
    mTypeFactory = new THandlerTypeFactoryImpl();
    mRtti = new THandlerRttiImpl();
    mTypeInfo = new THandlerTypeInformationImpl();
}
//--------------------------------------------------------------------------------------------------
THandlerReflectionAggregatorImpl::~THandlerReflectionAggregatorImpl()
{
    delete mTypeFactory;
    delete mRtti;
    delete mTypeInfo;
}
//--------------------------------------------------------------------------------------------------