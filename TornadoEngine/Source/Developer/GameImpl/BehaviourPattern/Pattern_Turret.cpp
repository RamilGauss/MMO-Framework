/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Pattern_Turret.h"

namespace nsPattern_Turret
{
  static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_Turret;

TPattern_Turret::TPattern_Turret() :
  TPattern_Model(&g_DefaultParameterMap)
{

}
//-------------------------------------------------------------------
TPattern_Turret::~TPattern_Turret()
{

}
//-------------------------------------------------------------------
