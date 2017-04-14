/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Pattern_Gun.h"

namespace nsPattern_Gun
{
	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_Gun;

TPattern_Gun::TPattern_Gun() : 
	TPattern_Model(&g_DefaultParameterMap)
{

}
//-------------------------------------------------------------------
TPattern_Gun::~TPattern_Gun()
{

}
//-------------------------------------------------------------------
