/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Modules/Interfaces/IDataBaseModule.h"

namespace nsTornadoEngine
{
    class DllExport TDataBaseModule : public IDataBaseModule
    {
    public:
        TDataBaseModule();
        virtual ~TDataBaseModule();

        bool ModuleStartEvent() override;
        void ModuleWork() override;
        void StopEvent() override;
    };
}