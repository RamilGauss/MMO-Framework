/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Pattern_Animated.h"

namespace nsPattern_Light
{
  static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_Light;

TPattern_Animated::TPattern_Animated() : 
  TBehaviourPattern(&g_DefaultParameterMap)
{

}
//---------------------------------------------------------------------------
TPattern_Animated::~TPattern_Animated()
{

}
//---------------------------------------------------------------------------
TPatternNameManager::eBaseType TPattern_Animated::GetBaseType()
{
  return TPatternNameManager::eAnimated;
}
//------------------------------------------------------------------------
