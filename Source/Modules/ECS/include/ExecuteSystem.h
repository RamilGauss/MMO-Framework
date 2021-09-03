/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "System.h"

namespace nsECSFramework
{
    class DllExport TExecuteSystem : virtual public TSystem
    {
    public:
        virtual void Execute() = 0;

        bool IsExecute() const override final { return true; }
    };

}
