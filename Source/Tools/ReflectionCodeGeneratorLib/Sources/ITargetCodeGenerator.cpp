/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ITargetCodeGenerator.h"
#include "Base/Common/SingletonManager.h"
#include "ConfigContainer.h"

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
TSerializer* ITargetCodeGenerator::GetSerializer()
{
    auto fit = mConfig->targetForCodeGeneration.implementations.find(mName);
    if (fit == mConfig->targetForCodeGeneration.implementations.end()) {
        return nullptr;
    }
    return &(fit->second);
}
//----------------------------------------------------------------------------------
