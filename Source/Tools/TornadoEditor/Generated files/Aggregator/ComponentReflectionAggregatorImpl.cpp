/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// File has been generated at 2022_12_29 17:47:00.834
	
#include "ComponentReflectionAggregatorImpl.h"

#include "ComponentJsonSerializerImpl.h"
#include "ComponentEntityManagerExtensionImpl.h"
#include "ComponentTypeInfoImpl.h"

using namespace nsTornadoEditor;

TComponentReflectionAggregatorImpl::TComponentReflectionAggregatorImpl()
{
    mJson = new TComponentJsonSerializerImpl();
    mEntMng = new TComponentEntityManagerExtensionImpl();
    mTypeInfo = new TComponentTypeInfoImpl();
}
//--------------------------------------------------------------------------------------------------
TComponentReflectionAggregatorImpl::~TComponentReflectionAggregatorImpl()
{
    delete mJson;
    delete mEntMng;
    delete mTypeInfo;
}
//--------------------------------------------------------------------------------------------------
