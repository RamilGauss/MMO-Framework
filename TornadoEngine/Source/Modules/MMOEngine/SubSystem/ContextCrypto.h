/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "CryptoAES_Impl.h"

class TContextCrypto
{
  TCryptoAES_Impl mSendAES;
  TCryptoAES_Impl mRecvAES;

public:
  TContextCrypto();
  ~TContextCrypto();

  TCryptoAES_Impl* GetSendAES();
  TCryptoAES_Impl* GetRecvAES();
protected:
};
