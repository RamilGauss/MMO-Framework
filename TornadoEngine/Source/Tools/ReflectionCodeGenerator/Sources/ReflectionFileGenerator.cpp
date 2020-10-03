/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ReflectionFileGenerator.h"

using namespace nsReflectionCodeGenerator;

TReflectionFileGenerator::TReflectionFileGenerator()
{
    mReflectionConfig = mConfig->targetForCodeGeneration.implementation.reflection.get();
}
//----------------------------------------------------------------------------------------------------
