/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEditor_ScenePartContainer.h"

#include "TornadoEditor_ComponentContainer.h"
#include "TornadoEditor_HandlerContainer.h"
#include "TornadoEditor_FeatureContainer.h"
#include "TornadoEditor_MenuItemContainer.h"

using namespace nsTornadoEditor;

TTornadoEditor_ScenePartContainer::TTornadoEditor_ScenePartContainer()
{
    mComponentContainer = new TTornadoEditor_ComponentContainer();
    mHandlerContainer = new TTornadoEditor_HandlerContainer();
    mFeatureContainer = new TTornadoEditor_FeatureContainer();
    mMenuItemContainer = new TTornadoEditor_MenuItemContainer();
}
//---------------------------------------------------------------------------------
TTornadoEditor_ScenePartContainer::~TTornadoEditor_ScenePartContainer()
{
    delete mComponentContainer;
    delete mHandlerContainer;
    delete mFeatureContainer;
    delete mMenuItemContainer;
}
//---------------------------------------------------------------------------------
