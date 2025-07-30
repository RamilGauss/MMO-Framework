/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine/TextureFactory.h"

#include "TornadoEngine/Features/Graphic/Begin/Maker/Graphic/TextureMakerSystem.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Resources/Common/ResourceManager.h"

using namespace nsGraphicWrapper;

void TTextureMakerSystem::Reactive(nsECSFramework::TEntityID eid, const nsGraphicWrapper::TTextureFromFileComponent* pTextureComponent)
{
    auto resourceAbsPath = nsTornadoEngine::Modules()->ResourceMng()->GetAbsPath(pTextureComponent->resourceGuid);
    pTextureComponent->value = nsGraphicEngine::TTextureFactory::Load(resourceAbsPath);
}
