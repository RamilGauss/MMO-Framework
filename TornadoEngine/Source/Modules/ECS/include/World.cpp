#include "World.h"
#include "IConveyerPart.h"

using namespace nsECSFramework;

TWorld::TWorld()
{
  SetRegistry( new THugeRegistry() );
}
//--------------------------------------------------------------------------------------
