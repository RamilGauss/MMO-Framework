/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/StringExtensions.h"

#include "Parser/Sources/TypeDeclarationLexema.h"

#include "Parser/Sources/ILexema.h"
#include "Parser/Sources/Types.h"

using namespace nsCppParser;
using namespace boost::wave;

bool TTypeDeclarationLexema::TTemplateInfo::HasSome() const
{
    return args.size() > 0;
}
//------------------------------------------------------------------------------------------------------
bool TTypeDeclarationLexema::TInheritance::HasSome() const
{
    return typeName.length() > 0;
}
//------------------------------------------------------------------------------------------------------
TTypeDeclarationLexema::TTypeDeclarationLexema(boost::wave::token_id id) : mTypeDecl(id)
{}
//------------------------------------------------------------------------------------------------------
bool TTypeDeclarationLexema::CanFill(const TLineTokenEntity* line) const
{
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
    SearchName(line);

    SearchInheritances(line);

    SearchTemplateArgs(line);
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
void TTypeDeclarationLexema::SearchTemplateArgs(const TLineTokenEntity* line)
{
    int cornerCount = 0;

    // Has template? Searching an interval.
    bool isTemplate = false;
    int beginTemplateIndex = 0;
    int endTemplateIndex = 0;
    int index = 0;
    for (auto& t : line->mTokens) {
        if (t.id == T_TEMPLATE && cornerCount == 0) {
            isTemplate = true;
        }
        if (t.id == T_LESS) {
            cornerCount++;
            if (isTemplate && cornerCount == 1) {
                beginTemplateIndex = index;
            }
        }
        if (t.id == T_GREATER) {
            cornerCount--;
        }

        if (isTemplate) {
            if (t.id == T_LESS && cornerCount == 1) {
                beginTemplateIndex = index + 1;
            }
            if (t.id == T_GREATER && cornerCount == 0) {
                endTemplateIndex = index;
            }
        }

        if (t.id == mTypeDecl && cornerCount == 0) {
            break;
        }
        index++;
    }

    if (!isTemplate) {
        return;
    }

    TTemplateInfo templateInfo;
    std::string templateArg;
    for (int i = beginTemplateIndex; i < endTemplateIndex; i++) {
        auto& t = line->mTokens[i];
        if (t.id == T_LESS) {
            cornerCount++;
        }
        if (t.id == T_GREATER) {
            cornerCount--;
        }
        if (t.id == T_COMMA && cornerCount == 0) {
            TStringExtensions::TrimLeft(templateArg, " ");
            TStringExtensions::TrimRight(templateArg, " ");

            templateInfo.args.push_back(templateArg);
            templateArg = "";
        } else {
            templateArg += t.value;
        }
    }

    TStringExtensions::TrimLeft(templateArg, " ");
    TStringExtensions::TrimRight(templateArg, " ");

    if (templateArg.length()) {
        templateInfo.args.push_back(templateArg);
    }

    if (templateInfo.HasSome()) {
        mTemplateInfo = templateInfo;
    }
}
//------------------------------------------------------------------------------------------------------
void TTypeDeclarationLexema::SearchName(const TLineTokenEntity* line)
{
    std::string lastIdentifier;

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
        if (t.id == T_COLON && cornerCount == 0) {
            break;
        }
        if (t.id == T_IDENTIFIER) {
            lastIdentifier = t.value;
        }
    }

    mName = lastIdentifier;
}
//------------------------------------------------------------------------------------------------------
void TTypeDeclarationLexema::SearchInheritances(const TLineTokenEntity* line)
{
    TInheritance inheritance;

    auto defaultAccessLevel = GetType() == ILexema::LexemaType::CLASS ? AccessLevel::PRIVATE : AccessLevel::PUBLIC;
    inheritance.accessLevel = defaultAccessLevel;

    bool isColon = false;
    int cornerCount = 0;
    for (auto& t : line->mTokens) {
        if (t.id == T_LESS) {
            cornerCount++;
        }
        if (t.id == T_GREATER) {
            cornerCount--;
        }
        if (t.id == T_COLON && cornerCount == 0 && !isColon) {
            isColon = true;
        }

        if (!isColon) {
            continue;
        }
        //----------------------------
        if ((t.id == T_IDENTIFIER) || 
            (t.id == T_COLON_COLON) || 
            (t.id == T_LESS) ||
            (t.id == T_GREATER)) {
            inheritance.typeName += t.value;
        }
        if ((t.id == T_COMMA) &&
            (cornerCount > 0)) {
            inheritance.typeName += t.value;
        }
        if (t.id == T_COMMA && cornerCount == 0) {
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
}
//------------------------------------------------------------------------------------------------------
