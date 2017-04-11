/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Sound.h"

namespace nsPatternModel_Sound
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Sound;

TPatternModel_Sound::TPatternModel_Sound() :
	TBehaviourPatternModel(&g_DefaultParameterMap)
{

}
//---------------------------------------------------------------------------
TPatternModel_Sound::~TPatternModel_Sound()
{

}
//---------------------------------------------------------------------------
