/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <list>
#include <memory>
#include <string>

#include "ProjectConfig.h"
#include "CallBackRegistrator.h"
#include "StopAccessor.h"

namespace nsTornadoEngine
{
    class IModule;
    class TModuleManager;

    class DllExport TTimeSliceEngine : public TStopAccessor
    {
        std::list<IModule*> mModulePtrList;

        std::shared_ptr<TModuleManager> mModuleMng;// Hide from Launcher

    public:
        static const std::string NAME;

        TTimeSliceEngine();

        bool Work(std::string absPathToProjectFile);// начало работы
    private:
        bool CreateModules();

        void Work();
    private:
        void Done();
    };
}