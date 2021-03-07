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
    class DllExport TVariableDeclarationLexema : public ILexema
    {
    public:
        std::string mType;
        std::string mName;
        VariableCategory mCategory;

        ILexema::LexemaType GetType() const override { return ILexema::LexemaType::VARIABLE_DECLARATION; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            // перед = или ; должен стоять идентификатор
            // должен быть тип перед именем
            using namespace boost::wave;
            int parenCount = 0;
            int semicolonIndex = -1;
            int assignIndex = -1;

            int index = 0;
            for (auto& t : line->mTokens) {
                if (t.id == T_SEMICOLON && parenCount == 0) {
                    semicolonIndex = index;
                }
                if (t.id == T_ASSIGN && parenCount == 0) {
                    assignIndex = index;
                }
                if (t.id == T_LEFTPAREN) {
                    parenCount++;
                }
                if (t.id == T_RIGHTPAREN) {
                    parenCount--;
                }
                index++;
            }
            if (semicolonIndex == -1) {
                return false;
            }

            int endNameIndex = 0;
            if (semicolonIndex == -1 || assignIndex == -1) {
                endNameIndex = semicolonIndex != -1 ? semicolonIndex : assignIndex;
            } else {
                endNameIndex = std::min(semicolonIndex, assignIndex);
            }

            bool hasIdentifier = false;
            int identifierIndex = 0;
            for (int i = endNameIndex - 1; i >= 0; i--) {
                auto& t = line->mTokens[i];

                if (t.id == T_IDENTIFIER) {
                    identifierIndex = i;
                    hasIdentifier = true;
                    break;
                }
                if (t.id != T_SPACE &&
                    t.id != T_SPACE2 &&
                    t.id != T_NEWLINE) {
                    return false;
                }
            }

            bool hasCanBeType = false;
            for (int i = 0; i < identifierIndex; i++) {
                auto& t = line->mTokens[i];

                if (IsCanBeType(t.id)) {
                    hasCanBeType = true;
                    break;
                }
            }

            return hasIdentifier && hasCanBeType;
        }

        void Fill(const TLineTokenEntity* line) override
        {
            using namespace boost::wave;
            // 1. Искать = или ;
            // 2. Искать идентификатор до этого токена - имя переменной
            // 3. Искать вначале const static constexpr - начало типа
            // 4. Взять тип между именем и началом
            // 5. Нормализация типа - удаление лишних space и newline
            auto assignIndex = Find(line, T_ASSIGN);
            auto semicolonIndex = Find(line, T_SEMICOLON);
            auto endNameIndex = assignIndex == -1 ? semicolonIndex : assignIndex;
            int nameIndex = -1;
            for (int i = endNameIndex; i >= 0; i--) {
                auto& t = line->mTokens[i];
                if (t.id == T_IDENTIFIER) {
                    mName = t.value;
                    nameIndex = i;
                    break;
                }
            }

            BL_ASSERT(nameIndex != -1);

            auto mutableIndex = Find(line, T_MUTABLE);
            auto constIndex = Find(line, T_CONST);
            auto staticIndex = Find(line, T_STATIC);

            if (mutableIndex != -1) {
                mCategory = VariableCategory::MUTABLE;
            } else if (constIndex != -1 && staticIndex != -1) {
                mCategory = VariableCategory::STATIC_CONST;
            } else if (constIndex != -1) {
                mCategory = VariableCategory::CONST;
            } else if (staticIndex != -1) {
                mCategory = VariableCategory::STATIC;
            }

            auto maxPrefixIndex = std::max(constIndex, staticIndex);
            maxPrefixIndex += 1;

            std::list<TTokenInfo> typeTokens;
            for (int i = maxPrefixIndex; i < nameIndex; i++) {
                typeTokens.push_back(line->mTokens[i]);
            }
            for (auto& t : typeTokens) {
                switch (t.id) {
                    case T_NEWLINE:
                        break;
                    default:
                        mType += t.value;
                }
            }
        }

        ~TVariableDeclarationLexema() {}

        std::string ToString() override
        {
            auto strCategory = magic_enum::enum_name<VariableCategory>(mCategory);
            return fmt::format("{}: {} {} {}", ILexema::ToString(), strCategory.data(), mType, mName);
        }

    private:

        static bool IsCanBeType(boost::wave::token_id id)
        {
            using namespace boost::wave;
            return
                id == T_BOOL ||
                id == T_CHAR ||
                id == T_SHORT ||
                id == T_INT ||
                id == T_LONG ||
                id == T_FLOAT ||
                id == T_DOUBLE ||
                id == T_SIGNED ||
                id == T_UNSIGNED ||
                id == T_IDENTIFIER;
        }
    };
}