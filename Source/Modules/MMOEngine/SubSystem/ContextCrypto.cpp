/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
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
