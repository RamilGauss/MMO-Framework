/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "TestControlTank.h"
#include "TankTower.h"
#include "HiTimer.h"
#include "BL_Debug.h"
#include "BreakPacket.h"
#include "..\..\GameLib\IServerDeveloperTool.h"
#include "BaseServer.h"
#include <list>

using namespace nsMMOEngine;

// формула для аппроксимации параметров в будущее
// x = x0 + v * ( now - time_recv )


//---------------------------------------------------------------------------
TTestControlTank::TTestControlTank():
mDesc(new TDesc)
{
	mTank	             = NULL;
	mTimeLastUpdate_ms = 0;
	mTimeRecv_ms       = 0;
}
//---------------------------------------------------------------------------
void TTestControlTank::SetTank(TTankTower* pTank)
{
	mTank = pTank;
}
//---------------------------------------------------------------------------
void TTestControlTank::SetupParamForNow()
{
	unsigned int now_ms = ht_GetMSCount();
	unsigned int delta = now_ms - mTimeRecv_ms;

	float angleGun    = mDesc->mAngleGun    + delta * mDesc->mSpeedRotateGun;
	float angleTurret = mDesc->mAngleTurret + delta * mDesc->mSpeedRotateTurret;

	mTank->RotateTurret(angleTurret);
	mTank->RotateVerticalGun(angleGun);
}
//---------------------------------------------------------------------------
void TTestControlTank::Recv(void* data, int size)
{
	if(size!=sizeof(TDesc))
	{
		BL_FIX_BUG();
		return;
	}
	//*(mDesc) = *((TDesc*)data);
	memcpy(mDesc.get(), data, size);
	mTimeRecv_ms = ht_GetMSCount();
}
//---------------------------------------------------------------------------
void TTestControlTank::Send()
{
	lockQtSend();
	//----------------------------
	UpdateAngle();
	TBreakPacket bp;
	bp.PushFront((char*)mDesc.get(), sizeof(TDesc));

	IServerDeveloperTool::TComponentServer* pComponent = 
		IServerDeveloperTool::Singleton()->GetComponent();
	TBaseServer* pBS = (TBaseServer*)pComponent->mNet.Base;

	std::list<unsigned int> listKey;
	//###
	// рассылка всем клиентам
	TSlave::TDescDownSlave descDown;
	int sizeDesc = sizeof(descDown);
	int countClient = pComponent->mNet.Slave->GetCountDown();
	for( int iClient = 0 ; iClient < countClient ; iClient++)
	{
		//if(pComponent->mNet.Slave->GetDescDown(iClient, (void*)&descDown, sizeDesc))
			//pBS->SendDown( descDown.id_session, bp);
		if(pComponent->mNet.Slave->GetDescDown(iClient, (void*)&descDown, sizeDesc))
		{
			unsigned int id_client;
			if(pComponent->mNet.Slave->FindClientKeyBySession(descDown.id_session,id_client))
				listKey.push_back(id_client);
		}
	}
	pBS->SendByClientKey( listKey, bp);
	//###
  //----------------------------
	unlockQtSend();
}
//---------------------------------------------------------------------------
void TTestControlTank::SetSpeedRotateTurret(float v)
{
	lockQtSend();
	mDesc->mSpeedRotateTurret = v;
	unlockQtSend();
}
//---------------------------------------------------------------------------
void TTestControlTank::SetSpeedRotateGun(float v)
{
	lockQtSend();
	mDesc->mSpeedRotateGun = v;
	unlockQtSend();
}
//---------------------------------------------------------------------------
void TTestControlTank::UpdateAngle()
{
	unsigned int now_ms = ht_GetMSCount();
	unsigned int delta = (mTimeLastUpdate_ms==0) ? 0:
												now_ms - mTimeLastUpdate_ms;
	
	mDesc->mAngleGun    = mDesc->mAngleGun    + delta * mDesc->mSpeedRotateGun;
	mDesc->mAngleTurret = mDesc->mAngleTurret + delta * mDesc->mSpeedRotateTurret;

	mTimeLastUpdate_ms = now_ms;
}
//---------------------------------------------------------------------------
