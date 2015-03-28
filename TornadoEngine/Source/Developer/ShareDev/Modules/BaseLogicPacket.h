/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BaseLogicPacketH
#define BaseLogicPacketH

#include "TypeDef.h"

struct DllExport TBaseLogicPacket
{
	TBaseLogicPacket();
	int type;
};

namespace nsBaseLogicPacket
{
	enum
	{
		eUndef,
		eCallBack0,
	};
};

#endif
