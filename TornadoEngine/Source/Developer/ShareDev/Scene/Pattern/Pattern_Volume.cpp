/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Pattern_Volume.h"

namespace nsPattern_Volume
{
  static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_Volume;

TPattern_Volume::TPattern_Volume() :
  TBehaviourPattern(&g_DefaultParameterMap)
{

}
//---------------------------------------------------------------------------
TPattern_Volume::~TPattern_Volume()
{

}
//---------------------------------------------------------------------------
TPatternNameManager::eBaseType TPattern_Volume::GetBaseType()
{
  return TPatternNameManager::eVolume;
}
//------------------------------------------------------------------------
