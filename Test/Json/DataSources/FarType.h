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
        nsBase::nsCommon::TSaveToFile stf;
        nsBase::nsCommon::TSaveToFile* pstf;
        std::shared_ptr<nsBase::nsCommon::TSaveToFile> shstf;

        std::list<nsBase::nsCommon::TSaveToFile> stf_l;
        std::map<int, nsBase::nsCommon::TSaveToFile> stf_m;
    };
}