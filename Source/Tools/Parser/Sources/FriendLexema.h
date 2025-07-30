/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "Parser/Sources/ILexema.h"

namespace nsCppParser
{
    class DllExport TFriendLexema : public ILexema
    {
    public:
        // friend type, etc.
        ILexema::LexemaType GetType() const override { return ILexema::LexemaType::FRIEND; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            using namespace boost::wave;

            return false;
        }

        void Fill(const TLineTokenEntity* line) override
        {

        }

        ~TFriendLexema() {}
    };
}