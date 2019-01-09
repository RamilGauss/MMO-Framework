/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IGenerator.h"
#include "SingletonManager.h"
#include "ConfigContainer.h"

using namespace nsReflectionCodeGenerator;

IGenerator::IGenerator()
{
  mConfig = SingletonManager()->Get<nsReflectionCodeGenerator::TConfigContainer>()->Config();
  mTypeMng = SingletonManager()->Get<TTypeManager>();
}
//----------------------------------------------------------------------------------
