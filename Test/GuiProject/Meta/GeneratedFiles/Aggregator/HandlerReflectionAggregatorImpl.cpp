/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "GuiProject/Meta/GeneratedFiles/Aggregator/HandlerReflectionAggregatorImpl.h"

#include "GuiProject/Meta/GeneratedFiles/Aggregator/HandlerTypeFactoryImpl.h"
#include "GuiProject/Meta/GeneratedFiles/Aggregator/HandlerTypeInformationImpl.h"
#include "GuiProject/Meta/GeneratedFiles/Aggregator/HandlerRttiImpl.h"

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