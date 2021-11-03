/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "SceneManager.h"

#include "Modules.h"
#include <ECS/include/EntityManager.h>

using namespace nsTornadoEngine;

void TSceneManager::SetContentMap(const TSceneContentMap& sceneContentMap)
{
    mSceneContentMap = sceneContentMap;
}
//--------------------------------------------------------------------------------
void TSceneManager::SetEntityManager(nsECSFramework::TEntityManager* entMng)
{
    mEntityManager = entMng;
}
//--------------------------------------------------------------------------------
void TSceneManager::LoadByAbsPath(const std::string& absPath)
{
    // Same as InstantiateByAbsPath, but without replasing guid
}
//--------------------------------------------------------------------------------
void TSceneManager::LoadByGuid(const std::string& guid)
{
    // Convert to abs path
    // LoadByAbsPath()
}
//--------------------------------------------------------------------------------
void TSceneManager::InstantiateByAbsPath(const std::string& absPath)
{
    // 1. Deserialize to object

    // 2. Convert typeName to rtti

    // 3. Add entity

    // 4. Add component by rtti

    // 5. Deserialize component by rtti and json body

    // 6. Replace all guids to new guid with ParentGuids and SceneGuids
}
//--------------------------------------------------------------------------------
void TSceneManager::InstantiateByGuid(const std::string& guid)
{
    // Convert to abs path
    // InstantiateByAbsPath()
}
//--------------------------------------------------------------------------------
void TSceneManager::Unload(const std::string& guid)
{
    // Search all entities with sceneGuid and destroy'em all
}
//--------------------------------------------------------------------------------
void TSceneManager::Save(const std::string& guid)
{
    // Search all entities with sceneGuid and serialize to file
    // Check on existing in sceneManagerMap
}
//--------------------------------------------------------------------------------