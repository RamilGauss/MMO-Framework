/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ContextCrypto.h"


TContextCrypto::TContextCrypto()
{

}
//-------------------------------------------------------------------------
TContextCrypto::~TContextCrypto()
{

}
//-------------------------------------------------------------------------
TCryptoRSA_Impl* TContextCrypto::GetRSA()
{
  return &mRSA;
}
//-------------------------------------------------------------------------
TCryptoAES_Impl* TContextCrypto::GetSendAES()
{
  return &mSendAES;
}
//-------------------------------------------------------------------------
TCryptoAES_Impl* TContextCrypto::GetRecvAES()
{
  return &mRecvAES;
}
//-------------------------------------------------------------------------
void TContextCrypto::SetPublicKey(void* key, int size)
{
  mSendAES.SetPublicKey(key, size);
  mRecvAES.SetPublicKey(key, size);
}
//-------------------------------------------------------------------------
