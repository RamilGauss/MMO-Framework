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
    Modules()->SceneMng()->SetEntityManager(Modules()->EntMng());
    Modules()->SceneMng()->SetContentMap(Project()->mSceneContentMap);
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
