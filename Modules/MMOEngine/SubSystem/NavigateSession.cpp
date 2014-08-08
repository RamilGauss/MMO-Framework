/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "NavigateSession.h"
#include "Session.h"
#include "Logger.h"
#include "Base.h"

#include <boost/foreach.hpp>

using namespace std;

using namespace nsMMOEngine;

TNavigateSession::TNavigateSession()
{

}
//--------------------------------------------------------------
TNavigateSession::~TNavigateSession()
{
  Clear();
}
//--------------------------------------------------------------
void TNavigateSession::Add(TSession* pSession)
{
  TIP_Port ip_port;
  pSession->GetInfo(ip_port);
  mMapID_Session.insert(TMapUintPtrVT(pSession->GetID(), pSession));
  mMapIP_Session.insert(TMapIP_PtrItVT(ip_port,          pSession));
  mSetSession.insert(pSession);
}
//--------------------------------------------------------------
void TNavigateSession::Delete(TSession* pSession)
{
  TIP_Port ip_port;
  pSession->GetInfo(ip_port);
  mMapIP_Session.erase(ip_port);
  mMapID_Session.erase(pSession->GetID());
  mSetSession.erase(pSession);
  delete pSession;
}
//--------------------------------------------------------------
TSession* TNavigateSession::FindSessionByIP(TIP_Port& ip_port)
{
  TSession* pSession = NULL;
  TMapIP_PtrIt fit = mMapIP_Session.find(ip_port);
  if(fit!=mMapIP_Session.end())
    pSession = fit->second;
  return pSession;
}
//--------------------------------------------------------------
TSession* TNavigateSession::FindSessionByID(unsigned int id)
{
  TSession* pSession = NULL;
  TMapUintPtrIt fit = mMapID_Session.find(id);
  if(fit!=mMapID_Session.end())
    pSession = fit->second;
  return pSession;
}
//--------------------------------------------------------------
bool TNavigateSession::IsExist(TSession* pSession)
{
  return (mSetSession.find(pSession)!=mSetSession.end());
}
//--------------------------------------------------------------
set<TSession*>::iterator TNavigateSession::Begin()
{
  return mSetSession.begin();
}
//--------------------------------------------------------------
set<TSession*>::iterator TNavigateSession::End()
{
  return mSetSession.end();
}
//--------------------------------------------------------------
void TNavigateSession::Work()
{
  BOOST_FOREACH(TSession* pSession, mSetSession)
    pSession->Work();
}
//--------------------------------------------------------------
void TNavigateSession::Clear()
{
  BOOST_FOREACH(TSession* pSession,mSetSession)
    delete pSession;
  mSetSession.clear();
}
//--------------------------------------------------------------
