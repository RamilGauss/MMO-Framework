/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TornadoEngine/TimeSliceEngine/ProjectConfigurator.h"

#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"
#include "TornadoEngine/TimeSliceEngine/ProjectConfigLoader.h"
#include "TornadoEngine/TimeSliceEngine/ProjectConfigUnloader.h"

#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Common/ModuleManager.h"

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

    resourceMng->SetContentMap(resources.resourcesContentMapAbsPath);

    auto sceneMng = Modules()->SceneMng();

    sceneMng->SetEntityManager(entMng);
    sceneMng->SetContentMap(resources.scenesContentMapAbsPath);

    auto prefabMng = Modules()->PrefabMng();

    prefabMng->SetEntityManager(entMng);
    prefabMng->SetContentMap(resources.prefabsContentMapAbsPath);

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
