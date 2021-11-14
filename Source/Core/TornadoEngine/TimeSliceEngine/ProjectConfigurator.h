/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <string>
#include <list>
#include "ModuleType.h"

namespace nsTornadoEngine
{
    class DllExport TProjectConfigurator
    {
        //###
        //TLoadStartedScenesSystem mLoadStartedScenesSystem;
        //TObjectMakerFeature mObjectMakerFeature;
        //TTreeBuilderFeature mTreeBuilderFeature;
        //###


    public:
        bool LoadProject(const std::string& absPathToProjectFile);
        void Setup();
        void UnloadProject();

        const std::list<ModuleType>& GetModuleTypes() const;
    };
}