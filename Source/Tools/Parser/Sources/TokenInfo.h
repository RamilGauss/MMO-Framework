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

#include "IdentifierToken.h"

namespace nsCppParser
{
    struct DllExport TTokenInfo
    {
        boost::wave::token_id id;
        std::string strId;
        std::string value;

        IdentifierToken Id() const
        {
            if (id == boost::wave::T_IDENTIFIER) {
                if (value == "final") {
                    return IdentifierToken::FINAL;
                }
                if (value == "override") {
                    return IdentifierToken::OVERRIDE;
                }
                return IdentifierToken::OTHER;
            }
            return IdentifierToken::NOT_IDENTIFIER;
        }
    };
}