/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Queue2ThreadH
#define Queue2ThreadH

#include <memory.h>

#include "TypeDef.h"
#include "BL_Debug.h"
#include "HiTimer.h"
#include "Container.h"

/*
Класс для обмена данными между 2-мя потоками
В одном потоке всегда вызывается Pop или PopFresh
в другом всегда Push
FIFO

ThreadSafe Class

*/
#if defined( TD_WINDOWS )
#pragma pack(push, 1)
#endif

class SHARE_EI TQueue2Thread
{
	int mCount;

	TContainer* pQueue;

	int mBeginPos, // первый поток
			mEndPos;   // второй поток
	volatile int mCurrentCount;// используется в 2 потоках
public:
	TQueue2Thread(int queue_count);

	virtual ~TQueue2Thread();
	//Добавить элемент в очередь
	bool Push(void* buffer, int size);
	//Извлечь элемент из очереди
	bool Pop(void* buffer,int &size);

protected:
	//Очистка очереди
	void Clear();
};

#if defined( TD_WINDOWS )
#pragma pack(pop)
#endif


#endif
