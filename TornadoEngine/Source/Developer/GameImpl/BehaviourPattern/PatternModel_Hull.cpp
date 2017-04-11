/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Hull.h"

namespace nsPatternModel_Hull
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Hull;

TPatternModel_Hull::TPatternModel_Hull() :
	TPatternModel_Model(&g_DefaultParameterMap)
{

}
//-------------------------------------------------------------------
TPatternModel_Hull::~TPatternModel_Hull()
{

}
//-------------------------------------------------------------------
