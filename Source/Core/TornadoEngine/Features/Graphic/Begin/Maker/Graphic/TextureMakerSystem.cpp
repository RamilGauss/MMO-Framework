/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TextureMakerSystem.h"

#include "Modules.h"
#include "ResourceManager.h"

#include "GraphicEngine/TextureFactory.h"

using namespace nsGraphicWrapper;

void TTextureMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGraphicWrapper::TTextureFromFileComponent* pTextureComponent)
{
    auto resourceAbsPath = nsTornadoEngine::Modules()->ResourceMng()->GetAbsPath(pTextureComponent->resourceGuid);
    pTextureComponent->value = nsGraphicEngine::TTextureFactory::Load(resourceAbsPath);
}
