#include "ProjectConfigurator.h"

#include "ProjectConfigContainer.h"
#include "ProjectConfigLoader.h"
#include "ProjectConfigUnloader.h"

#include "Modules.h"
#include "ModuleManager.h"

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
    
    auto sceneMng = Modules()->SceneMng();

    sceneMng->SetEntityManager(entMng);
    sceneMng->SetContentMap(resources.scenes);

    auto prefabMng = Modules()->PrefabMng();

    prefabMng->SetEntityManager(entMng);
    prefabMng->SetContentMap(resources.prefabs);

    // Crossing
    sceneMng->SetPrefabManager(prefabMng);
    prefabMng->SetSceneManager(sceneMng);

    auto propertyMng = Modules()->PropertyMng();
    propertyMng->Init();
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
