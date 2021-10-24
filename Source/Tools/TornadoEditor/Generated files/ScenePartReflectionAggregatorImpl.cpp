/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ScenePartReflectionAggregatorImpl.h"

#include "ComponentReflectionAggregatorImpl.h"
#include "HandlerReflectionAggregatorImpl.h"
#include "FeatureReflectionAggregatorImpl.h"
#include "MenuItemReflectionAggregatorImpl.h"

using namespace nsTornadoEditor;

TScenePartReflectionAggregatorImpl::TScenePartReflectionAggregatorImpl()
{
    mComponents = new TComponentReflectionAggregatorImpl();
    mHandlers = new THandlerReflectionAggregatorImpl();
    mFeatures = new TFeatureReflectionAggregatorImpl();
    mMenuItems = new TMenuItemReflectionAggregatorImpl();
}
//---------------------------------------------------------------------------------
TScenePartReflectionAggregatorImpl::~TScenePartReflectionAggregatorImpl()
{
    delete mComponents;
    delete mHandlers;
    delete mFeatures;
    delete mMenuItems;
}
//---------------------------------------------------------------------------------
