/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Pattern_Tank.h"

namespace nsPattern_Tank
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_Tank;

TPattern_Tank::TPattern_Tank() :
	TPattern_Model(&g_DefaultParameterMap)
{

}
//-------------------------------------------------------------------
TPattern_Tank::~TPattern_Tank()
{

}
//-------------------------------------------------------------------
