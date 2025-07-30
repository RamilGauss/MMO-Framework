/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/SingletonManager.h"

#include "ReflectionCodeGeneratorLib/Sources/IGenerator.h"
#include "ReflectionCodeGeneratorLib/Sources/ConfigContainer.h"

using namespace nsReflectionCodeGenerator;

IGenerator::IGenerator()
{
    mTypeManager = SingletonManager()->Get<TTypeManager>();
    mConfig = SingletonManager()->Get<TConfigContainer>()->Config();
    mCache = SingletonManager()->Get<TCache>();
}
//----------------------------------------------------------------------------------
