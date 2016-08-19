/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "CryptoAES_Impl.h"

#include <openssl/pem.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <openssl/rand.h>
#include "BL_Debug.h"

namespace nsCryptoAES_Impl
{
  #define CIPHER  ((const EVP_CIPHER*)mCipher)
  #define CONTEXT ((EVP_CIPHER_CTX*)mContext)
}

using namespace nsCryptoAES_Impl;

TCryptoAES_Impl::TCryptoAES_Impl()
{
  mContext = (EVP_CIPHER_CTX*)new EVP_CIPHER_CTX();

	memset( &iv[0], 0, sizeof(iv));
}
//--------------------------------------------------------------------------------
TCryptoAES_Impl::~TCryptoAES_Impl()
{
	EVP_CIPHER_CTX_cleanup(CONTEXT);

  delete CONTEXT;
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::GenerateKey( eCountBits c )
{
  int sizeKey = c / 8;// на 8 бит
  mKey.SetDataByCount(NULL, sizeKey);
  int res = RAND_bytes((unsigned char*)mKey.GetPtr(), mKey.GetSize());

  if(res==0)
    return false;

  // Выбираем алгоритм шифрования
  switch(c)
  {
    case e128:
      mCipher = (void*)EVP_aes_128_cfb();
      break;
    case e192:
      mCipher = (void*)EVP_aes_192_cfb();
      break;
    case e256:
      mCipher = (void*)EVP_aes_256_cfb();
      break;
  }
  return true;
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::Encrypt( void* pIn, int sizeIn, TContainer& c_out)
{
	// Обнуляем структуру контекста
	EVP_CIPHER_CTX_init(CONTEXT);
	// Инициализируем контекст алгоритма
	int res = EVP_EncryptInit_ex(CONTEXT, CIPHER, NULL, (const unsigned char*)mKey.GetPtr(), iv);
	if(res==-1)
		return false;

  c_out.SetDataByCount(NULL, sizeIn);

	int sizeOut;
  // Шифруем данные
  if(!EVP_EncryptUpdate(CONTEXT, (unsigned char*)c_out.GetPtr(), &sizeOut, (const unsigned char *)pIn, sizeIn))
		return false;
  if(!EVP_EncryptFinal_ex(CONTEXT, (unsigned char*)c_out.GetPtr() + sizeOut, &sizeOut))
		return false;

	EVP_CIPHER_CTX_cleanup(CONTEXT);
  return true;
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::Decrypt(void* pIn, int sizeIn, TContainer& c_out)
{
	// Обнуляем структуру контекста
	EVP_CIPHER_CTX_init(CONTEXT);
	// Инициализируем контекст алгоритма
	int res = EVP_DecryptInit_ex(CONTEXT, CIPHER, NULL, (const unsigned char*)mKey.GetPtr(), iv);
	if(res==-1)
		return false;

	c_out.SetDataByCount(NULL, sizeIn);
	
	int sizeOut;
	// дешифруем данные
	if(!EVP_DecryptUpdate(CONTEXT, (unsigned char*)c_out.GetPtr(), &sizeOut, (const unsigned char *)pIn, sizeIn)) 
		return false;
	// Завершаем процесс дешифрования
	if(!EVP_DecryptFinal_ex(CONTEXT, (unsigned char*)c_out.GetPtr() + sizeOut, &sizeOut)) 
		return false; 

	EVP_CIPHER_CTX_cleanup(CONTEXT);
  return true;
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::Decrypt(void* pIn, int sizeIn, TContainerPtr& c_out)
{
  // Обнуляем структуру контекста
  EVP_CIPHER_CTX_init(CONTEXT);
  // Инициализируем контекст алгоритма
  int res = EVP_DecryptInit_ex(CONTEXT, CIPHER, NULL, (const unsigned char*)mKey.GetPtr(), iv);
  if(res==-1)
    return false;

  int sizeOut;
  // дешифруем данные
  if(!EVP_DecryptUpdate(CONTEXT, (unsigned char*)c_out.GetPtr(), &sizeOut, (const unsigned char *)pIn, sizeIn)) 
    return false;
  // Завершаем процесс дешифрования
  if(!EVP_DecryptFinal_ex(CONTEXT, (unsigned char*)c_out.GetPtr() + sizeOut, &sizeOut)) 
    return false; 

	EVP_CIPHER_CTX_cleanup(CONTEXT);
  return true;
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::GetPublicKey(TContainer& c_out)
{
	if(mKey.GetSize()==0)
		return false;

	c_out.SetDataByCount((char*)mKey.GetPtr(), mKey.GetSize());
	return true;
}
//--------------------------------------------------------------------------------
void TCryptoAES_Impl::SetPublicKey(void* pKey, int sizeKey)
{
  mKey.SetDataByCount((char*)pKey, sizeKey);

	int sizeCipher = sizeKey*8;
	// Выбираем алгоритм шифрования
	switch(sizeCipher)
	{
		case e128:
			mCipher = (void*)EVP_aes_128_cfb();
			break;
		case e192:
			mCipher = (void*)EVP_aes_192_cfb();
			break;
		case e256:
			mCipher = (void*)EVP_aes_256_cfb();
			break;
		default:BL_FIX_BUG();
	}
}
//--------------------------------------------------------------------------------

