/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/CryptoAES_Impl.h"

#include <openssl/pem.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <openssl/rand.h>
#include "Base/Common/BL_Debug.h"
#include "openssl/ossl_typ.h"

namespace nsCryptoAES_Impl
{
#define CIPHER  ((const EVP_CIPHER*)mCipher)
#define CONTEXT ((EVP_CIPHER_CTX*)mContext)
}

using namespace nsCryptoAES_Impl;

TCryptoAES_Impl::TCryptoAES_Impl()
{
    mContext = EVP_CIPHER_CTX_new();

    memset(&iv[0], 0, sizeof(iv));
}
//--------------------------------------------------------------------------------
TCryptoAES_Impl::~TCryptoAES_Impl()
{
    EVP_CIPHER_CTX_cleanup(CONTEXT);

    EVP_CIPHER_CTX_free(CONTEXT);
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::GenerateKey(eCountBits c)
{
    int sizeKey = c / 8;// на 8 бит
    mKey.SetDataByCount(nullptr, sizeKey);
    int res = RAND_bytes((unsigned char*)mKey.GetPtr(), mKey.GetSize());

    if (res == 0) {
        return false;
    }

    // Выбираем алгоритм шифрования
    switch (c) {
    case e128:
        mCipher = (void*)EVP_aes_128_ctr();
        break;
    case e192:
        mCipher = (void*)EVP_aes_192_ctr();
        break;
    case e256:
        mCipher = (void*)EVP_aes_256_ctr();
        break;
    }

    InitContext();
    return true;
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::InnerEncrypt(void* pIn, int sizeIn, void* pOut)
{
    int res = EVP_EncryptInit_ex(CONTEXT, CIPHER, nullptr, (const unsigned char*)mKey.GetPtr(), iv);
    if (res != 1) {
        return false;
    }
    int sizeOut;
    // Шифруем данные
    res = EVP_EncryptUpdate(CONTEXT, (unsigned char*)pOut, &sizeOut, (const unsigned char*)pIn, sizeIn);
    if (res != 1) {
        return false;
    }
    res = EVP_EncryptFinal_ex(CONTEXT, (unsigned char*)pOut + sizeOut, &sizeOut);
    if (res != 1) {
        return false;
    }
    return true;
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::Encrypt(void* pIn, int sizeIn, TContainerRise& c_out)
{
    c_out.Alloc(sizeIn);
    return InnerEncrypt(pIn, sizeIn, c_out.GetPtr());
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::Encrypt(void* pIn, int sizeIn, TContainer& c_out)
{
    c_out.SetDataByCount(nullptr, sizeIn);
    return InnerEncrypt(pIn, sizeIn, c_out.GetPtr());
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::InnerDecrypt(void* pIn, int sizeIn, void* pOut)
{
    auto res = EVP_DecryptInit_ex(CONTEXT, CIPHER, nullptr, (const unsigned char*)mKey.GetPtr(), iv);
    if (res != 1) {
        return false;
    }
    int sizeOut;
    // дешифруем данные
    res = EVP_DecryptUpdate(CONTEXT, (unsigned char*)pOut, &sizeOut, (const unsigned char*)pIn, sizeIn);
    if (res != 1) {
        return false;
    }
    // Завершаем процесс дешифрования
    res = EVP_DecryptFinal_ex(CONTEXT, (unsigned char*)pOut + sizeOut, &sizeOut);
    if (res != 1) {
        return false;
    }
    return true;
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::Decrypt(void* pIn, int sizeIn, TContainerRise& c_out)
{
    c_out.Alloc(sizeIn);
    return InnerDecrypt(pIn, sizeIn, c_out.GetPtr());
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::Decrypt(void* pIn, int sizeIn, TContainer& c_out)
{
    c_out.SetDataByCount(nullptr, sizeIn);
    return InnerDecrypt(pIn, sizeIn, c_out.GetPtr());
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::Decrypt(void* pIn, int sizeIn, TContainerPtr& c_out)
{
    return InnerDecrypt(pIn, sizeIn, c_out.GetPtr());
}
//--------------------------------------------------------------------------------
bool TCryptoAES_Impl::GetKey(TContainerRise& c_out)
{
    if (mKey.GetSize() == 0) {
        return false;
    }

    c_out.Clear();
    c_out.Append(mKey.GetSize(), (char*)mKey.GetPtr());
    return true;
}
//--------------------------------------------------------------------------------
void TCryptoAES_Impl::SetKey(void* pKey, int sizeKey)
{
    mKey.SetDataByCount((char*)pKey, sizeKey);

    int sizeCipher = sizeKey * 8;// 8 бит
    // Выбираем алгоритм шифрования
    switch (sizeCipher) {
    case e128:
        mCipher = (void*)EVP_aes_128_ctr();
        break;
    case e192:
        mCipher = (void*)EVP_aes_192_ctr();
        break;
    case e256:
        mCipher = (void*)EVP_aes_256_ctr();
        break;
    default:BL_FIX_BUG();
    }

    InitContext();
}
//--------------------------------------------------------------------------------
void TCryptoAES_Impl::InitContext()
{
    // Обнуляем структуру контекста
    EVP_CIPHER_CTX_init(CONTEXT);
}
//--------------------------------------------------------------------------------
