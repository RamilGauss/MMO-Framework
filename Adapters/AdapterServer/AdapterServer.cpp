/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "AdapterServer.h"

AdapterServer::AdapterServer()
{
  //GetLogger()->Register(STR_NAME_Server);
}
//----------------------------------------------------------------
AdapterServer::~AdapterServer()
{

}
//----------------------------------------------------------------
PrototypeBaseModule* AdapterServer::NewExample()
{
  return new AdapterServer;
}
//----------------------------------------------------------------
void AdapterServer::DeleteExample(PrototypeBaseModule* ptr)
{
  delete ptr;
}
//----------------------------------------------------------------
int AdapterServer::GetVersionAdapter()
{
  return 1;
}
//----------------------------------------------------------------
bool AdapterServer::Work()
{
  return true;
}
//----------------------------------------------------------------
