/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "Parser/Sources/TypeDeclarationLexema.h"

namespace nsCppParser
{
    class DllExport TClassLexema : public TTypeDeclarationLexema
    {
    public:
        TClassLexema() : TTypeDeclarationLexema(boost::wave::T_CLASS) { mDeclType = DeclarationType::CLASS; };

        ILexema::LexemaType GetType() const override { return ILexema::LexemaType::CLASS; }

        ~TClassLexema() {}
    };
}