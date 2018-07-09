/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ContainerContextSc.h"

using namespace nsMMOEngine;

//------------------------------------------------------------
TContainerContextSc::TContainerContextSc()
{
  mManagerContextSc = NULL;

  mListContext.push_back( &mDisClient );
  mListContext.push_back( &mFlow );
  mListContext.push_back( &mLoginClient );
  mListContext.push_back( &mLoginSlave );
  mListContext.push_back( &mLoginMaster );
  mListContext.push_back( &mRcm );
  mListContext.push_back( &mSynchroSlave );
  mListContext.push_back( &mSendToClient );

  mID_Session = 0;
}
//------------------------------------------------------------
void TContainerContextSc::SetSessionID( unsigned int sessionID )
{
  mID_Session = sessionID;
  for( auto p : mListContext )
    p->SetSessionID( sessionID );
}
//------------------------------------------------------------
unsigned int TContainerContextSc::GetSessionID()
{
  return mID_Session;
}
//------------------------------------------------------------
void TContainerContextSc::SetMCSc( TScContextManager* pMCSc )
{
  mManagerContextSc = pMCSc;

  for( auto p : mListContext )
    p->SetMSc( mManagerContextSc );
}
//------------------------------------------------------------
void TContainerContextSc::SetMS( TSessionManager* pMS )
{
  for( auto p : mListContext )
    p->SetMS( pMS );
}
//------------------------------------------------------------
void TContainerContextSc::SetSE( TSrcEvent* pSE )
{
  for( auto p : mListContext )
    p->SetSE( pSE );
}
//------------------------------------------------------------
void TContainerContextSc::SetUserPtr( void* p )
{
  for( auto p : mListContext )
    p->SetUserPtr( p );
}
//------------------------------------------------------------
TScContextManager* TContainerContextSc::GetMCSc()
{
  return mManagerContextSc;
}
//------------------------------------------------------------
bool TContainerContextSc::IsRcmActive()
{
  if( GetMCSc()->GetActive() == &mRcm )
    return true;
  return false;
}
//------------------------------------------------------------
bool TContainerContextSc::IsLoginClientActive()
{
  if( GetMCSc()->GetActive() == &mLoginClient )
    return true;
  return false;
}
//------------------------------------------------------------
