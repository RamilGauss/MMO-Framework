/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/SingletonManager.h"

#include "ReflectionCodeGeneratorLib/Sources/IGenerator.h"

using namespace nsReflectionCodeGenerator;

void IGenerator::SetTypeManager(TTypeManager* typeManager)
{
    mTypeManager = typeManager;
}
//----------------------------------------------------------------------------------
void IGenerator::SetResolvedConfig(TResolvedConfig* resolvedConfig)
{
    mResolvedConfig = resolvedConfig;
}
//----------------------------------------------------------------------------------
