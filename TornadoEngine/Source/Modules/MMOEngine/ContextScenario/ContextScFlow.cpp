/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ContextScFlow.h"
#include "ManagerSession.h"
#include <boost/foreach.hpp>
#include "BL_Debug.h"

using namespace nsMMOEngine;

TContextScFlow::TContextScFlow()
{

}  
//------------------------------------------------------------
TContextScFlow::~TContextScFlow()
{
  Done();
}  
//------------------------------------------------------------
void TContextScFlow::Done()
{
  BOOST_FOREACH(TSavePacket* pSP,mListSave)
    delete pSP;
}
//------------------------------------------------------------
void TContextScFlow::Send( TBreakPacket& bp, bool check)
{
  GetMS()->Send( GetID_Session(), bp, check);
}  
//------------------------------------------------------------
void TContextScFlow::SaveBreakPacket(TBreakPacket& bp, bool check)
{
  TSavePacket* pSP = new TSavePacket;
  // собрать пакет
  bp.Collect();
  // запомнить где находится собранный пакет
  char* p  = (char*)bp.GetCollectPtr();
  int size = bp.GetSize();
  // отцепиться от собранного пакета
  bp.UnlinkCollect();
  // отдать на хранение память пакета в контейнер
  pSP->c.EntrustByCount(p, size);
  pSP->check = check;

  mListSave.push_back(pSP);
}
//-------------------------------------------------------------------------
void TContextScFlow::SendAndRemoveFirst()
{
  if(mListSave.size()==0)
  {
    // не ожидали
    BL_FIX_BUG();
    return;
  }

  TSavePacket* pSP = mListSave.front();
  mListSave.pop_front();

  mBP.Reset();
  mBP.PushFront( pSP->c.GetPtr(), pSP->c.GetSize() );
  Send( mBP, pSP->check);
  delete pSP;
}
//-------------------------------------------------------------------------
