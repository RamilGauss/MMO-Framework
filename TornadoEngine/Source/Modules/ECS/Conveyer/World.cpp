#include "World.h"
#include "IConveyerPart.h"

using namespace MWorks::ECS;

TWorld::TWorld()
{
  SetRegistry(new THugeRegistry());
}
//--------------------------------------------------------------------------------------
