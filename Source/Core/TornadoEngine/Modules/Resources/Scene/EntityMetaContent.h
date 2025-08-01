/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TornadoEngine/Modules/Resources/Common/EntityContent.h"

namespace nsTornadoEngine
{
    struct DllExport TEntityMetaContent
    {
        TEntityContent content;

        std::string guid;
        std::string parentGuid;
    };

    using TEntityMetaContentPtr = std::shared_ptr<TEntityMetaContent>;
}
