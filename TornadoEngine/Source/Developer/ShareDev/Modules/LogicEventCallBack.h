/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef LogicEventCallBackH
#define LogicEventCallBackH

#include "BaseLogicPacket.h"
#include "CallBackRegistrator.h"

struct DllExport TLogicEventCallBack : public TBaseLogicPacket
{
	TLogicEventCallBack()
	{
		type = nsBaseLogicPacket::eCallBack0;
	}
	TCallBackRegistrator0 mCB; 
};

#endif
