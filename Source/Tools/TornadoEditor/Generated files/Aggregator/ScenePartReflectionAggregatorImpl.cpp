/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ScenePartReflectionAggregatorImpl.h"

#include "ComponentReflectionAggregatorImpl.h"
#include "HandlerReflectionAggregatorImpl.h"
#include "SystemReflectionAggregatorImpl.h"

using namespace nsTornadoEditor;

TScenePartReflectionAggregatorImpl::TScenePartReflectionAggregatorImpl()
{
    mComponents = new TComponentReflectionAggregatorImpl();
    mHandlers = new THandlerReflectionAggregatorImpl();
    mSystems = new TSystemReflectionAggregatorImpl();
}
//--------------------------------------------------------------------------------------------------
TScenePartReflectionAggregatorImpl::~TScenePartReflectionAggregatorImpl()
{
    delete mComponents;
    delete mHandlers;
    delete mSystems;
}
//--------------------------------------------------------------------------------------------------
