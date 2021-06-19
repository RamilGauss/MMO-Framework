/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "StructPattern_Terrain.h"

using namespace nsStructPattern_Terrain;

THeightMapTerrain::THeightMapTerrain()
{
  size = 0;
  worldSize =0;
  inputScale = 0;
  inputBias = 0;
  pos = nsMathTools::TVector3(0,0,0);
}
//--------------------------------------------------------------------------------
TTerrainPart_Physic::TTerrainPart_Physic()
{
  Init();
}
//--------------------------------------------------------------------------------
void TTerrainPart_Physic::Init()
{
  pData = NULL;
  pRB   = NULL;
  pHeightfieldShape = NULL;
}
//--------------------------------------------------------------------------------
