/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerContextCryptoH
#define ManagerContextCryptoH

#include <map>

#include "ShareMisc.h"
#include "CRC8.h"
#include "Container.h"
#include "BreakPacket.h"
#include "ContainerRise.h"
#include "CryptoRSA_Impl.h"

class TContextCrypto;
class TCryptoRSA_Impl;
class TCryptoAES_Impl;

class TManagerContextCrypto
{
  typedef std::map<TIP_Port,TContextCrypto*> TMapIP_Ptr;
  typedef TMapIP_Ptr::iterator TMapIP_PtrIt;
  
  TMapIP_Ptr mMapIP_TCP;

  TCRC8 mCRC8;

  enum
  {
    eSizeCRC = 1,
  };

  // под AES дешифровку, что бы каждый раз не выделять память
  TContainerRise mCRise;


  // процесс создания ключа скачет от 100 мс до 7-8 секунд случайным образом
  // опасны эти максимальные значения. Поэтому можно на весь менеджер создать
  // всего один ключ и пользоваться им, например, для Клиента,
  // который сначала использует его для Мастера, потом для Slave.
  // Т.о. можно будет экономить время. К тому же таймаут Мастера очень требователен (5000 мс).
  // Более чем одно соединение наверх запрещено (Идеология).


  TCryptoRSA_Impl mRSA_ForUpConnection;

public:
	TManagerContextCrypto();
	~TManagerContextCrypto();
  
  void SendRSA_PublicKey(TIP_Port& ip_port, TContainer& c_key);
  bool RecvRSA_PublicKey(TIP_Port& ip_port, void* pKey, int sizeKey);
  
  void SendAES_Key(TIP_Port& ip_port, TContainer& c_encrypt_key);
  bool RecvAES_Key(TIP_Port& ip_port, void* pKey, int sizeKey);

  void Send(TIP_Port& ip_port, TBreakPacket& bp, TContainer& c_encrypt);
  bool Recv(TIP_Port& ip_port, 
            void* pEncrypt, int sizeEncrypt,
            TContainerPtr& c_decrypt);

  void Close(TIP_Port& ip_port);

protected:
  TContextCrypto* Get(TIP_Port& ip_port);
  void Add(TIP_Port& ip_port, TContextCrypto* pCtx);
  void Remove(TIP_Port& ip_port);

  void Done();
protected:
  void Encrypt(TCryptoRSA_Impl* pRSA, TContainer& c_original, TContainer& c_encrypt);
  bool Decrypt(TCryptoRSA_Impl* pRSA, void* pEncrypt, int sizeEncrypt,  TContainer& c_decrypt);
  
  void Encrypt(TCryptoAES_Impl* pAES, TContainer& c_original, TContainer& c_encrypt);
  bool Decrypt(TCryptoAES_Impl* pAES, 
               void* pEncrypt, int sizeEncrypt,  
               TContainerPtr& c_decrypt);
};


#endif
