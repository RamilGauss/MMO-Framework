/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CryptoRSA_ImplH
#define CryptoRSA_ImplH

#include "TypeDef.h"
#include "Container.h"

class SHARE_EI TCryptoRSA_Impl
{

  void* mRSAKey;

  int mMaxSizePartBeforeCrypt;
  int mMaxSizePartAfterCrypt;

  TContainer mContainerPrivateKey;
  TContainer mContainerPublicKey;

public:
  TCryptoRSA_Impl();
  ~TCryptoRSA_Impl();
  
  bool GenerateKey(int bits = 2048);

  bool Encrypt( void* pIn, int sizeIn, TContainer& c_out);
  bool Decrypt(void* pIn, int sizeIn, TContainer& c_out);

  bool GetPublicKey(TContainer& c_out);
  bool SetPublicKey(void* pKey, int sizeKey);

  bool GetPrivateKey(TContainer& c_out);

  bool SetupAllKeys(void* pPrivateKey, int sizePrivateKey, 
                    void* pPublicKey,  int sizePublicKey);
private:
  void MakeContainerForPrivateKey();
  void MakeContainerForPublicKey();
};


#endif

