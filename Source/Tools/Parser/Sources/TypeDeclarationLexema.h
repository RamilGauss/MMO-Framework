/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "ILexema.h"
#include "Types.h"

namespace nsCppParser
{
    class DllExport TTypeDeclarationLexema : public ILexema
    {
    protected:

        boost::wave::token_id mTypeDecl;

    public:
        DeclarationType mDeclType;

        std::string mName;

        struct TInheritance
        {
            AccessLevel accessLevel;
            std::string typeName;

            bool HasSome() const
            {
                return typeName.length() > 0;
            }
        };

        std::list<TInheritance> mInheritanceList;

        TTypeDeclarationLexema(boost::wave::token_id id) : mTypeDecl(id) {};

        bool CanFill(const TLineTokenEntity* line) const override
        {
            using namespace boost::wave;

            auto hasEnum = std::find_if(std::begin(line->mTokens), std::end(line->mTokens), [](const TTokenInfo& t) { return t.id == T_ENUM; });
            if (hasEnum != std::end(line->mTokens)) {
                return false;
            }

            auto hasPragma = std::find_if(std::begin(line->mTokens), std::end(line->mTokens), [](const TTokenInfo& t) { return t.id == T_PP_PRAGMA; });
            if (hasPragma != std::end(line->mTokens)) {
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

        void Fill(const TLineTokenEntity* line) override
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
                if (isColon && t.id == T_IDENTIFIER) {
                    inheritance.typeName += t.value;
                }
                if (t.id == T_COLON_COLON && isColon) {
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

        ~TTypeDeclarationLexema() {}

        std::string ToString() override
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
    };
}