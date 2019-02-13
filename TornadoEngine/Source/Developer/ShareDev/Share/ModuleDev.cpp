/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ModuleDev.h"

TModuleDev::TModuleDev()
{
  mID = -1;
  mName = "";
}
//----------------------------------------------------------------------
bool TModuleDev::Work()
{
  bool res = WorkInherit();
  return res;
}
//----------------------------------------------------------------------
int TModuleDev::GetID()
{
  return mID;
}
//----------------------------------------------------------------------
std::string TModuleDev::GetName()
{
  return mName;
}
//----------------------------------------------------------------------
void TModuleDev::SetID( int id )
{
  mID = id;
}
//----------------------------------------------------------------------
void TModuleDev::SetName( const std::string& name )
{
  mName = name;
}
//----------------------------------------------------------------------
void TModuleDev::InputFromSynchroPoint()
{
  while ( true )
  {
    int id_sender = 0;
    IContainer* pCInput = nullptr;
    pCInput = GetEvent( id_sender );
    if ( pCInput == nullptr )
      break;
    Input( id_sender, pCInput->GetPtr(), pCInput->GetSize() );
  }
}
//---------------------------------------------------------------------------------
