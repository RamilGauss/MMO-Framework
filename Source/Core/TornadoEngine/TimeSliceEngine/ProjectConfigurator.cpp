/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ProjectConfigurator.h"

#include "TimeSliceEngine/ProjectConfigContainer.h"
#include "ProjectConfigLoader.h"
#include "ProjectConfigUnloader.h"

#include "Modules/Common/Modules.h"
#include "Modules/Common/ModuleManager.h"

using namespace nsTornadoEngine;

bool TProjectConfigurator::LoadProject(const std::string& absPathToProjectFile)
{
    Project()->projectAbsPath = absPathToProjectFile;

    TProjectConfigLoader projectLoader;
    auto loadResult = projectLoader.Load(Project());
    if (loadResult == false) {
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------------
void TProjectConfigurator::Setup()
{
    auto entMng = Modules()->EntMng();
    std::list<std::string> dllPathList = 
    {
        boost::dll::this_line_location().string(), 
        Project()->GetBinaryAbsPath()
    };
    entMng->Setup(dllPathList);

    auto& resources = Project()->mResources;

    auto resourceMng = Modules()->ResourceMng();

    resourceMng->SetContentMap(resources.resourcesContentMapPath);

    auto sceneMng = Modules()->SceneMng();

    sceneMng->SetEntityManager(entMng);
    sceneMng->SetContentMap(resources.scenesContentMapPath);

    auto prefabMng = Modules()->PrefabMng();

    prefabMng->SetEntityManager(entMng);
    prefabMng->SetContentMap(resources.prefabsContentMapPath);

    // Crossing
    sceneMng->SetPrefabManager(prefabMng);
    prefabMng->SetSceneManager(sceneMng);

    auto propertyMng = Modules()->PropertyMng();
    propertyMng->Init();

    Project()->SetEntityManager(entMng);

    Project()->mScenePartAggregator->Init();
}
//-----------------------------------------------------------------------------------
void TProjectConfigurator::UnloadProject()
{
    TProjectConfigUnloader projectUnloader;
    projectUnloader.Unload(Project());
}
//-----------------------------------------------------------------------------------
const std::list<ModuleType>& TProjectConfigurator::GetModuleTypes() const
{
    return Project()->mConveyor.modules;
}
//-----------------------------------------------------------------------------------
