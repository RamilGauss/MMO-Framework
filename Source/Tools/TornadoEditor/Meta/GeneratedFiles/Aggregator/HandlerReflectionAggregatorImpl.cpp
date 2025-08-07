/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "TornadoEditor/Meta/GeneratedFiles/Aggregator/HandlerReflectionAggregatorImpl.h"

#include "TornadoEditor/Meta/GeneratedFiles/Aggregator/HandlerTypeFactoryImpl.h"
#include "TornadoEditor/Meta/GeneratedFiles/Aggregator/HandlerTypeInformationImpl.h"
#include "TornadoEditor/Meta/GeneratedFiles/Aggregator/HandlerRttiImpl.h"

using namespace nsTornadoEditor;

THandlerReflectionAggregatorImpl::THandlerReflectionAggregatorImpl()
{
    mTypeFactory = std::make_shared<THandlerTypeFactoryImpl>();
    mRtti = std::make_shared<THandlerRttiImpl>();
    mTypeInfo = std::make_shared<THandlerTypeInformationImpl>();
}
//--------------------------------------------------------------------------------------------------
