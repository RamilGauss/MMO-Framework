/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Animated.h"

namespace nsPatternModel_Light
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Light;

TPatternModel_Animated::TPatternModel_Animated() : 
	TBehaviourPatternModel(&g_DefaultParameterMap)
{

}
//---------------------------------------------------------------------------
TPatternModel_Animated::~TPatternModel_Animated()
{

}
//---------------------------------------------------------------------------
