/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FeatureReflectionAggregatorImpl.h"

#include "FeatureTypeFactoryImpl.h"
#include "FeatureTypeInformationImpl.h"

using namespace nsTornadoEditor;

TFeatureReflectionAggregatorImpl::TFeatureReflectionAggregatorImpl()
{
    mTypeFactory = new TFeatureTypeFactoryImpl();
    mTypeInfo = new TFeatureTypeInformationImpl();
}
//-----------------------------------------------------------------------------
TFeatureReflectionAggregatorImpl::~TFeatureReflectionAggregatorImpl()
{
    delete mTypeFactory;
    delete mTypeInfo;
}
//-----------------------------------------------------------------------------