/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "TypeDeclarationLexema.h"

namespace nsCppParser
{
    class DllExport TStructLexema : public TTypeDeclarationLexema
    {
    public:
        TStructLexema() : TTypeDeclarationLexema(boost::wave::T_STRUCT) { mDeclType = DeclarationType::STRUCT; };

        ILexema::LexemaType GetType() const override { return ILexema::LexemaType::STRUCT; }

        ~TStructLexema() {}
    };
}