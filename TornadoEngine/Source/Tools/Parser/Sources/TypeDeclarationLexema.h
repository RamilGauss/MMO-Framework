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
        };

        std::list<TInheritance> mInheritanceList;

        TTypeDeclarationLexema(boost::wave::token_id id) : mTypeDecl(id) {};

        bool CanFill(const TLineTokenEntity* line) const override
        {
            using namespace boost::wave;

            bool isClass = false;
            int cornerCount = 0;
            bool isSemiColon = false;

            for (auto& t : line->mTokenList) {
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

            std::string guessName;
            bool isColon = false;
            int cornerCount = 0;
            bool isClass = false;
            for (auto& t : line->mTokenList) {
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
                if (isClass && !isColon  && t.id == T_IDENTIFIER) {
                    lastIdentifier = t.value;
                }
                if (isColon && t.id == T_IDENTIFIER) {
                    inheritance.typeName = t.value;
                }
                if (t.id == T_COMMA && isColon) {
                    mInheritanceList.push_back(inheritance);
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

            mName = lastIdentifier;
        }

        ~TTypeDeclarationLexema() {}

        std::string GetInfo() override
        {
            return fmt::format("{}: name {}", ILexema::GetInfo(), mName);
        }
    };
}