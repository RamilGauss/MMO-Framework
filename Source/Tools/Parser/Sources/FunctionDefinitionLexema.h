/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "Parser/Sources/FunctionLexema.h"

namespace nsCppParser
{
    class DllExport TFunctionDefinitionLexema : public TFunctionLexema
    {
    public:
        TFunctionDefinitionLexema() : TFunctionLexema(ILexema::LexemaType::FUNCTION_DEFINITION) {}
        ~TFunctionDefinitionLexema() {}
    };
}