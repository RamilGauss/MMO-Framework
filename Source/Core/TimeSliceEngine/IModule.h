/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include "TypeDef.h"

class DllExport IModule
{
public:
    virtual ~IModule() {};

    virtual bool Work() = 0;

    virtual std::string GetName() = 0;

    virtual void StartEvent() {}
    virtual void StopEvent() {}
};
