/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SessionNavigator.h"
#include "Session.h"
#include "Logger.h"
#include "Base.h"

using namespace std;

using namespace nsMMOEngine;

TSessionNavigator::TSessionNavigator()
{

}
//--------------------------------------------------------------
TSessionNavigator::~TSessionNavigator()
{
  Clear();
}
//--------------------------------------------------------------
void TSessionNavigator::Add( TSession* pSession )
{
  TIP_Port ip_port;
  pSession->GetInfo( ip_port );
  mMapID_Session.insert( TMapUintPtrVT( pSession->GetID(), pSession ) );
  mMapIP_Session.insert( TMapIP_PtrItVT( ip_port, pSession ) );
  mSetSession.insert( pSession );
}
//--------------------------------------------------------------
void TSessionNavigator::Delete( TSession* pSession )
{
  TIP_Port ip_port;
  pSession->GetInfo( ip_port );
  mMapIP_Session.erase( ip_port );
  mMapID_Session.erase( pSession->GetID() );
  mSetSession.erase( pSession );
  delete pSession;
}
//--------------------------------------------------------------
TSession* TSessionNavigator::FindSessionByIP( TIP_Port& ip_port )
{
  TSession* pSession = NULL;
  TMapIP_PtrIt fit = mMapIP_Session.find( ip_port );
  if( fit != mMapIP_Session.end() )
    pSession = fit->second;
  return pSession;
}
//--------------------------------------------------------------
TSession* TSessionNavigator::FindSessionByID( unsigned int id )
{
  TSession* pSession = NULL;
  TMapUintPtrIt fit = mMapID_Session.find( id );
  if( fit != mMapID_Session.end() )
    pSession = fit->second;
  return pSession;
}
//--------------------------------------------------------------
bool TSessionNavigator::IsExist( TSession* pSession )
{
  return (mSetSession.find( pSession ) != mSetSession.end());
}
//--------------------------------------------------------------
set<TSession*>::iterator TSessionNavigator::Begin()
{
  return mSetSession.begin();
}
//--------------------------------------------------------------
set<TSession*>::iterator TSessionNavigator::End()
{
  return mSetSession.end();
}
//--------------------------------------------------------------
void TSessionNavigator::Work()
{
  for( TSession* pSession : mSetSession )
    pSession->Work();
}
//--------------------------------------------------------------
void TSessionNavigator::Clear()
{
  for( TSession* pSession : mSetSession )
    delete pSession;
  mSetSession.clear();
}
//--------------------------------------------------------------
