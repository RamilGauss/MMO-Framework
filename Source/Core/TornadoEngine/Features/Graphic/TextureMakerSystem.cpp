/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TextureMakerSystem.h"

#include "ProjectConfigContainer.h"

#include "GraphicEngine/TextureFactory.h"

using namespace nsGraphicWrapper;

void TTextureMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGraphicWrapper::TTextureComponent* pTextureComponent)
{
    auto resourceAbsPath = nsTornadoEngine::Project()->GetResourcesAbsPath(pTextureComponent->resourceGuid);
    pTextureComponent->value = nsGraphicEngine::TTextureFactory::Load(resourceAbsPath);
}
