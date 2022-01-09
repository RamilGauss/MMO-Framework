/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeDeclarationLexema.h"

#include "ILexema.h"
#include "Types.h"

using namespace nsCppParser;

bool TTypeDeclarationLexema::CanFill(const TLineTokenEntity* line) const
{
    using namespace boost::wave;

    auto hasEnum = Find(line->mTokens, T_ENUM);
    if (hasEnum != -1) {
        return false;
    }

    auto hasPragma = Find(line->mTokens, T_PP_PRAGMA);
    if (hasPragma != -1) {
        return false;
    }

    bool isClass = false;
    int cornerCount = 0;
    bool isSemiColon = false;

    for (auto& t : line->mTokens) {
        if (t.id == mTypeDecl && cornerCount == 0) {
            isClass = true;
        }
        if (t.id == T_SEMICOLON && cornerCount == 0) {
            isSemiColon = true;
        }
        if (t.id == T_LESS) {
            cornerCount++;
        }
        if (t.id == T_GREATER) {
            cornerCount--;
        }
    }
    return isClass && !isSemiColon;
}
//------------------------------------------------------------------------------------------------------
void TTypeDeclarationLexema::Fill(const TLineTokenEntity* line)
{
    using namespace boost::wave;

    std::string lastIdentifier;
    TInheritance inheritance;

    auto defaultAccessLevel = GetType() == ILexema::LexemaType::CLASS ? AccessLevel::PRIVATE : AccessLevel::PUBLIC;
    inheritance.accessLevel = defaultAccessLevel;

    std::string guessName;
    bool isColon = false;
    int cornerCount = 0;
    bool isClass = false;
    for (auto& t : line->mTokens) {
        if (t.id == mTypeDecl && cornerCount == 0) {
            isClass = true;
        }
        if (t.id == T_LESS) {
            cornerCount++;
        }
        if (t.id == T_GREATER) {
            cornerCount--;
        }
        if (t.id == T_COLON && cornerCount == 0 && !isColon) {
            isColon = true;
        }
        if (isClass && !isColon && t.id == T_IDENTIFIER) {
            lastIdentifier = t.value;
        }
        if (isColon && t.id == T_IDENTIFIER && cornerCount == 0) {
            inheritance.typeName += t.value;
        }
        if (t.id == T_COLON_COLON && isColon && cornerCount == 0) {
            inheritance.typeName += t.value;
        }
        if (t.id == T_COMMA && isColon) {
            mInheritanceList.push_back(inheritance);
            inheritance.accessLevel = defaultAccessLevel;
            inheritance.typeName = "";
        }
        if (t.id == T_PUBLIC) {
            inheritance.accessLevel = AccessLevel::PUBLIC;
        }
        if (t.id == T_PROTECTED) {
            inheritance.accessLevel = AccessLevel::PROTECTED;
        }
        if (t.id == T_PRIVATE) {
            inheritance.accessLevel = AccessLevel::PRIVATE;
        }
    }

    if (inheritance.HasSome()) {
        mInheritanceList.push_back(inheritance);
    }

    mName = lastIdentifier;
}
//------------------------------------------------------------------------------------------------------
std::string TTypeDeclarationLexema::ToString()
{
    std::string strInheritance;
    for (auto& inheritance : mInheritanceList) {
        auto access = magic_enum::enum_name<AccessLevel>(inheritance.accessLevel);
        strInheritance += fmt::format("{}: {} ", access.data(), inheritance.typeName);
    }

    if (strInheritance.length() > 0) {
        return fmt::format("{}: {} : {}", ILexema::ToString(), mName, strInheritance);
    }
    return fmt::format("{}: {}", ILexema::ToString(), mName);
}
//------------------------------------------------------------------------------------------------------