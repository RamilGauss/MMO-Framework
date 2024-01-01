/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once


#include <list>
#include <memory>
#include <string>

#include "Base/Common/TypeDef.h"
#include "Base/Common/CallbackPool.h"

#include "ProjectConfig.h"
#include "ProjectConfigContainer.h"

#include "StopAccessor.h"
#include "ModuleType.h"

namespace nsTornadoEngine
{
    class IModule;
    class TModuleManager;

    class DllExport TTimeSliceEngine : public TStopAccessor
    {
        std::list<IModule*> mModulePtrList;

        std::shared_ptr<TModuleManager> mModuleMng;// Hide from Launcher
        
        std::list<ModuleType> mModuleTypes;

        TProjectConfigContainer mProjectConfigContainer;

    public:
        TTimeSliceEngine();

        bool Work(const std::list<ModuleType>& moduleTypes);

        TCallbackPool<> onModuleCreationEndsCb;

    private:
        bool CreateModules();
        void Work();
        void Done();
    };
}