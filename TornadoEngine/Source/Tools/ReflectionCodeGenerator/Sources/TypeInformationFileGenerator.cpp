/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TypeInformationFileGenerator.h"

using namespace nsReflectionCodeGenerator;

TTypeInformationFileGenerator::TTypeInformationFileGenerator()
{
    mTypeInformationConfig = mConfig->targetForCodeGeneration.implementation.typeInformation.get();
}
//----------------------------------------------------------------------------------------------------
