/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/Features/Graphic/Begin/Builder/Properties/TitleAddSystem.h"

using namespace nsGraphicWrapper;
using namespace nsGuiWrapper;

void TTitleAddSystem::Reactive(nsECSFramework::TEntityID eid, const TTitleComponent* pTitleComponent)
{
    pTitleComponent->pOwner->SetTitle(pTitleComponent->value);
}