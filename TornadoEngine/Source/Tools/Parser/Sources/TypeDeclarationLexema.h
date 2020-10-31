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
            std::string access;
            std::string typeName;
        };

        std::list<TInheritance> mInheritanceList;

        TTypeDeclarationLexema(boost::wave::token_id id) : mTypeDecl(id) {};

        //ILexema::LexemaType GetType() override { return ILexema::LexemaType::CLASS; }

        bool CanFill(const TLineTokenEntity& line) const override
        {
            bool isClass = false;
            int cornerCount = 0;
            bool isSemiColon = false;

            for (auto& t : line.mTokenList) {
                if (t.id == mTypeDecl && cornerCount == 0) {
                    isClass = true;
                }
                if (t.id == boost::wave::T_SEMICOLON && cornerCount == 0) {
                    isSemiColon = true;
                }
                if (t.id == boost::wave::T_LESS) {
                    cornerCount++;
                }
                if (t.id == boost::wave::T_GREATER) {
                    cornerCount--;
                }
            }
            return isClass && !isSemiColon;
        }

        void Fill(const TLineTokenEntity& line) override
        {
            std::string guessName;
            bool isColon = false;
            int cornerCount = 0;
            for (auto& t : line.mTokenList) {
                if (t.id == mTypeDecl && cornerCount == 0) {

                }
                if (t.id == boost::wave::T_LESS) {
                    cornerCount++;
                }
                if (t.id == boost::wave::T_GREATER) {
                    cornerCount--;
                }
                if (t.id == boost::wave::T_COLON && cornerCount == 0 && !isColon) {


                    isColon = true;
                }
            }
        }

        ~TTypeDeclarationLexema() {}
    };
}