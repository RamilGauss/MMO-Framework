/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "ContainerTypes.h"
#include "ContainerRise.h"

class DllExport TCryptoAES_Impl
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

    bool GenerateKey(eCountBits c = e256);

    bool Encrypt(void* pIn, int sizeIn, TContainerRise& c_out);
    bool Encrypt(void* pIn, int sizeIn, TContainer& c_out);

    bool Decrypt(void* pIn, int sizeIn, TContainerRise& c_out);
    bool Decrypt(void* pIn, int sizeIn, TContainer& c_out);
    bool Decrypt(void* pIn, int sizeIn, TContainerPtr& c_out);

    bool GetKey(TContainerRise& c_out);
    void SetKey(void* pKey, int sizeKey);

protected:
    void InitContext();

    bool InnerEncrypt(void* pIn, int sizeIn, void* pOut);
    bool InnerDecrypt(void* pIn, int sizeIn, void* pOut);
};