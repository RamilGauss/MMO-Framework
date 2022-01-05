/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FrameKeyHandlerTerminatorSystem.h"
#include "Modules.h"
#include "ProjectConfigContainer.h"
#include "Logger.h"
#include "TimeSliceEngine.h"
#include "HandlerLinkHelper.h"

using namespace nsGraphicWrapper;

void TFrameKeyHandlerTerminatorSystem::Reactive(nsECSFramework::TEntityID eid,
    const nsGuiWrapper::TFrameKeyHandlerComponent* pFrameKeyHandlerComponent)
{
    auto entMng = GetEntMng();
    THandlerLinkHelper::UnlinkGui(entMng, eid, pFrameKeyHandlerComponent);
}
