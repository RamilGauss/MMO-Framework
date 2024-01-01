/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include "Base/Common/TypeDef.h"

#include "ILexema.h"

namespace nsCppParser
{
    class DllExport TEnumValuesLexema : public ILexema
    {
        enum class StateType
        {
            BEGIN,
            IDENTIFIER,
            ASSIGN,
            MINUS,
            INTLIT,
            COMMA
        };
    public:
        std::map<std::string, int64_t> mValuesMap;

        ILexema::LexemaType GetType() const override { return ILexema::LexemaType::ENUM_VALUES; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            std::vector<TTokenInfo> normalizedTokens;
            ThinningEmpty(line->mTokens, normalizedTokens);
            auto checkResult = Check(normalizedTokens);
            if (!checkResult) {
                return false;
            }
            using namespace boost::wave;

            StateType state = StateType::BEGIN;
            for (auto& t : normalizedTokens) {
                switch (t.id) {
                    case T_COMMA:
                        if (state != StateType::IDENTIFIER &&
                            state != StateType::INTLIT) {
                            return false;
                        }
                        state = StateType::COMMA;
                        break;
                    case T_IDENTIFIER:
                        if (state != StateType::COMMA &&
                            state != StateType::BEGIN) {
                            return false;
                        }
                        state = StateType::IDENTIFIER;
                        break;
                    case T_MINUS:
                        if (state != StateType::ASSIGN) {
                            return false;
                        }
                        state = StateType::MINUS;
                        break;
                    case T_INTLIT:
                        if (state != StateType::ASSIGN &&
                            state != StateType::MINUS) {
                            return false;
                        }
                        state = StateType::INTLIT;
                        break;
                    case T_ASSIGN:
                        if (state != StateType::IDENTIFIER) {
                            return false;
                        }
                        state = StateType::ASSIGN;
                        break;
                    default:
                        return false;
                }
            }
            if (state != StateType::IDENTIFIER &&
                state != StateType::INTLIT &&
                state != StateType::COMMA) {
                return false;
            }
            return true;
        }

        void Fill(const TLineTokenEntity* line) override
        {
            std::vector<TTokenInfo> normalizedTokens;
            ThinningEmpty(line->mTokens, normalizedTokens);
            using namespace boost::wave;

            std::string identifier;
            int64_t lastValue = 0;
            bool hasMinus = false;
            bool hasValue = false;
            int commaCount = 0;
            for (auto& t : normalizedTokens) {
                switch (t.id) {
                    case T_COMMA:
                        if (commaCount > 0 && !hasValue) {
                            lastValue++;
                        }
                        commaCount++;
                        mValuesMap.insert({identifier, lastValue});
                        hasValue = false;
                        break;
                    case T_IDENTIFIER:
                        identifier = t.value;
                        break;
                    case T_MINUS:
                        hasMinus = true;
                        break;
                    case T_INTLIT:
                        {
                            hasValue = true;
                            char* str_end = nullptr;
                            auto num10 = strtoll(t.value.data(), &str_end, 10);
                            auto num16 = strtoll(t.value.data(), &str_end, 16);
                            if (num10 == num16) {
                                lastValue = num10;
                            } else if (num10 != 0) {
                                lastValue = num10;
                            } else {
                                lastValue = num16;
                            }
                            if (hasMinus) {
                                lastValue *= -1;
                                hasMinus = false;
                            }
                        }
                        break;
                    case T_ASSIGN:
                        break;
                }
            }
            if (normalizedTokens.back().id != T_COMMA) {
                if (commaCount > 0) {
                    lastValue++;
                }
                mValuesMap.insert({identifier, lastValue});
            }
        }

        ~TEnumValuesLexema() {}

        std::string ToString() override
        {
            auto type = magic_enum::enum_name<ILexema::LexemaType>(GetType());

            std::string str = fmt::format("{} :", type.data());
            for (auto& pair : mValuesMap) {
                str += fmt::format("{}={}, ", pair.first, pair.second);
            }
            return str;
        }
    private:
        bool Check(std::vector<TTokenInfo>& tokens) const
        {
            using namespace boost::wave;
            for (auto& t : tokens) {
                switch (t.id) {
                    case T_COMMA:
                    case T_IDENTIFIER:
                    case T_INTLIT:
                    case T_ASSIGN:
                    case T_MINUS:
                        break;
                    default:
                        return false;
                }
            }
            return true;
        }
    };
}