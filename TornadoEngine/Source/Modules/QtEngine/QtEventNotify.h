/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef QtEventNotifyH
#define QtEventNotifyH

#include "TypeDef.h"

#include <QEvent>
#include "CallBackRegistrator.h"

class DllExport TQtEventNotify : public QEvent
{
public:
	enum
	{
		TypeEvent = QEvent::User + 1,
	};
	TQtEventNotify() : QEvent((QEvent::Type)TypeEvent)
	{}
	TCallBackRegistrator0 mCB;
};


#endif