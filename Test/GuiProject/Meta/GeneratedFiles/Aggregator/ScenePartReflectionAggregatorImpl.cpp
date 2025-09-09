/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "GuiProject/Meta/GeneratedFiles/Aggregator/ScenePartReflectionAggregatorImpl.h"

#include "GuiProject/Meta/GeneratedFiles/Aggregator/ComponentReflectionAggregatorImpl.h"
#include "GuiProject/Meta/GeneratedFiles/Aggregator/HandlerReflectionAggregatorImpl.h"
#include "GuiProject/Meta/GeneratedFiles/Aggregator/SystemReflectionAggregatorImpl.h"
#include "GuiProject/Meta/GeneratedFiles/Aggregator/ImGuiWidgetsReflectionAggregatorImpl.h"

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
