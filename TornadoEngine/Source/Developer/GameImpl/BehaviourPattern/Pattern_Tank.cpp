/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Pattern_Tank.h"

namespace nsPattern_Tank
{
  static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_Tank;

TPattern_Tank::TPattern_Tank() :
  TPattern_Model(&g_DefaultParameterMap)
{

}
//-------------------------------------------------------------------
TPattern_Tank::~TPattern_Tank()
{

}
//-------------------------------------------------------------------
void TPattern_Tank::SetAccelerate(float power, float speedLinim)
{
  // внутренняя логика расчета крутящего момента для шасси
  // все зависит от скорости и кол-ва передач в коробке

}
//-------------------------------------------------------------------
void TPattern_Tank::SetMouseAim(nsMathTools::TOrientation& orient)
{

}
//-------------------------------------------------------------------
bool TPattern_Tank::GetRealMouseAim(nsMathTools::TOrientation& orient)
{
  return false;
}
//-------------------------------------------------------------------
