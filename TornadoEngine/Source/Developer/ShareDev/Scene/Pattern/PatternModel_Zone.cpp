/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Zone.h"

namespace nsPatternModel_Zone
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Zone;

TPatternModel_Zone::TPatternModel_Zone() :
	TBehaviourPatternModel(&g_DefaultParameterMap)
{

}
//---------------------------------------------------------------------------
TPatternModel_Zone::~TPatternModel_Zone()
{

}
//---------------------------------------------------------------------------
