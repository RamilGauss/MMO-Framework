/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine/TextureFactory.h"

#include "TornadoEngine/Features/Graphic/Begin/Terminator/Graphic/TextureTerminatorSystem.h"

using namespace nsGraphicWrapper;

void TTextureTerminatorSystem::Reactive(nsECSFramework::TEntityID eid, const nsGraphicWrapper::TTextureFromFileComponent* pTextureComponent)
{
    nsGraphicEngine::TTextureFactory::Unload(pTextureComponent->value);

    pTextureComponent->value = nullptr;
}
