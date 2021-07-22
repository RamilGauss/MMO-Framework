/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Ãóäàêîâ Ğàìèëü Ñåğãååâè÷
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modules.h"
#include "SingletonManager.h"

using namespace nsTornadoEngine;

TGraphicEngine* TModules::Graphic() const
{
    return graphic;
}

TPhysicEngine* TModules::Physic() const
{
    return physic;
}

TEntityManager* TModules::EntMng() const
{
    return entMng;
}

TSceneManager* TModules::SceneMng() const
{
    return sceneMng;
}

TPrefabManager* TModules::PrefabMng() const
{
    return prefabMng;
}

TModules* nsTornadoEngine::Modules()
{
    return SingletonManager()->Get<TModules>();
}
