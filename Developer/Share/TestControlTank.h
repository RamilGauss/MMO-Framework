/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef TestControlTankH
#define TestControlTankH

#include "Container.h"
#include "GCS.h"
#include <boost/smart_ptr/scoped_ptr.hpp>

class TTankTower;

// зародыш Developer протокола для управления танком


class TTestControlTank
{
#if defined( WIN32 )
#pragma pack(push, 1)
#endif
	struct TDesc
	{
		float mSpeedRotateTurret;
		float mAngleTurret;

		float mSpeedRotateGun;
		float mAngleGun;
    //###
    //char burn_memory[800000];
    //###

		TDesc()
		{
			mSpeedRotateTurret = 0;
			mAngleTurret    	 = 0;
			mSpeedRotateGun 	 = 0;
			mAngleGun       	 = 0;
		}
	};
#if defined( WIN32 )
#pragma pack(pop)
#endif

	TTankTower* mTank;

	unsigned int mTimeRecv_ms;
	unsigned int mTimeLastUpdate_ms;
	
	boost::scoped_ptr<TDesc> mDesc;

	GCS mMutexQtSend;

	void lockQtSend()  {mMutexQtSend.lock();}
	void unlockQtSend(){mMutexQtSend.unlock();}

public:
  TTestControlTank();

	// назначить объект
	void SetTank(TTankTower* pTank);
	// вызывать для аппроксимации параметров и применения для объекта
	void SetupParamForNow();
	
public:
	void Recv(void* data, int size);
	void Send();

	// реакция на нажатие кнопок в форме
	// задать скорость
	void SetSpeedRotateTurret(float v);
	void SetSpeedRotateGun(float v);
private:
	void UpdateAngle();
};


#endif