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

#include "TornadoEngine/TimeSliceEngine/ProjectConfig.h"
#include "TornadoEngine/TimeSliceEngine/LogDumper.h"

#include "TornadoEngine/TimeSliceEngine/StopAccessor.h"
#include "TornadoEngine/TimeSliceEngine/ModuleType.h"

namespace nsTornadoEngine
{
    class IModule;
    class TModuleManager;

    class DllExport TTimeSliceEngine : public TStopAccessor
    {
        std::list<IModule*> mModulePtrList;

        std::shared_ptr<TModuleManager> mModuleMng;// Hide from Launcher
        
        std::list<ModuleType> mModuleTypes;

    public:
        bool Init(const std::list<ModuleType>& moduleTypes);
        void StartModules();
        void Work(std::list<TLogDumper*>&& logDumpers);
        void StopModules();

    private:
        bool CreateModules();
    };
}