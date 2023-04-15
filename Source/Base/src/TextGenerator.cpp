/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TextGenerator.h"

#include "GuidGenerator.h"

namespace nsBase
{
    TTextGenerator::TTextGenerator(const std::list<TLine>& lines)
    {
        mLines = lines;
    }
    //--------------------------------------------------------------------------------------------------
    void TTextGenerator::SetTabSize(uint8_t value)
    {
        mTabSize = value;
    }
    //--------------------------------------------------------------------------------------------------
    bool TTextGenerator::Apply(const inja::json& data, const std::list<TFormatFuncDeclaration>& formatFuncDeclarations)
    {
        std::string STAMP = nsBase::TGuidGenerator::Generate();

        try {
            inja::Environment env;

            for (auto& formatFuncDeclaration : formatFuncDeclarations) {
                env.add_callback(formatFuncDeclaration.name, formatFuncDeclaration.argCount, formatFuncDeclaration.func);
            }

            // Make a string for a inja render
            std::string str;

            for (auto& line : mLines) {
                str += STAMP;
                str += line.str;
                str += RET_SYMBOL;
            }

            str = env.render(str, data);

            uint32_t offset = 0;

            std::list<std::string> cutStr;
            // Form new lines
            while (true) {
                auto pos = str.find(RET_SYMBOL.c_str(), offset);
                if (pos == std::string::npos) {
                    break;
                }

                cutStr.push_back(str.substr(offset, pos - offset));
                offset = pos + RET_SYMBOL.size();
            }

            std::list<TLine> newLines;
            uint32_t currentTabCount = 0;
            auto line = mLines.begin();

            for (auto& cut : cutStr) {
                TLine newLine;

                auto stampPos = cut.find(STAMP);
                if (stampPos != std::string::npos) {
                    currentTabCount = 0;
                    newLine.str = cut.substr(STAMP.size());
                    newLine.tabDiff = line->tabDiff;

                    line++;
                } else {
                    uint8_t tabCount = 0;
                    for (auto& cutSymbol : cut){
                        if (cutSymbol == '\t') {
                            tabCount++;
                        } else {
                            break;
                        }
                    }
                    if (currentTabCount != tabCount) {
                        newLine.tabDiff = tabCount - currentTabCount;
                        currentTabCount = tabCount;
                    }

                    newLine.str = cut.substr(tabCount);
                }

                newLines.emplace_back(newLine);
            }

            mLines = std::move(newLines);

        } catch (...) {
            return false;
        }

        return true;
    }
    //--------------------------------------------------------------------------------------------------
    std::string TTextGenerator::Render() const
    {
        std::string str;
        uint32_t tabCount = 0;

        int i = 0;
        for (auto& line : mLines) {
            tabCount += line.tabDiff;

            str += std::string(tabCount * mTabSize, ' ');
            str += line.str;
            str += i + 1 < mLines.size() ? "\n" : "";

            i++;
        }

        return str;
    }
    //--------------------------------------------------------------------------------------------------
}