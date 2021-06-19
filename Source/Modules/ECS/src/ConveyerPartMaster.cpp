/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ConveyerPartMaster.h"

using namespace nsECSFramework;

void TConveyerPartMaster::Init()
{
  // весь конвейер находится здесь
  mReactiveInitializer->InitSystems();
  mInitAndExecuteInitializer->InitSystems();
}
//--------------------------------------------------------------------------
void TConveyerPartMaster::Update()
{
  // весь конвейер находится здесь
  mSystemUpdater->UpdateSystems();
}
//--------------------------------------------------------------------------
