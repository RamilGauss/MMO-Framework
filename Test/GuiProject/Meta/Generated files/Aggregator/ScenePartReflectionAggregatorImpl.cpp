/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_09_12 12:37:51.402
	
#include "ScenePartReflectionAggregatorImpl.h"

#include "ComponentReflectionAggregatorImpl.h"
#include "HandlerReflectionAggregatorImpl.h"
#include "SystemReflectionAggregatorImpl.h"
#include "ImGuiWidgetsReflectionAggregatorImpl.h"

using namespace nsTornadoEditor;

TScenePartReflectionAggregatorImpl::TScenePartReflectionAggregatorImpl()
{
    mComponents = new TComponentReflectionAggregatorImpl();
    mHandlers = new THandlerReflectionAggregatorImpl();
    mSystems = new TSystemReflectionAggregatorImpl();
    mImGuiWidgets = new TImGuiWidgetsReflectionAggregatorImpl();
}
//--------------------------------------------------------------------------------------------------
TScenePartReflectionAggregatorImpl::~TScenePartReflectionAggregatorImpl()
{
    delete mComponents;
    delete mHandlers;
    delete mSystems;
    delete mImGuiWidgets;
}
//--------------------------------------------------------------------------------------------------
