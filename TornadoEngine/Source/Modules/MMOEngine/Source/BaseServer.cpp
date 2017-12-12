/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BaseServer.h"
#include "ManagerSession.h"
#include "CryptMITM.h"

using namespace nsMMOEngine;


TBaseServer::TBaseServer()
{

}
//-------------------------------------------------------------------------
TBaseServer::~TBaseServer()
{

}
//-------------------------------------------------------------------------
bool TBaseServer::IsSessionSecurity(unsigned int id_session, void* crypt, int size_crypt, 
                                    void* pLogin, int sizeLogin, void* pPassword, int sizePassword)
{
  TContainer cRSA;
  // получить по сессии RSA от транспорта
  if( mManagerSession->GetRSAPublicKey(id_session, cRSA)==false )
    return false;

  TCryptMITM cryptMITM;
  TContainer cMITM;
  if( cryptMITM.Calc(cRSA.GetPtr(), cRSA.GetSize(),
    pLogin, sizeLogin, pPassword, sizePassword, cMITM)==false )
    return false;
  // сравнить по размеру
  if(size_crypt!=cMITM.GetSize())
    return false;
  // сравнить по содержимому
  if(memcmp(crypt, cMITM.GetPtr(), size_crypt)!=0)
    return false;

  return true;
}
//-------------------------------------------------------------------------
//###
void TBaseServer::DisconnectByKeyClient(unsigned int id_client)
{
  
}
//-------------------------------------------------------------------------
//###
