/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef CryptoAES_ImplH
#define CryptoAES_ImplH

#include "TypeDef.h"
#include "Container.h"
#include "ContainerPtr.h"

class SHARE_EI TCryptoAES_Impl
{
  TContainer mKey;
  
  unsigned char iv[32]; // вектор инициализации 

  void* mCipher;
  void* mContext;

public:
  TCryptoAES_Impl();
  ~TCryptoAES_Impl();
  
  typedef enum
  {
    e128 = 128,
    e192 = 192,
    e256 = 256,
  }eCountBits;

  bool GenerateKey( eCountBits c = e256 );

  bool Encrypt( void* pIn, int sizeIn, TContainer& c_out);
  bool Decrypt(void* pIn, int sizeIn,  TContainer& c_out);
  bool Decrypt(void* pIn, int sizeIn,  TContainerPtr& c_out);

  bool GetPublicKey(TContainer& c_out);
  void SetPublicKey(void* pKey, int sizeKey);

};


#endif

