/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ManagerContextDownConnection_Slave.h"

#include <algorithm>

#include "Logger.h"
#include "ContainerContextSc.h"
#include "Base.h"
#include "BL_Debug.h"

using namespace nsMMOEngine;

TManagerContextDownConnection_Slave::TManagerContextDownConnection_Slave( TBase* pBase ) :
  TManagerContextDownConnection( pBase )
{

}
//---------------------------------------------------------------------------------------
TManagerContextDownConnection_Slave::~TManagerContextDownConnection_Slave()
{

}
//---------------------------------------------------------------------------------------
void TManagerContextDownConnection_Slave::AddSessionEvent( unsigned int sessionID )
{
  mMapSessionLoadProcent.insert( TMapUintUchar::value_type( sessionID, 0 ) );
}
//---------------------------------------------------------------------------------------
void TManagerContextDownConnection_Slave::DeleteSessionEvent( unsigned int sessionID )
{
  mMapSessionLoadProcent.erase( sessionID );
}
//---------------------------------------------------------------------------------------
bool TManagerContextDownConnection_Slave::FindMinimumLoad( unsigned int& sessionID, unsigned char& load_procent )
{
  if ( mMapSessionLoadProcent.size() == 0 )
    return false;

  mVecDesc.clear();
  for ( auto& it : mMapSessionLoadProcent )
    mVecDesc.push_back( TDesc( it.second, it.first ) );

  std::sort( mVecDesc.begin(), mVecDesc.end() );
  sessionID = mVecDesc[0].sessionID;
  load_procent = mVecDesc[0].load_procent;
  //###
  // для теста объединения из разных Slave
  //sessionID   = mVecDesc[mVecDesc.size()-1].sessionID; 
  //load_procent = mVecDesc[mVecDesc.size()-1].load_procent;
  //###
  return true;
}
//---------------------------------------------------------------------------------------
void TManagerContextDownConnection_Slave::SetLoadBySession( unsigned int sessionID, unsigned char load_procent )
{
  TMapUintUcharIt fit = mMapSessionLoadProcent.find( sessionID );
  if ( fit == mMapSessionLoadProcent.end() )
  {
    BL_FIX_BUG();
    return;
  }
  fit->second = load_procent;
}
//---------------------------------------------------------------------------------------
bool TManagerContextDownConnection_Slave::FindLoadBySession( unsigned int sessionID, unsigned char& load_procent )
{
  TMapUintUcharIt fit = mMapSessionLoadProcent.find( sessionID );
  if ( fit == mMapSessionLoadProcent.end() )
    return false;
  load_procent = fit->second;
  return true;
}
//---------------------------------------------------------------------------------------
