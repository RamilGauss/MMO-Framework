/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Chassis.h"

namespace nsPatternModel_Chassis
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Chassis;

TPatternModel_Chassis::TPatternModel_Chassis() :
	TPatternModel_Model(&g_DefaultParameterMap)
{

}
//-------------------------------------------------------------------
TPatternModel_Chassis::~TPatternModel_Chassis()
{

}
//-------------------------------------------------------------------
