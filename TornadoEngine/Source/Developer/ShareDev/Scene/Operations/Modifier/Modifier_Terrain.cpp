/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Modifier_Terrain.h"

TModifier_Terrain::TDescTarget::TDescTarget()
{
  worldSizePart = 1;
  sizePart = 3;
  
  height     = 0;
  inputScale = 33;
  inputBias  = 33;
}
//------------------------------------------------------------------------
TModifier_Terrain::TModifier_Terrain()
{
}
//------------------------------------------------------------------------
