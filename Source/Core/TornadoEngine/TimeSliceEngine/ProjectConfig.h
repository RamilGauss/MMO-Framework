/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <list>
#include <string>

#pragma REFLECTION_ATTRIBUTE
struct TProjectInfo
{
    std::string company;
    std::string appName;
    std::string license;
};

#pragma REFLECTION_ATTRIBUTE
struct TProjectConfig
{
    TProjectInfo info;

    std::string binary;

    std::string conveyorFile;
    std::list<std::string> startScenes;
    std::vector<std::string> args;
};
