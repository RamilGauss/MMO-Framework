/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/CryptoRSA_Impl.h"

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/evp.h>

#include <algorithm>
#include "Base/Common/BL_Debug.h"
#include "Base/Common/Mutex.h"

namespace nsCryptoRSA_Impl
{
#define RSA_KEY ((RSA*)mRSAKey)

    // на случай когда в одном процессе созданы несколько верхних соединений
    // то что бы не создавать много разных RSA ключей (тратиться много времени, а смысла в этом нет,
    // потому что процесс все равно один, соответственно безопасность не нарушается).
    static RSA* g_RSAKey = NULL;
    static int  g_CountGenerateKey = 0;
    static TMutex  g_MutexRSAKey;
    static int  g_BitsRSA = 2048;
    void lockRSA() { g_MutexRSAKey.lock(); }
    void unlockRSA() { g_MutexRSAKey.unlock(); }
}

using namespace nsCryptoRSA_Impl;

TCryptoRSA_Impl::TCryptoRSA_Impl()
{
    mRSAKey = NULL;
    mMaxSizePartAfterCrypt = 0;
    mMaxSizePartBeforeCrypt = 0;
}
//----------------------------------------------------------------------------------
TCryptoRSA_Impl::~TCryptoRSA_Impl()
{
    lockRSA();
    if ( mRSAKey == g_RSAKey ) {
        BL_ASSERT(g_CountGenerateKey);
        if ( (g_RSAKey == NULL && g_CountGenerateKey) ||
            (g_RSAKey && g_CountGenerateKey == 0) ) {
            BL_FIX_BUG();
        }
        if ( g_CountGenerateKey == 1 ) {
            RSA_free(g_RSAKey);
            g_RSAKey = NULL;
            mRSAKey = NULL;
        }
        g_CountGenerateKey--;

        unlockRSA();
        return;
    }
    unlockRSA();
    RSA_free(RSA_KEY);
    mRSAKey = NULL;
}
//----------------------------------------------------------------------------------
bool TCryptoRSA_Impl::GenerateKey_OnlyOneExample(int bits)
{
    lockRSA();
    // проверка
    if ( g_CountGenerateKey == 0 )
        g_BitsRSA = bits;
    else {
        BL_ASSERT(g_BitsRSA == bits);
    }
    // создавать новый или использовать старый?
    if ( g_CountGenerateKey == 0 )
        g_RSAKey = RSA_generate_key(bits, RSA_F4, NULL, NULL);
    mRSAKey = g_RSAKey;
    g_CountGenerateKey++;
    unlockRSA();
    if ( RSA_KEY == NULL )
        return false;

    mMaxSizePartAfterCrypt = RSA_size(RSA_KEY);
    mMaxSizePartBeforeCrypt = mMaxSizePartAfterCrypt - 11;

    MakeContainerForPrivateKey();
    MakeContainerForPublicKey();

    return true;
}
//----------------------------------------------------------------------------------
bool TCryptoRSA_Impl::GenerateKey(int bits)
{
    mRSAKey = RSA_generate_key(bits, RSA_F4, NULL, NULL);
    if ( RSA_KEY == NULL )
        return false;

    mMaxSizePartAfterCrypt = RSA_size(RSA_KEY);
    mMaxSizePartBeforeCrypt = mMaxSizePartAfterCrypt - 11;

    MakeContainerForPrivateKey();
    MakeContainerForPublicKey();

    return true;
}
//--------------------------------------------------------------------------------
bool TCryptoRSA_Impl::Encrypt(void* pVoidIn, int sizeIn, TContainer& c_out)
{
    BL_ASSERT(RSA_KEY);
    if ( sizeIn <= 0 ) {
        BL_FIX_BUG();
        return false;
    }

    int countPart = (sizeIn - 1) / mMaxSizePartBeforeCrypt + 1;
    int sizeOut = mMaxSizePartAfterCrypt * countPart;
    // выделить память под результат 
    c_out.SetDataByCount(NULL, sizeOut);
    char* pIn = (char*) pVoidIn;
    char* pOut = (char*) c_out.GetPtr();
    // шифровать частями 
    int sizePart = std::min(sizeIn, mMaxSizePartBeforeCrypt);
    for ( int i = 0; i < countPart; i++ ) {
        int res = RSA_public_encrypt(sizePart, (const unsigned char*) pIn,
            (unsigned char*) pOut, RSA_KEY, RSA_PKCS1_PADDING);
        if ( res == -1 )
            return false;

        sizeIn -= mMaxSizePartBeforeCrypt;
        pIn += mMaxSizePartBeforeCrypt;
        pOut += mMaxSizePartAfterCrypt;

        sizePart = std::min(sizeIn, mMaxSizePartBeforeCrypt);
    }
    return true;
}
//----------------------------------------------------------------------------------
bool TCryptoRSA_Impl::Decrypt(void* pVoidIn, int sizeIn, TContainer& c_out)
{
    BL_ASSERT(RSA_KEY);
    if ( (sizeIn < mMaxSizePartAfterCrypt) ||
        (sizeIn % mMaxSizePartAfterCrypt) )// размер должен делиться без остатка
    {
        BL_FIX_BUG();
        return false;
    }

    int countPart = sizeIn / mMaxSizePartAfterCrypt;
    // пока выделить по максимуму,
    //потому как будет рассчитываться в процессе дешифрования
    int sizeOut = countPart * mMaxSizePartBeforeCrypt;
    // выделить память под результат 
    TContainer c_Temp;
    c_Temp.SetDataByCount(NULL, sizeOut);
    char* pIn = (char*) pVoidIn;
    char* pOut = (char*) c_Temp.GetPtr();
    // шифровать частями 
    int sizeOut_Calc = 0;
    int sizePart = mMaxSizePartAfterCrypt;// размер частей всегда один и тот же
    for ( int i = 0; i < countPart; i++ ) {
        int res = RSA_private_decrypt(sizePart, (const unsigned char*) pIn,
            (unsigned char*) pOut, RSA_KEY, RSA_PKCS1_PADDING);
        if ( res == -1 )
            return false;
        sizeOut_Calc += res;

        pIn += mMaxSizePartAfterCrypt;
        pOut += res;
    }
    if ( sizeOut_Calc > c_Temp.GetSize() ) {
        BL_FIX_BUG();
        return false;
    }
    c_out.SetDataByCount((char*) c_Temp.GetPtr(), sizeOut_Calc);
    return true;
}
//----------------------------------------------------------------------------------
bool TCryptoRSA_Impl::GetPublicKey(TContainer& c_out)
{
    if ( RSA_KEY == NULL )
        return false;

    c_out.SetDataByCount((char*) mContainerPublicKey.GetPtr(), mContainerPublicKey.GetSize());
    return true;
}
//----------------------------------------------------------------------------------
bool TCryptoRSA_Impl::SetPublicKey(void* pKey, int sizeKey)
{
    BIO* pBIO = BIO_new(BIO_s_mem());
    int resBIO_write = BIO_write(pBIO, (char*) pKey, sizeKey);

    if ( resBIO_write == -1 ) {
        BIO_free(pBIO);
        return false;
    }

    RSA_free(RSA_KEY);
    mRSAKey = RSA_new();
    if ( mRSAKey == NULL ) {
        BIO_free(pBIO);
        return false;
    }

    RSA* pRes = PEM_read_bio_RSAPublicKey(pBIO, (RSA**) &mRSAKey, NULL, NULL);
    BIO_free(pBIO);

    if ( pRes == NULL )
        return false;

    mMaxSizePartAfterCrypt = RSA_size(RSA_KEY);
    mMaxSizePartBeforeCrypt = mMaxSizePartAfterCrypt - 11;

    mContainerPublicKey.SetData((char*) pKey, sizeKey);

    return true;
}
//----------------------------------------------------------------------------------
void TCryptoRSA_Impl::MakeContainerForPublicKey()
{
    BIO* pBIO = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPublicKey(pBIO, RSA_KEY);

    int sizeBIO = BIO_pending(pBIO);
    mContainerPublicKey.SetDataByCount(NULL, sizeBIO + 1);
    char* pMemContainer = (char*) mContainerPublicKey.GetPtr();
    BIO_read(pBIO, pMemContainer, sizeBIO);
    BIO_free(pBIO);
    pMemContainer[sizeBIO] = '\0';
}
//----------------------------------------------------------------------------------
void TCryptoRSA_Impl::MakeContainerForPrivateKey()
{
    BIO* pBIO = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPrivateKey(pBIO, RSA_KEY, NULL, NULL, 0, NULL, NULL);

    int sizeBIO = BIO_pending(pBIO);
    mContainerPrivateKey.SetDataByCount(NULL, sizeBIO + 1);
    char* pMemContainer = (char*) mContainerPrivateKey.GetPtr();
    BIO_read(pBIO, pMemContainer, sizeBIO);
    BIO_free(pBIO);
    pMemContainer[sizeBIO] = '\0';
}
//----------------------------------------------------------------------------------
bool TCryptoRSA_Impl::GetPrivateKey(TContainer& c_out)
{
    if ( RSA_KEY == NULL )
        return false;

    c_out.SetDataByCount((char*) mContainerPrivateKey.GetPtr(), mContainerPrivateKey.GetSize());
    return true;
}
//----------------------------------------------------------------------------------
bool TCryptoRSA_Impl::SetupAllKeys(void* pPrivateKey, int sizePrivateKey,
    void* pPublicKey, int sizePublicKey)
{
    // инициализация BIO приватного ключа
    BIO* pPrivateBIO = BIO_new(BIO_s_mem());
    int resPrivateBIO_write = BIO_write(pPrivateBIO, (char*) pPrivateKey, sizePrivateKey);
    // инициализация BIO публичного ключа
    BIO* pPublicBIO = BIO_new(BIO_s_mem());
    int resPublicBIO_write = BIO_write(pPublicBIO, (char*) pPublicKey, sizePublicKey);
    // проверка результата записи в BIO
    if ( resPrivateBIO_write == -1 || resPublicBIO_write == -1 ) {
        BIO_free(pPrivateBIO);
        BIO_free(pPublicBIO);
        return false;
    }
    //============================================
    // создать объект ключа заново
    RSA_free(RSA_KEY);
    mRSAKey = RSA_new();
    if ( mRSAKey == NULL ) {
        BIO_free(pPrivateBIO);
        BIO_free(pPublicBIO);
        return false;
    }
    //============================================
    RSA* pPrivateRes = NULL,
        * pPublicRes = NULL;
    // запись в RSA структуру из BIO
    pPrivateRes = PEM_read_bio_RSAPrivateKey(pPrivateBIO, (RSA**) &mRSAKey, NULL, NULL);
    if ( pPrivateRes )
        pPublicRes = PEM_read_bio_RSAPublicKey(pPublicBIO, (RSA**) &mRSAKey, NULL, NULL);
    // освободить BIO
    BIO_free(pPrivateBIO);
    BIO_free(pPublicBIO);
    // проверка результата
    if ( pPrivateRes == NULL || pPublicRes == NULL )
        return false;

    mMaxSizePartAfterCrypt = RSA_size(RSA_KEY);
    mMaxSizePartBeforeCrypt = mMaxSizePartAfterCrypt - 11;

    return true;
}
//----------------------------------------------------------------------------------
