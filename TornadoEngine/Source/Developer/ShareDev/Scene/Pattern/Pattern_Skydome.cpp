/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Pattern_Skydome.h"

namespace nsPattern_Skypdome
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_Skypdome;

TPattern_Skydome::TPattern_Skydome() :
	TBehaviourPattern(&g_DefaultParameterMap)
{

}
//---------------------------------------------------------------------------
TPattern_Skydome::~TPattern_Skydome()
{

}
//---------------------------------------------------------------------------
TManagerNamePattern::eBaseType TPattern_Skydome::GetBaseType()
{
	return TManagerNamePattern::eSky;
}
//------------------------------------------------------------------------
