/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Turret.h"

namespace nsPatternModel_Turret
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Turret;

TPatternModel_Turret::TPatternModel_Turret() :
	TPatternModel_Model(&g_DefaultParameterMap)
{

}
//-------------------------------------------------------------------
TPatternModel_Turret::~TPatternModel_Turret()
{

}
//-------------------------------------------------------------------
