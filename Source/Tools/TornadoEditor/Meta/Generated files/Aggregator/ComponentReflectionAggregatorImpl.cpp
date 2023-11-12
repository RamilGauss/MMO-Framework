/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_11_12 12:58:31.996
	
#include "ComponentReflectionAggregatorImpl.h"

#include "ComponentJsonSerializerImpl.h"
#include "ComponentEntityManagerExtensionImpl.h"
#include "ComponentRttiImpl.h"
#include "ComponentDynamicCasterImpl.h"
#include "ComponentTypeFactoryImpl.h"

using namespace nsTornadoEditor;

TComponentReflectionAggregatorImpl::TComponentReflectionAggregatorImpl()
{
    mJson = new TComponentJsonSerializerImpl();
    mEntMng = new TComponentEntityManagerExtensionImpl();
    mRtti = new TComponentRttiImpl();
    mDynamicCaster = new TComponentDynamicCasterImpl();
    mTypeFactory = new TComponentTypeFactoryImpl();
}
//--------------------------------------------------------------------------------------------------
TComponentReflectionAggregatorImpl::~TComponentReflectionAggregatorImpl()
{
    delete mJson;
    delete mEntMng;
    delete mRtti;
    delete mDynamicCaster;
    delete mTypeFactory;
}
//--------------------------------------------------------------------------------------------------
