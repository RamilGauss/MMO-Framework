/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerLoginingClientsOnSlave.h"
#include "BL_Debug.h"

using namespace nsMMOEngine;

void TManagerLoginingClientsOnSlave::AddSlave( unsigned int slaveSessionID )
{
  if ( mSlaveSession_ClientSetMap.find( slaveSessionID ) == mSlaveSession_ClientSetMap.end() )
    mSlaveSession_ClientSetMap.erase( slaveSessionID );

  mSlaveSession_ClientSetMap.insert( {slaveSessionID, TUintSet()} );
}
//----------------------------------------------------------------------------------------------
void TManagerLoginingClientsOnSlave::RemoveSlave( unsigned int slaveSessionID )
{
  mSlaveSession_ClientSetMap.erase( slaveSessionID );
}
//----------------------------------------------------------------------------------------------
int TManagerLoginingClientsOnSlave::GetClientCountBySlave( unsigned int slaveSessionID )
{
  auto fit = mSlaveSession_ClientSetMap.find( slaveSessionID );
  if ( fit == mSlaveSession_ClientSetMap.end() )
    return 0;
  return fit->second.size();
}
//----------------------------------------------------------------------------------------------
void TManagerLoginingClientsOnSlave::AddClient( unsigned int slaveSessionID, unsigned int clientKey )
{
  auto fit = mSlaveSession_ClientSetMap.find( slaveSessionID );
  if ( fit == mSlaveSession_ClientSetMap.end() )
  {
    AddSlave( slaveSessionID );
    fit = mSlaveSession_ClientSetMap.find( slaveSessionID );
  }
  fit->second.insert( clientKey );

  AddClientKeySlaveSession( clientKey, slaveSessionID );
}
//----------------------------------------------------------------------------------------------
void TManagerLoginingClientsOnSlave::RemoveClient( unsigned int clientKey )
{
  unsigned int slaveSessionID;
  if( FindSlaveSessionByClientKey( clientKey, slaveSessionID ) == false )
  {
    BL_FIX_BUG();
    return;
  }

  auto fit = mSlaveSession_ClientSetMap.find( slaveSessionID );
  if ( fit == mSlaveSession_ClientSetMap.end() )
  {
    BL_FIX_BUG();
    return;
  }
  fit->second.erase( slaveSessionID );
}
//----------------------------------------------------------------------------------------------
bool TManagerLoginingClientsOnSlave::FindSlaveSessionByClientKey( unsigned int clientKey, unsigned int& slaveSessionID )
{
  auto fit = mClientKeySlaveSessionIDMap.find( clientKey );
  if ( fit == mClientKeySlaveSessionIDMap.end() )
    return false;
  slaveSessionID = fit->second;
  return true;
}
//----------------------------------------------------------------------------------------------
void TManagerLoginingClientsOnSlave::AddClientKeySlaveSession( unsigned int clientKey, unsigned int slaveSessionID )
{
  mClientKeySlaveSessionIDMap.insert( {clientKey, slaveSessionID} );
}
//----------------------------------------------------------------------------------------------
