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
