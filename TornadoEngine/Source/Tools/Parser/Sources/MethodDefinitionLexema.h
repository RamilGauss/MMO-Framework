/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "MethodLexema.h"

namespace nsCppParser
{
    class DllExport TMethodDefinitionLexema : public TMethodLexema
    {
    public:
        TMethodDefinitionLexema() : TMethodLexema(ILexema::LexemaType::METHOD_DEFINITION) {}
        ~TMethodDefinitionLexema() {}
    };
}