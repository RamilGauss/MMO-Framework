/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleClientLogic_Dev.h"
#include "ListModules.h"
#include "LogicEventCallBack.h"
#include "ModuleTimer.h"

bool TModuleClientLogic_Dev::WorkClient()
{
  return true;
}
//----------------------------------------------------------
void TModuleClientLogic_Dev::Input(int id, void* p, int size)
{
	switch(id)
	{
		case nsListModules::GraphicEngine:
			break;
    case nsListModules::MMOEngineClient:
			break;
    case nsListModules::PhysicEngine:
			break;
    case nsListModules::SoundEngine:
			break;
    case nsListModules::DataBase:
			break;
    case nsListModules::Timer:
			{
				// события от таймера
				int a = 0;
			}
			break;
	}
}
//----------------------------------------------------------
void TModuleClientLogic_Dev::StartEvent()
{
	TLogicEventCallBack* pLCB = new TLogicEventCallBack;
	pLCB->mCB.Register( &TModuleClientLogic_Dev::StartTimer, this);
	TSynchroAbonent::AddEventWithoutCopy(nsListModules::Timer, pLCB);
}
//----------------------------------------------------------
void TModuleClientLogic_Dev::StartTimer()
{
	// вызовется из потока таймера
	unsigned int mID_Timer = mComp.pTimer->New(5000);
}
//----------------------------------------------------------
