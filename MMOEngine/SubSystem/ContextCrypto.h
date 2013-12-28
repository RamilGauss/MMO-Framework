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
  TCryptoAES_Impl mAES;

public:
	TContextCrypto();
	~TContextCrypto();

  TCryptoRSA_Impl* GetRSA();
  TCryptoAES_Impl* GetAES();

protected:
};


#endif
