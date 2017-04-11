/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Gun.h"

namespace nsPatternModel_Gun
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Gun;

TPatternModel_Gun::TPatternModel_Gun() : 
	TPatternModel_Model(&g_DefaultParameterMap)
{

}
//-------------------------------------------------------------------
TPatternModel_Gun::~TPatternModel_Gun()
{

}
//-------------------------------------------------------------------
