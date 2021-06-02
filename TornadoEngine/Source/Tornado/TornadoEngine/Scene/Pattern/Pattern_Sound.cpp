/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Pattern_Sound.h"

namespace nsPattern_Sound
{
  static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_Sound;

TPattern_Sound::TPattern_Sound() :
  TBehaviourPattern(&g_DefaultParameterMap)
{

}
//---------------------------------------------------------------------------
TPattern_Sound::~TPattern_Sound()
{

}
//---------------------------------------------------------------------------
TPatternNameManager::eBaseType TPattern_Sound::GetBaseType()
{
  return TPatternNameManager::eSound;
}
//------------------------------------------------------------------------
