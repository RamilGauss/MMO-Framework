/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ContextCryptoH
#define ContextCryptoH

#include "CryptoRSA_Impl.h"
#include "CryptoAES_Impl.h"

class TContextCrypto
{
  TCryptoRSA_Impl mRSA;
  //TCryptoAES_Impl mAES;

  TCryptoAES_Impl mSendAES;
  TCryptoAES_Impl mRecvAES;

public:
  TContextCrypto();
  ~TContextCrypto();

  TCryptoRSA_Impl* GetRSA();
  TCryptoAES_Impl* GetSendAES();
  TCryptoAES_Impl* GetRecvAES();

  void SetPublicKey( void* key, int size );
protected:
};


#endif
