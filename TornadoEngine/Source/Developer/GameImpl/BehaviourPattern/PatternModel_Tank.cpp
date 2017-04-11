/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Tank.h"

namespace nsPatternModel_Tank
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Tank;

TPatternModel_Tank::TPatternModel_Tank() :
	TPatternModel_Model(&g_DefaultParameterMap)
{

}
//-------------------------------------------------------------------
TPatternModel_Tank::~TPatternModel_Tank()
{

}
//-------------------------------------------------------------------
