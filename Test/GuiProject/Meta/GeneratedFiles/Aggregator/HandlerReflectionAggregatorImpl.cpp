/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "HandlerReflectionAggregatorImpl.h"

#include "HandlerTypeFactoryImpl.h"
#include "HandlerTypeInformationImpl.h"
#include "HandlerRttiImpl.h"

using namespace nsGuiProject;

THandlerReflectionAggregatorImpl::THandlerReflectionAggregatorImpl()
{
    mTypeFactory = std::make_shared<THandlerTypeFactoryImpl>();
    mRtti = std::make_shared<THandlerRttiImpl>();
    mTypeInfo = std::make_shared<THandlerTypeInformationImpl>();
}
//--------------------------------------------------------------------------------------------------
THandlerReflectionAggregatorImpl::~THandlerReflectionAggregatorImpl()
{
}
//--------------------------------------------------------------------------------------------------