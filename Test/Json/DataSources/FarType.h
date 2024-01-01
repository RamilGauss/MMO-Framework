/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <memory>
#include <map>
#include <list>

#include "Base/Common/SaveToFile.h"

namespace nsFarType
{
    struct X
    {
        TSaveToFile stf;
        TSaveToFile* pstf;
        std::shared_ptr<TSaveToFile> shstf;

        std::list<TSaveToFile> stf_l;
        std::map<int, TSaveToFile> stf_m;
    };
}