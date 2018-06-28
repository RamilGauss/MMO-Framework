#include "ConveyerPartMaster.h"

using namespace MWorks::ECS;

void TConveyerPartMaster::Init()
{
  for (auto part : mInitVector)
  {
    part->Init();
  }
}
//--------------------------------------------------------------------------
void TConveyerPartMaster::Update()
{
  for (auto part : mUpdateVector)
  {
    part->Update();
  }
}
//--------------------------------------------------------------------------

