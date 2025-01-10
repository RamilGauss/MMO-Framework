
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include <array>
#include <iostream>

#include "Base/Common/CryptoAES_Impl.h"

TEST(CryptoAES, Simple_Ok)
{
    TCryptoAES_Impl src;
    src.GenerateKey();
    TContainerRise key;
    src.GetKey(key);

    TContainer encrypted;

    std::string str = "1234567890";

    auto resEncrypt = src.Encrypt((void*)str.data(), str.length(), encrypted);

    TCryptoAES_Impl dst;
    dst.SetKey(key.GetPtr(), key.GetSize());

    TContainerRise decrypted;
    auto resDecrypt = dst.Decrypt(encrypted.GetPtr(), encrypted.GetSize(), decrypted);

    ASSERT_EQ(resDecrypt, true);

    auto decryptedStr = std::string(decrypted.GetPtr(), decrypted.GetSize());
    ASSERT_EQ(decryptedStr, str);
}