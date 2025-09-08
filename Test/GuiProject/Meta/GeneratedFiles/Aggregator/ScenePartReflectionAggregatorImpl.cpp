/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "ScenePartReflectionAggregatorImpl.h"

#include "ComponentReflectionAggregatorImpl.h"
#include "HandlerReflectionAggregatorImpl.h"
#include "SystemReflectionAggregatorImpl.h"
#include "ImGuiWidgetsReflectionAggregatorImpl.h"

using namespace nsGuiProject;

TScenePartReflectionAggregatorImpl::TScenePartReflectionAggregatorImpl()
{
    mComponents = std::make_shared<TComponentReflectionAggregatorImpl>();
    mHandlers = std::make_shared<THandlerReflectionAggregatorImpl>();
    mSystems = std::make_shared<TSystemReflectionAggregatorImpl>();
    mImGuiWidgets = std::make_shared<TImGuiWidgetsReflectionAggregatorImpl>();
}
//--------------------------------------------------------------------------------------------------
TScenePartReflectionAggregatorImpl::~TScenePartReflectionAggregatorImpl()
{
}
//--------------------------------------------------------------------------------------------------
