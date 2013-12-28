/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerContextCrypto.h"

#include <boost/foreach.hpp>

#include "ContextCrypto.h"
#include "BL_Debug.h"

TManagerContextCrypto::TManagerContextCrypto()
{
  mRSA_ForUpConnection.GenerateKey();
}
//-----------------------------------------------------------------
TManagerContextCrypto::~TManagerContextCrypto()
{
  Done();
}
//-----------------------------------------------------------------
void TManagerContextCrypto::SendRSA_PublicKey(TIP_Port& ip_port, TContainer& c_public_key)
{
  if(Get(ip_port))
  {
    BL_FIX_BUG();
    return;
  }
  TContextCrypto* pCtx = new TContextCrypto;
  Add(ip_port, pCtx);
  
  // полностью проинициализировать ключи
  TContainer c_private_key;
  bool resPrivate = mRSA_ForUpConnection.GetPrivateKey(c_private_key);
  bool resPublic  = mRSA_ForUpConnection.GetPublicKey(c_public_key);
  BL_ASSERT(resPrivate && resPublic);

  pCtx->GetRSA()->SetupAllKeys((char*)c_private_key.GetPtr(), c_private_key.GetSize(),
                               (char*)c_public_key.GetPtr(),  c_public_key.GetSize());
}
//-----------------------------------------------------------------
bool TManagerContextCrypto::RecvRSA_PublicKey(TIP_Port& ip_port, void* pKey, int sizeKey)
{
  if(Get(ip_port))
  {
    BL_FIX_BUG();
    return false;
  }
  TContextCrypto* pCtx = new TContextCrypto;
  Add(ip_port, pCtx);

  return pCtx->GetRSA()->SetPublicKey(pKey, sizeKey);
}
//-----------------------------------------------------------------
void TManagerContextCrypto::SendAES_Key(TIP_Port& ip_port, TContainer& c_encrypt_key)
{
  TContextCrypto* pCtx = Get(ip_port);
  if(pCtx==NULL)
  {
    BL_FIX_BUG();
    return;
  }
  TContainer c_key;

  pCtx->GetAES()->GenerateKey();
  pCtx->GetAES()->GetPublicKey(c_key);

  Encrypt(pCtx->GetRSA(), c_key, c_encrypt_key);
}
//-----------------------------------------------------------------
bool TManagerContextCrypto::RecvAES_Key(TIP_Port& ip_port, void* pKey, int sizeKey)
{
  TContextCrypto* pCtx = Get(ip_port);
  if(pCtx==NULL)
  {
    BL_FIX_BUG();
    return false;
  }
  TContainer c_decrypt_key;
  if(Decrypt(pCtx->GetRSA(), pKey, sizeKey, c_decrypt_key)==false)
    return false;

  pCtx->GetAES()->SetPublicKey(c_decrypt_key.GetPtr(), c_decrypt_key.GetSize());
  return true;
}
//-----------------------------------------------------------------
void TManagerContextCrypto::Send(TIP_Port& ip_port, TBreakPacket& bp, TContainer& c_encrypt)
{
  TContextCrypto* pCtx = Get(ip_port);
  if(pCtx==NULL)
  {
    BL_FIX_BUG();
    return;
  }
  // добавить память под контрольную сумму
  char crc8;
  bp.PushFront(&crc8,sizeof(crc8));
  // собрать все
  bp.Collect();
  // отдать под контроль контейнеру
  TContainer c_original;
  c_original.Entrust((char*)bp.GetCollectPtr(), bp.GetSize());
  // освободить break packet от памяти
  bp.UnlinkCollect();
  bp.UnlinkPart();

  Encrypt(pCtx->GetAES(), c_original, c_encrypt);
}
//-----------------------------------------------------------------
bool TManagerContextCrypto::Recv(TIP_Port& ip_port, 
                                 void* pEncrypt, int sizeEncrypt, 
                                 TContainerPtr& c_decrypt)
{
  TContextCrypto* pCtx = Get(ip_port);
  if(pCtx==NULL)
  {
    //BL_FIX_BUG();
    return false;// ignore
  }

  return Decrypt(pCtx->GetAES(), pEncrypt, sizeEncrypt, c_decrypt);
}
//-----------------------------------------------------------------
void TManagerContextCrypto::Close(TIP_Port& ip_port)
{
  Remove(ip_port);
}
//-----------------------------------------------------------------
void TManagerContextCrypto::Done()
{
  BOOST_FOREACH( TMapIP_Ptr::value_type& it, mMapIP_TCP)
    delete it.second;

  mMapIP_TCP.clear();
}
//-----------------------------------------------------------------
TContextCrypto* TManagerContextCrypto::Get(TIP_Port& ip_port)
{
  TMapIP_PtrIt fit = mMapIP_TCP.find(ip_port);
  if(mMapIP_TCP.end()==fit)
    return NULL;

  return fit->second;
}
//-----------------------------------------------------------------
void TManagerContextCrypto::Add(TIP_Port& ip_port, TContextCrypto* pCtx)
{
  mMapIP_TCP.insert(TMapIP_Ptr::value_type(ip_port,pCtx));
}
//-----------------------------------------------------------------
void TManagerContextCrypto::Remove(TIP_Port& ip_port)
{
  delete Get(ip_port);
  mMapIP_TCP.erase(ip_port);
}
//-----------------------------------------------------------------
void TManagerContextCrypto::Encrypt(TCryptoRSA_Impl* pRSA, 
                                    TContainer& c_original, TContainer& c_encrypt)
{
  pRSA->Encrypt(c_original.GetPtr(), c_original.GetSize(), c_encrypt);
}
//-----------------------------------------------------------------
bool TManagerContextCrypto::Decrypt(TCryptoRSA_Impl* pRSA, 
                                    void* pEncrypt, int sizeEncrypt,  
                                    TContainer& c_decrypt)
{
  return pRSA->Decrypt(pEncrypt, sizeEncrypt, c_decrypt);
}
//-----------------------------------------------------------------
void TManagerContextCrypto::Encrypt(TCryptoAES_Impl* pAES, 
                                    TContainer& c_original, TContainer& c_encrypt)
{
  // c_original содержит данные и 1 байт под контрольную сумму,
  // c_original.size() - 1 - считаем CRC8 и помещаем в первый байт
  unsigned char crc8 = mCRC8.Calc((char*)c_original.GetPtr() + eSizeCRC, 
                                   c_original.GetSize()      - eSizeCRC);
  // помещаем результат в первый байт
  ((unsigned char*)c_original.GetPtr())[0] = crc8;

  pAES->Encrypt(c_original.GetPtr(), c_original.GetSize(), c_encrypt);
}
//-----------------------------------------------------------------
bool TManagerContextCrypto::Decrypt(TCryptoAES_Impl* pAES, 
                                    void*  pEncrypt, int  sizeEncrypt,  
                                    TContainerPtr& c_decrypt_ptr)
{
  // размер шифрования равен размеру дешифрования
  // попытаться выделить память (расширит если будет мало)
  mCRise.Alloc(sizeEncrypt);
  // контейнер запомнит участок памяти
  c_decrypt_ptr.SetData(mCRise.GetPtr(), mCRise.GetSize());

  // дешифровать и поместить результат в область памяти
  bool res = pAES->Decrypt(pEncrypt, sizeEncrypt, c_decrypt_ptr);
  if(res==false)
    return false;

  // c_decrypt содержит данные и 1 байт под контрольную сумму,
  // c_decrypt.size() - 1 - считаем CRC8 и сравниваем с первым байтом
  unsigned char realy_crc8 = ((unsigned char*)c_decrypt_ptr.GetPtr())[0];
  c_decrypt_ptr.SetData((char*)c_decrypt_ptr.GetPtr() + eSizeCRC,
                        c_decrypt_ptr.GetSize()       - eSizeCRC);

  unsigned char calc_crc8  = mCRC8.Calc((char*)c_decrypt_ptr.GetPtr(), c_decrypt_ptr.GetSize());
  if(calc_crc8!=realy_crc8)
    return false;

  return true;
}
//-----------------------------------------------------------------
