/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CryptoContextManager.h"

#include "ContextCrypto.h"
#include "BL_Debug.h"

TCryptoContextManager::TCryptoContextManager()
{

}
//-----------------------------------------------------------------
TCryptoContextManager::~TCryptoContextManager()
{
  Done();
}
//-----------------------------------------------------------------
void TCryptoContextManager::SendAES_Key( TIP_Port& ip_port, TContainer& c_encrypt_key )
{
  TContextCrypto* pCtx = Get( ip_port );
  if( pCtx == NULL )
  {
    BL_FIX_BUG();
    return;
  }
  TContainerRise c_key;

  pCtx->GetSendAES()->GenerateKey();
  pCtx->GetSendAES()->GetKey( c_key );

  pCtx->GetRecvAES()->SetKey( c_key.GetPtr(), c_key.GetSize() );

  //Encrypt( pCtx->GetRSA(), c_key, c_encrypt_key );
}
//-----------------------------------------------------------------
bool TCryptoContextManager::RecvAES_Key( TIP_Port& ip_port, void* pKey, int sizeKey )
{
  TContextCrypto* pCtx = Get( ip_port );
  if( pCtx == NULL )
  {
    BL_FIX_BUG();
    return false;
  }
  //TContainer c_decrypt_key;
  //if( Decrypt( pCtx->GetRSA(), pKey, sizeKey, c_decrypt_key ) == false )
  //  return false;

  //pCtx->GetRecvAES()->SetKey( c_decrypt_key.GetPtr(), c_decrypt_key.GetSize() );
  //pCtx->SetKey( c_decrypt_key.GetPtr(), c_decrypt_key.GetSize() );
  return true;
}
//-----------------------------------------------------------------
void TCryptoContextManager::Send( TIP_Port& ip_port, TBreakPacket& bp, TContainer& c_encrypt )
{
  TContextCrypto* pCtx = Get( ip_port );
  if( pCtx == NULL )
  {
    BL_FIX_BUG();
    return;
  }
  // добавить память под контрольную сумму
  char crc8;
  bp.PushFront( &crc8, sizeof( crc8 ) );
  // собрать все
  TContainerRise c_original;
  bp.CopyInBuffer( c_original );

  Encrypt( pCtx->GetSendAES(), c_original, c_encrypt );
}
//-----------------------------------------------------------------
bool TCryptoContextManager::Recv( TIP_Port& ip_port,
  void* pEncrypt, int sizeEncrypt,
  TContainerPtr& c_decrypt )
{
  TContextCrypto* pCtx = Get( ip_port );
  if( pCtx == NULL )
  {
    //BL_FIX_BUG();
    return false;// ignore
  }

  return Decrypt( pCtx->GetRecvAES(), pEncrypt, sizeEncrypt, c_decrypt );
}
//-----------------------------------------------------------------
void TCryptoContextManager::Close( TIP_Port& ip_port )
{
  Remove( ip_port );
}
//-----------------------------------------------------------------
void TCryptoContextManager::Done()
{
  for( auto& it : mMapIP_TCP )
    delete it.second;

  mMapIP_TCP.clear();
}
//-----------------------------------------------------------------
TContextCrypto* TCryptoContextManager::Get( TIP_Port& ip_port )
{
  TMapIP_PtrIt fit = mMapIP_TCP.find( ip_port );
  if( mMapIP_TCP.end() == fit )
    return NULL;

  return fit->second;
}
//-----------------------------------------------------------------
void TCryptoContextManager::Add( TIP_Port& ip_port, TContextCrypto* pCtx )
{
  mMapIP_TCP.insert( TMapIP_Ptr::value_type( ip_port, pCtx ) );
}
//-----------------------------------------------------------------
void TCryptoContextManager::Remove( TIP_Port& ip_port )
{
  delete Get( ip_port );
  mMapIP_TCP.erase( ip_port );
}
//-----------------------------------------------------------------
void TCryptoContextManager::Encrypt( TCryptoAES_Impl* pAES,
  TContainerRise& c_original, TContainer& c_encrypt )
{
  // c_original содержит данные и 1 байт под контрольную сумму,
  // c_original.size() - 1 - считаем CRC8 и помещаем в первый байт
  unsigned char crc8;
  mCRC8.Calc( (char*) c_original.GetPtr() + eSizeCRC, c_original.GetSize() - eSizeCRC, crc8 );
  // помещаем результат в первый байт
  ((unsigned char*) c_original.GetPtr())[0] = crc8;

  pAES->Encrypt( c_original.GetPtr(), c_original.GetSize(), c_encrypt );
}
//-----------------------------------------------------------------
bool TCryptoContextManager::Decrypt( TCryptoAES_Impl* pAES,
  void*  pEncrypt, int  sizeEncrypt,
  TContainerPtr& c_decrypt_ptr )
{
  // размер шифрования равен размеру дешифрования
  // попытаться выделить память (расширит если будет мало)
  mCRise.Alloc( sizeEncrypt );
  // контейнер запомнит участок памяти
  c_decrypt_ptr.SetDataByCount( mCRise.GetPtr(), mCRise.GetSize() );

  // дешифровать и поместить результат в область памяти
  bool res = pAES->Decrypt( pEncrypt, sizeEncrypt, c_decrypt_ptr );
  if( res == false )
    return false;

  // c_decrypt содержит данные и 1 байт под контрольную сумму,
  // c_decrypt.size() - 1 - считаем CRC8 и сравниваем с первым байтом
  unsigned char realy_crc8 = ((unsigned char*) c_decrypt_ptr.GetPtr())[0];
  c_decrypt_ptr.SetDataByCount( (char*) c_decrypt_ptr.GetPtr() + eSizeCRC,
    c_decrypt_ptr.GetSize() - eSizeCRC );

  unsigned char calc_crc8;
  mCRC8.Calc( (char*) c_decrypt_ptr.GetPtr(), c_decrypt_ptr.GetSize(), calc_crc8 );
  if( calc_crc8 != realy_crc8 )
    return false;

  return true;
}
//-----------------------------------------------------------------
