/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include "ConveyerConfig.h"

class TConveyerFileParser
{
    std::string strError;

    TConveyerConfig mConveyerConfig;
public:
    bool Parse(std::string& fileDescConveyer);
    std::string GetStrError();
    std::vector<std::string> GetResult();
};
