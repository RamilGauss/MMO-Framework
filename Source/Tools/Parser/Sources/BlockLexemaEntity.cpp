/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "BlockLexemaEntity.h"
#include "LineLexemaEntity.h"

using namespace nsCppParser;

std::string TBlockLexemaEntity::ToString(int indend)
{
    std::string str = std::string(4 * indend, ' ') + "BLOCK:\n";
    indend++;

    for (auto& lexema : mTokens) {
        switch (lexema->GetType()) {
            case ILexemaEntity::Type::BLOCK:
                str += ((TBlockLexemaEntity*) lexema.get())->ToString(indend);
                break;
            case ILexemaEntity::Type::LINE:
                for (auto& lexema : ((TLineLexemaEntity*) lexema.get())->mLexemas) {
                    str += std::string(4 * indend, ' ') + lexema->ToString() + "\n";
                }
                break;
        }
    }
    return str;
}
