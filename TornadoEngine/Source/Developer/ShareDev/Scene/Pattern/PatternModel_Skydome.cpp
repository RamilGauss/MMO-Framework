/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Skydome.h"

namespace nsPatternModel_Skypdome
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Skypdome;

TPatternModel_Skydome::TPatternModel_Skydome() :
	TBehaviourPatternModel(&g_DefaultParameterMap)
{

}
//---------------------------------------------------------------------------
TPatternModel_Skydome::~TPatternModel_Skydome()
{

}
//---------------------------------------------------------------------------
