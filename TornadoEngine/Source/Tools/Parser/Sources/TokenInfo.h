/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <boost/wave/token_ids.hpp>

#include "TypeDef.h"

namespace nsCppParser
{
    struct DllExport TTokenInfo
    {
        boost::wave::token_id id;
        std::string strId;
        std::string value;
    };
}