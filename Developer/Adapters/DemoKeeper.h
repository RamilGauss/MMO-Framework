/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef __DEMO_KEEPER_H__
#define __DEMO_KEEPER_H__

#include "BaseManager.h"

namespace demo
{

	class DemoKeeper :
		public base::BaseManager
	{
	public:
		virtual void createScene();
		virtual void destroyScene();

	private:
		virtual void setupResources();
	};

} // namespace demo

#endif // __DEMO_KEEPER_H__
