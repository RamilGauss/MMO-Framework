/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeManager.h"

using namespace nsReflectionCodeGenerator;

void TTypeManager::Add(nsCppParser::TTypeInfo* typeInfo)
{
    mFullNameTypeMap.insert({typeInfo->GetTypeNameWithNameSpace(), typeInfo});
}
//--------------------------------------------------------------------------------------------------------
nsCppParser::TTypeInfo* TTypeManager::Get(const std::string& fullTypeName)
{
    auto fit = mFullNameTypeMap.find(fullTypeName);
    if (fit != mFullNameTypeMap.end()) {
        return fit->second;
    }
    return nullptr;
}
//--------------------------------------------------------------------------------------------------------