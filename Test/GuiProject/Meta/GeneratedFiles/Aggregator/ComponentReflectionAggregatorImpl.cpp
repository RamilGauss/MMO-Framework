/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "GuiProject/Meta/GeneratedFiles/Aggregator/ComponentReflectionAggregatorImpl.h"

#include "GuiProject/Meta/GeneratedFiles/Aggregator/ComponentJsonSerializerImpl.h"
#include "GuiProject/Meta/GeneratedFiles/Aggregator/ComponentEntityManagerExtensionImpl.h"
#include "GuiProject/Meta/GeneratedFiles/Aggregator/ComponentRttiImpl.h"
#include "GuiProject/Meta/GeneratedFiles/Aggregator/ComponentDynamicCasterImpl.h"
#include "GuiProject/Meta/GeneratedFiles/Aggregator/ComponentTypeFactoryImpl.h"

using namespace nsGuiProject;

TComponentReflectionAggregatorImpl::TComponentReflectionAggregatorImpl()
{
    mJson = std::make_shared<TComponentJsonSerializerImpl>();
    mEntMng = std::make_shared<TComponentEntityManagerExtensionImpl>();
    mRtti = std::make_shared<TComponentRttiImpl>();
    mDynamicCaster = std::make_shared<TComponentDynamicCasterImpl>();
    mTypeFactory = std::make_shared<TComponentTypeFactoryImpl>();
}
//--------------------------------------------------------------------------------------------------
TComponentReflectionAggregatorImpl::~TComponentReflectionAggregatorImpl()
{
}
//--------------------------------------------------------------------------------------------------
