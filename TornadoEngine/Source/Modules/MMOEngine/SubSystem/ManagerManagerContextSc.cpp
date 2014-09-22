/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerManagerContextSc.h"
#include <boost/foreach.hpp>

using namespace nsMMOEngine;

TManagerManagerContextSc::TManagerManagerContextSc()
{

}
//-----------------------------------------------------------------------------
TManagerManagerContextSc::~TManagerManagerContextSc()
{
  BOOST_FOREACH( TManagerContextSc* pMSc, mSetManagerContextSc )
    delete pMSc;
  mSetManagerContextSc.clear();
}
//-----------------------------------------------------------------------------
TManagerContextSc* TManagerManagerContextSc::Add()
{
  TManagerContextSc* pMCSc = new TManagerContextSc();
  pMCSc->GetCallBackActivate()   ->Register(&TManagerManagerContextSc::ActiveEvent,this);
  pMCSc->GetCallBackDisactivate()->Register(&TManagerManagerContextSc::DisactiveEvent,this);
  mSetManagerContextSc.insert(pMCSc);
  return pMCSc;
}
//-----------------------------------------------------------------------------
void TManagerManagerContextSc::Remove(TManagerContextSc* pMCSc)
{
  mSetManagerContextSc.erase(pMCSc);
  mSetActiveManagerContextSc.erase(pMCSc);
  delete pMCSc;
}
//-----------------------------------------------------------------------------
void TManagerManagerContextSc::Work()
{
  TSetPtr copySetActiveManagerContextSc = mSetActiveManagerContextSc;
  BOOST_FOREACH( TManagerContextSc* pMSc, copySetActiveManagerContextSc )
    pMSc->Work();// работает только активный сценарий
}
//-----------------------------------------------------------------------------
void TManagerManagerContextSc::ActiveEvent(TManagerContextSc* pMCSc)
{
  mSetActiveManagerContextSc.insert(pMCSc);
}
//-----------------------------------------------------------------------------
void TManagerManagerContextSc::DisactiveEvent(TManagerContextSc* pMCSc)
{
  if(pMCSc->IsActive()==false)
    mSetActiveManagerContextSc.erase(pMCSc);
}
//-----------------------------------------------------------------------------
