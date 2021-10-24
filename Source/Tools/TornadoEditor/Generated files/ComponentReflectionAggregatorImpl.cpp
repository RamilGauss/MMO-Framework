/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ComponentReflectionAggregatorImpl.h"
#include "ComponentJsonSerializerImpl.h"

using namespace nsTornadoEditor;

TComponentReflectionAggregatorImpl::TComponentReflectionAggregatorImpl()
{
    mJson = new TComponentJsonSerializerImpl();
    //mBin = new ;
    //mImGui = new ;
    //mEntMng = new ;
    //mTypeFactory = new ;
    //mTypeInfo = new ;
}
//------------------------------------------------------------------------
TComponentReflectionAggregatorImpl::~TComponentReflectionAggregatorImpl()
{
    delete mJson;
    delete mBin;
    delete mImGui;
    delete mEntMng;
    delete mTypeFactory;
    delete mTypeInfo;
}
//------------------------------------------------------------------------
