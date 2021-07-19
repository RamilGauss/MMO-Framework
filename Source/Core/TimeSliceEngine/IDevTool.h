/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <vector>

#include "TypeDef.h"

class IModule;

class DllExport IDevTool
{
public:
    virtual ~IDevTool() {};

    virtual void SetVectorParam(std::vector<std::string>& vecArg) = 0;
    virtual std::string GetFileDescConveyer() = 0;
    virtual IModule* GetModuleByName(const std::string& sName) = 0;
};
