/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "ILexema.h"

namespace nsCppParser
{
    class DllExport TMemberLexema : public ILexema
    {
        static bool IsType(boost::wave::token_id id)
        {
            using namespace boost::wave;
            return
                id == T_BOOL ||
                id == T_CHAR ||
                id == T_SHORT ||
                id == T_INT ||
                id == T_FLOAT ||
                id == T_DOUBLE ||
                id == T_IDENTIFIER;
        }

        static bool IsPrefixType(boost::wave::token_id id)
        {
            using namespace boost::wave;
            return id == T_SIGNED ||
                id == T_UNSIGNED;
        }

    public:

        std::string mName;
        std::string mType;

        ILexema::LexemaType GetType() override { return ILexema::LexemaType::MEMBER; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            using namespace boost::wave;
            bool hasAssign = false;
            bool isMember = false;
            bool hasSemicolon = false;

            for (auto& t : line->mTokenList) {
                if (t.id == T_SEMICOLON) {
                    hasSemicolon = true;
                }
                if (t.id == T_IDENTIFIER && !hasAssign) {
                    isMember = true;
                }
                if (t.id == T_ASSIGN) {
                    hasAssign = true;
                }
                if ((t.id == T_LEFTPAREN ||
                    t.id == T_RIGHTPAREN) &&
                    !hasAssign) {
                    return false;
                }
            }
            return isMember && hasSemicolon;
        }

        void Fill(const TLineTokenEntity* line) override
        {
            using namespace boost::wave;
            bool hasAssign = false;
            bool isMember = false;

            bool beginCollectType = false;
            //bool 

            for (auto& t : line->mTokenList) {
                if (beginCollectType) {
                    mType += t.value;
                }

                if (t.id == T_IDENTIFIER && !hasAssign) {

                }
                if (t.id == T_ASSIGN) {
                    hasAssign = true;
                }
                if (IsPrefixType(t.id) && !hasAssign) {
                    mType += t.value;
                    beginCollectType = true;
                }
                if (IsType(t.id) && !hasAssign) {
                    mType += t.value;
                }
            }
        }

        ~TMemberLexema() {}

        std::string GetInfo() override
        {
            return fmt::format("{}: {} {}", ILexema::GetInfo(), mType, mName);
        }
    };
}