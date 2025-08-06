/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:58.491
#include "TornadoEditor/Meta/GeneratedFiles/Aggregator/ComponentReflectionAggregatorImpl.h"

#include "TornadoEditor/Meta/GeneratedFiles/Aggregator/ComponentJsonSerializerImpl.h"
#include "TornadoEditor/Meta/GeneratedFiles/Aggregator/ComponentEntityManagerExtensionImpl.h"
#include "TornadoEditor/Meta/GeneratedFiles/Aggregator/ComponentRttiImpl.h"
#include "TornadoEditor/Meta/GeneratedFiles/Aggregator/ComponentDynamicCasterImpl.h"
#include "TornadoEditor/Meta/GeneratedFiles/Aggregator/ComponentTypeFactoryImpl.h"

using namespace nsTornadoEditor;

TComponentReflectionAggregatorImpl::TComponentReflectionAggregatorImpl()
{
    mJson = std::make_shared<TComponentJsonSerializerImpl>();
    mEntMng = std::make_shared<TComponentEntityManagerExtensionImpl>();
    mRtti = std::make_shared<TComponentRttiImpl>();
    mDynamicCaster = std::make_shared<TComponentDynamicCasterImpl>();
    mTypeFactory = std::make_shared<TComponentTypeFactoryImpl>();
}
//--------------------------------------------------------------------------------------------------
