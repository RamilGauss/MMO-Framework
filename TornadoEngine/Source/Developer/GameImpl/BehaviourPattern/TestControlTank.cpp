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
#include <list>
#include "DevTool_Share.h"
#include "MMOEngine/include/Slave.h"

// формула для аппроксимации параметров в будущее
// x = x0 + v * ( now - time_recv )


//---------------------------------------------------------------------------
TTestControlTank::TTestControlTank()
{
  mTank = NULL;
  mTimeLastUpdate_ms = 0;
  mTimeRecv_ms = 0;
}
//---------------------------------------------------------------------------
void TTestControlTank::SetTank( TTankTower* pTank )
{
  mTank = pTank;
}
//---------------------------------------------------------------------------
void TTestControlTank::SetupParamForNow()
{
  unsigned int now_ms = ht_GetMSCount();
  unsigned int delta = now_ms - mTimeRecv_ms;

  float angleGun = mDesc.mAngleGun + delta * mDesc.mSpeedRotateGun;
  float angleTurret = mDesc.mAngleTurret + delta * mDesc.mSpeedRotateTurret;

  mTank->RotateTurret( angleTurret );
  mTank->RotateVerticalGun( angleGun );
}
//---------------------------------------------------------------------------
void TTestControlTank::Recv( void* data, int size )
{
  if ( size != sizeof( TDesc ) )
  {
    BL_FIX_BUG();
    return;
  }
  //*(mDesc) = *((TDesc*)data);
  memcpy( &mDesc, data, size );
  mTimeRecv_ms = ht_GetMSCount();
}
//---------------------------------------------------------------------------
void TTestControlTank::Send()
{
  //lockQtSend();
  ////----------------------------
  //UpdateAngle();
  //TBreakPacket bp;
  //bp.PushFront((char*)mDesc.get(), sizeof(TDesc));

  //TDevTool_Share::TComponent* pComponent = TDevTool_Share::Singleton()->GetComponent();
 // nsMMOEngine::TBaseServer* pBS = (nsMMOEngine::TBaseServer*)pComponent->mMMO;

  //std::list<unsigned int> listKey;
  ////###
  //// рассылка всем клиентам
  //nsMMOEngine::TSlave::TDescDownSlave descDown;
  //int sizeDesc = sizeof(descDown);
  //int countClient = pComponent->mSlave->Get()->GetCountDown();
  //for( int iClient = 0 ; iClient < countClient ; iClient++)
  //{
  //  //if(pComponent->mNet.Slave->GetDescDown(iClient, (void*)&descDown, sizeDesc))
  //    //pBS->SendDown( descDown.sessionID, bp);
  //  if(pComponent->mSlave->Get()->GetDescDown(iClient, (void*)&descDown, sizeDesc))
  //  {
  //    unsigned int clientKey;
  //    if(pComponent->mSlave->Get()->FindClientKeyBySession(descDown.sessionID,clientKey))
  //      listKey.push_back(clientKey);
  //  }
  //}
  //pBS->SendByClientKey( listKey, bp);
  ////###
 // //----------------------------
  //unlockQtSend();
}
//---------------------------------------------------------------------------
void TTestControlTank::SetSpeedRotateTurret( float v )
{
  lockQtSend();
  mDesc.mSpeedRotateTurret = v;
  unlockQtSend();
}
//---------------------------------------------------------------------------
void TTestControlTank::SetSpeedRotateGun( float v )
{
  lockQtSend();
  mDesc.mSpeedRotateGun = v;
  unlockQtSend();
}
//---------------------------------------------------------------------------
void TTestControlTank::UpdateAngle()
{
  unsigned int now_ms = ht_GetMSCount();
  unsigned int delta = ( mTimeLastUpdate_ms == 0 ) ? 0 : now_ms - mTimeLastUpdate_ms;

  mDesc.mAngleGun = mDesc.mAngleGun + delta * mDesc.mSpeedRotateGun;
  mDesc.mAngleTurret = mDesc.mAngleTurret + delta * mDesc.mSpeedRotateTurret;

  mTimeLastUpdate_ms = now_ms;
}
//---------------------------------------------------------------------------
