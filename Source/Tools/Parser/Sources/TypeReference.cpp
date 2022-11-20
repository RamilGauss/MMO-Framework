/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeReference.h"
#include "StringExtensions.h"

namespace nsCppParser
{
    void TTypeReference::SetupTemplates()
    {
        originalTemplates.clear();

        const char COMMA = ',';
        const char LESS = '<';
        const char GREATER = '>';

        size_t currentIndex = 0;
        size_t elementIndex = 0;
        int cornerCount = 0;
        for (auto s : mOriginalName) {

            switch (s) {
                case COMMA:
                    if (cornerCount == 1) {
                        originalTemplates.push_back(mOriginalName.substr(elementIndex, currentIndex - elementIndex));
                        elementIndex = currentIndex + 1;
                    }
                    break;
                case LESS:
                    if (cornerCount == 0) {
                        elementIndex = currentIndex + 1;
                    }
                    cornerCount++;
                    break;
                case GREATER:
                    cornerCount--;
                    if (cornerCount == 0) {
                        originalTemplates.push_back(mOriginalName.substr(elementIndex, currentIndex - elementIndex));
                    }
                    break;
                default:;
            }

            currentIndex++;
        }

        for (auto& templateStr : originalTemplates) {
            TStringExtensions::TrimRight(templateStr, " ");

        }
    }
}