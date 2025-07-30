/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Parser/Sources/MemberInfo.h"

using namespace nsCppParser;

void TMemberInfo::CreateExtArray(std::vector<TMemberExtendedTypeInfo>& arr)
{
    arr.clear();
    auto pExt = &mExtendedInfo;
    arr.push_back(*pExt);
    while (pExt->mTemplateChildArr.size() > 0) {

        size_t lastIndex = 0;
        if (pExt->mCategory == TypeCategory::MAP) {
            lastIndex = 1;
        }

        pExt = &(pExt->mTemplateChildArr[lastIndex]);
        arr.push_back(*pExt);
    }
}
