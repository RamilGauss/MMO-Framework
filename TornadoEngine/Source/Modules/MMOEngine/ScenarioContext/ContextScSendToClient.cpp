/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ContextScSendToClient.h"
#include <boost/foreach.hpp>
#include "BL_Debug.h"
#include "SessionManager.h"

using namespace nsMMOEngine;

TContextScSendToClient::TContextScSendToClient()
{

}
//------------------------------------------------------------------
void TContextScSendToClient::SaveBreakPacket(TBreakPacket& bp)
{
  auto pDescSP = TMemoryPool<TSavePacket>::Singleton()->Pop(1);
  auto pSP = pDescSP->p;
  // собрать пакет
  bp.CopyInBuffer(pSP->c);

  mListSave.push_back(pDescSP);
}
//------------------------------------------------------------------
void TContextScSendToClient::SendAndRemoveFirst()
{
  if(mListSave.size()==0)
  {
    // не ожидали
    BL_FIX_BUG();
    return;
  }

  auto pDescSP = mListSave.front();
  mListSave.pop_front();

  unsigned int id_session = GetID_Session();

  mBP.Reset();
  auto pSP = pDescSP->p;
  mBP.PushFront( pSP->c.GetPtr(), pSP->c.GetSize());
  GetMS()->Send( id_session, mBP );

  TMemoryPool<TSavePacket>::Singleton()->Push(pDescSP);
}
//------------------------------------------------------------------

