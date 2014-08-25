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
                                      void* login_password, int size_login_password)
{
  TContainer cRSA;
  // получить по сессии RSA от транспорта
  if(mManagerSession->GetRSAPublicKey(id_session, cRSA)==false)
    return false;

  TCryptMITM cryptMITM;
  TContainer cEncryptRSA_bySHA1_LP;
  if(cryptMITM.Calc(cRSA.GetPtr(), cRSA.GetSize(),
    login_password, size_login_password,
    cEncryptRSA_bySHA1_LP)==false)
    return false;
  // сравнить по размеру
  if(size_crypt!=cEncryptRSA_bySHA1_LP.GetSize())
    return false;
  // сравнить по содержимому
  if(memcmp(crypt, cEncryptRSA_bySHA1_LP.GetPtr(), size_crypt)!=0)
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
