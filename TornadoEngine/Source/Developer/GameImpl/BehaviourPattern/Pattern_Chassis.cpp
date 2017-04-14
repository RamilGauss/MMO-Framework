/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Pattern_Chassis.h"

namespace nsPattern_Chassis
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_Chassis;

TPattern_Chassis::TPattern_Chassis() :
	TPattern_Model(&g_DefaultParameterMap)
{

}
//-------------------------------------------------------------------
TPattern_Chassis::~TPattern_Chassis()
{

}
//-------------------------------------------------------------------
