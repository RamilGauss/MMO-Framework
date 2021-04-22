/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ITargetCodeGenerator.h"
#include "SingletonManager.h"
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
bool ITargetCodeGenerator::IsWork()
{
    return GetSerializer() != nullptr;
}
//----------------------------------------------------------------------------------