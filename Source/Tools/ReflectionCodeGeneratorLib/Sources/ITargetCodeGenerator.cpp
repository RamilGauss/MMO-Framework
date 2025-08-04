/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/SingletonManager.h"

#include "ReflectionCodeGeneratorLib/Sources/ITargetCodeGenerator.h"

using namespace nsReflectionCodeGenerator;

ITargetCodeGenerator::ITargetCodeGenerator(const std::string& name) :
    ICodeGenerator(name)
{

}
//----------------------------------------------------------------------------------
TTypeNameDataBase* ITargetCodeGenerator::GetTypeNameDB()
{
    return &mTypeNameDB;
}
//----------------------------------------------------------------------------------
bool ITargetCodeGenerator::HasSerializer()
{
    return GetSerializer() != nullptr;
}
//----------------------------------------------------------------------------------
TSerializerExt* ITargetCodeGenerator::GetSerializer()
{
    auto fit = mResolvedConfig->implementations.find(mName);
    if (fit == mResolvedConfig->implementations.end()) {
        return nullptr;
    }
    return &(fit->second);
}
//----------------------------------------------------------------------------------
